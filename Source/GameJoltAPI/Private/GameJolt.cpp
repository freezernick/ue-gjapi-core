// Copyright by Nick Lamprecht (2020-2021)


#include "GameJolt.h"
#include "Misc/SecureHash.h"
#include "AsyncActions/Users/AutoLogin.h"
#include "AsyncActions/Users/Login.h"
#include "GameJoltAPI.h"
#include "Misc/Paths.h"
#include "Runtime/Engine/Public/EngineGlobals.h"

/* Prevents crashes within 'Get...' functions */
UWorld* UGameJolt::GetWorld() const
{
	return World;
}


UGameJolt& UGameJolt::Get(UObject* WorldContextObject)
{
#if ENGINE_MINOR_VERSION == 19
    UE_LOG(LogTemp, Error, TEXT("19!!!!!!"));
    FGameJoltAPIModule* Module = FModuleManager::GetModulePtr<FGameJoltAPIModule>("GameJoltAPI");
    if(Module->GJAPI->bInitialized)
        return *Module->GJAPI;
    Module->GJAPI = NewObject<UGameJolt>((UGameJolt*)GetTransientPackage(), UGameJolt::StaticClass());
    Module->GJAPI->World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject);
    Module->GJAPI->bInitialized = true;
    return *Module->GJAPI;
#else
    return *FModuleManager::GetModulePtr<FGameJoltAPIModule>("GameJoltAPI")->GJAPI;
#endif
}

void UGameJolt::Initialize(UObject* WorldContextObject, const int32 game_id, const FString private_key, const FString server, const FString version)
{
    UGameJolt& API = UGameJolt::Get(WorldContextObject);
    API.GameID = game_id;
    API.PrivateKey = private_key;
    API.Server = server;
    API.Version = version;
}

void UGameJolt::Login(const FString Name, const FString Token)
{
    bLoggedIn = true;
    UserName = Name;
    UserToken = Token;
}

void UGameJolt::Logout()
{
    UGameJolt& API = UGameJolt::Get();
    API.bLoggedIn = false;
    API.UserName = "";
    API.UserToken = "";
}

FString UGameJolt::CreateURL(const FString URL, bool AppendUserInfo)
{
    UGameJolt& GameJolt = UGameJolt::Get();
    FString BaseURL;
    if(GameJolt.Server == "")
        BaseURL = TEXT("https://api.gamejolt.com/api/game");
    else
        BaseURL = GameJolt.Server;
    if(GameJolt.Version == "")
        BaseURL += TEXT("/v1_2");
    else
        BaseURL = FPaths::Combine(BaseURL, GameJolt.Version);
    FPaths::NormalizeDirectoryName(BaseURL);
    BaseURL = FPaths::Combine(BaseURL, URL + "&game_id=" + FString::FromInt(GameJolt.GameID) + ((GameJolt.bLoggedIn && AppendUserInfo) ? "&username=" + GameJolt.UserName + "&user_token=" + GameJolt.UserToken : ""));
    return (BaseURL + "&signature=" + FMD5::HashAnsiString(*(BaseURL + GameJolt.PrivateKey)));
}