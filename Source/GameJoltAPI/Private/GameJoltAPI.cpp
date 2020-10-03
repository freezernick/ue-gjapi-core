// Copyright by Free2Play-Entertainment (2020)

#include "GameJoltAPI.h"
#include "GameJolt.h"

void FGameJoltAPIModule::StartupModule()
{
    GameJoltAPI = NewObject<UGameJolt>();
}

void FGameJoltAPIModule::ShutdownModule()
{
}

IMPLEMENT_MODULE(FGameJoltAPIModule, GameJoltAPI)