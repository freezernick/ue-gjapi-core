// Copyright by Nick Lamprecht (2020-2021)


#include "GameJolt.h"
#include "Misc/SecureHash.h"
#include "AsyncActions/Users/AutoLogin.h"
#include "AsyncActions/Users/Login.h"
#include "GameJoltAPI.h"
#include "Misc/Paths.h"

UGameJolt& UGameJolt::Get()
{
#if ENGINE_MINOR_VERSION < 20
    if(!UGameJolt::Instance)
        UGameJolt::Instance = NewObject<UGameJolt>();
    return *UGameJolt::Instance;
#else
    return *FModuleManager::GetModulePtr<FGameJoltAPIModule>("GameJoltAPI")->GJAPI;
#endif
}

#if ENGINE_MINOR_VERSION < 20

UGameJolt* UGameJolt::Instance = nullptr;

// Thanks to Ben for some inspiration 
// https://benui.ca/unreal/cpp-style-singletons/

#endif

UGameJolt::UGameJolt(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
#if ENGINE_MINOR_VERSION < 20
	// Don't set up Singleton instance in CDO constructor
	// or other Unreal-style constructors
	if ( !HasAnyFlags( RF_ClassDefaultObject
		| RF_NeedLoad
		| RF_NeedPostLoad
		| RF_NeedPostLoadSubobjects ) )
	{
		ensureMsgf( UGameJolt::Instance == nullptr, TEXT( "Uh-oh two singletons!" ) );
		UGameJolt::Instance = this;
	}
#endif
}

#if ENGINE_MINOR_VERSION < 20

void UGameJolt::BeginDestroy()
{
	if (UGameJolt::Instance != nullptr)
        UGameJolt::Instance = nullptr;
    Super::BeginDestroy();
}

#endif

void UGameJolt::Initialize(const int32 Game_ID, const FString Private_Key, const FString Server, const FString Version)
{
    UGameJolt& API = UGameJolt::Get();
    API.Logout();
    API.GameID = Game_ID;
    API.PrivateKey = Private_Key;
    API.Server = Server;
    API.Version = Version;
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
