// Copyright by Nick Lamprecht (2020-2023)

#include "GameJoltSubsystem.h"
#include "Kismet/GameplayStatics.h"
#include "AsyncActions/Users/Login.h"
#include "AsyncActions/Users/AutoLogin.h"
#include "GameJoltAPI.h"

void UGameJoltSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
    Super::Initialize(Collection);

    if (!UGameJoltSettings::Get())
    {
        UE_LOG(GameJoltAPI, Warning, TEXT("Could not automatically initialize Game Jolt API. Please initialize manually!"));
        return;
    }

    UGameJoltSettings* Settings = UGameJoltSettings::Get();
    GameID = Settings->GameID;
    PrivateKey = Settings->PrivateKey;
    Server = Settings->GetServer();
    Version = Settings->GetVersion();
}

void UGameJoltSubsystem::Setup(UObject* WCO, const int32 gameID, const FString privateKey, const FString server, const FString version)
{
    return UGameplayStatics::GetGameInstance(WCO)->GetSubsystem<UGameJoltSubsystem>()->Setup(
        gameID,
        privateKey,
        server,
        version
    );
}

void UGameJoltSubsystem::Setup(const int32 gameID, const FString privateKey, const FString server, const FString version)
{
    Logout();
    GameID = gameID;
    PrivateKey = privateKey;
    Server = server;
    Version = version;
}

FString UGameJoltSubsystem::GetUsername(UObject* WCO)
{
    return UGameplayStatics::GetGameInstance(WCO)->GetSubsystem<UGameJoltSubsystem>()->GetUsername();
}

FString UGameJoltSubsystem::GetUsername()
{
    return UserName;
}

FString UGameJoltSubsystem::GetPrivateKey(UObject* WCO)
{
    return UGameplayStatics::GetGameInstance(WCO)->GetSubsystem<UGameJoltSubsystem>()->GetPrivateKey();
}

FString UGameJoltSubsystem::GetPrivateKey()
{
    return PrivateKey;
}

int32 UGameJoltSubsystem::GetGameID(UObject* WCO)
{
    return UGameplayStatics::GetGameInstance(WCO)->GetSubsystem<UGameJoltSubsystem>()->GetGameID();
}

int32 UGameJoltSubsystem::GetGameID()
{
    return GameID;
}

bool UGameJoltSubsystem::IsLoggedIn(UObject* WCO)
{
    return UGameplayStatics::GetGameInstance(WCO)->GetSubsystem<UGameJoltSubsystem>()->IsLoggedIn();
}

bool UGameJoltSubsystem::IsLoggedIn()
{
    return bLoggedIn;
}

void UGameJoltSubsystem::Login(const FString Name, const FString Token)
{
    bLoggedIn = true;
    UserName = Name;
    UserToken = Token;
}

void UGameJoltSubsystem::Logout(UObject* WCO)
{
    return UGameplayStatics::GetGameInstance(WCO)->GetSubsystem<UGameJoltSubsystem>()->Logout();
}

void UGameJoltSubsystem::Logout()
{
    bLoggedIn = false;
    UserName = "";
    UserToken = "";
}

FString UGameJoltSubsystem::CreateURL(const FString URL, bool AppendUserInfo)
{
    FString BaseURL;
    if(Server == "")
        BaseURL = TEXT("https://api.gamejolt.com/api/game");
    else
        BaseURL = Server;
    if(Version == "")
        BaseURL += TEXT("/v1_2");
    else
        BaseURL = FPaths::Combine(BaseURL, Version);
    FPaths::NormalizeDirectoryName(BaseURL);
    BaseURL = FPaths::Combine(BaseURL, URL + "&game_id=" + FString::FromInt(GameID) + ((bLoggedIn && AppendUserInfo) ? "&username=" + UserName + "&user_token=" + UserToken : ""));
    return (BaseURL + "&signature=" + FMD5::HashAnsiString(*(BaseURL + PrivateKey)));
}
