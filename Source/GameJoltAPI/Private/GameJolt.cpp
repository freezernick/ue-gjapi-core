// Copyright by Free2Play-Entertainment (2020)


#include "GameJolt.h"

UGameJolt* UGameJolt::Initialize(const int32 game_id, const FString private_key)
{
    UGameJolt* GameJoltAPI = NewObject<UGameJolt>(UGameJolt::StaticClass());
    GameJoltAPI->GameID = game_id;
    GameJoltAPI->PrivateKey = private_key;
    return GameJoltAPI;
}