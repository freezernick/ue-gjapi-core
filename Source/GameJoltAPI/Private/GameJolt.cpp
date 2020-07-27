// Copyright by Free2Play-Entertainment (2020)


#include "GameJolt.h"
#include "Misc/Paths.h"
#include "Misc/SecureHash.h"

UGameJolt* UGameJolt::Initialize(const int32 game_id, const FString private_key)
{
    UGameJolt* GameJoltAPI = NewObject<UGameJolt>(UGameJolt::StaticClass());
    GameJoltAPI->GameID = game_id;
    GameJoltAPI->PrivateKey = private_key;
    return GameJoltAPI;
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

FString UGameJolt::CreateURL(const FString URL, const UGameJolt* GameJolt)
{
    FString BaseURL = FPaths::Combine((GameJolt->Server + GameJolt->Version), URL) + "&game_id=" + FString::FromInt(GameJolt->GameID) + (GameJolt->bLoggedIn ? "&username=" + GameJolt->UserName + "&user_token=" + GameJolt->UserToken : "");
    return (BaseURL + "&signature=" + FMD5::HashAnsiString(*(BaseURL + GameJolt->PrivateKey)));
}