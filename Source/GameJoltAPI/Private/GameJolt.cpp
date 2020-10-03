// Copyright by Free2Play-Entertainment (2020)


#include "GameJolt.h"
#include "Misc/Paths.h"
#include "Misc/SecureHash.h"

void UGameJolt::Initialize(const int32 game_id, const FString private_key)
{
    UGameJolt* API = UGameJolt::Get();
    API->GameID = game_id;
    API->PrivateKey = private_key;
}

void UGameJolt::Login(const FString Name, const FString Token)
{
    bLoggedIn = true;
    UserName = Name;
    UserToken = Token;
}

void UGameJolt::Logout()
{
    bLoggedIn = false;
    UserName = "";
    UserToken = "";
}

FString UGameJolt::CreateURL(const FString URL, bool AppendUserInfo)
{
    UGameJolt* GameJolt = UGameJolt::Get(); 
    FString BaseURL = FPaths::Combine(FString(GameJolt->Server + GameJolt->Version), URL) + "&game_id=" + FString::FromInt(GameJolt->GameID) + ((GameJolt->bLoggedIn && AppendUserInfo) ? "&username=" + GameJolt->UserName + "&user_token=" + GameJolt->UserToken : "");
    return (BaseURL + "&signature=" + FMD5::HashAnsiString(*(BaseURL + GameJolt->PrivateKey)));
}