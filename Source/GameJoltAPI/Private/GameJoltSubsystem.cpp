#include "GameJoltSubsystem.h"
// Copyright by Nick Lamprecht (2020-2022)

#include "GameJoltSubsystem.h"
#include "AsyncActions/Users/Login.h"
#include "AsyncActions/Users/AutoLogin.h"

void UGameJoltSubsystem::Setup(const int32 gameID, const FString privateKey, const FString server, const FString version)
{
    Logout();
    GameID = gameID;
    PrivateKey = privateKey;
    Server = server;
    Version = version;
}

void UGameJoltSubsystem::Login(const FString Name, const FString Token)
{
    bLoggedIn = true;
    UserName = Name;
    UserToken = Token;
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
