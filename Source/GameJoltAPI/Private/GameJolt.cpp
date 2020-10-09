// Copyright by Free2Play-Entertainment (2020)


#include "GameJolt.h"
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
    UGameJolt* API = UGameJolt::Get();
    API->bLoggedIn = false;
    API->UserName = "";
    API->UserToken = "";
}

FString UGameJolt::CreateURL(const FString URL, bool AppendUserInfo)
{
    UGameJolt* GameJolt = UGameJolt::Get();
    FString BaseURL = "https://api.gamejolt.com/api/game/v1_2/" + URL + "&game_id=" + FString::FromInt(GameJolt->GameID) + ((GameJolt->bLoggedIn && AppendUserInfo) ? "&username=" + GameJolt->UserName + "&user_token=" + GameJolt->UserToken : "");
    return (BaseURL + "&signature=" + FMD5::HashAnsiString(*(BaseURL + GameJolt->PrivateKey)));
}