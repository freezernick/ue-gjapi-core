// Copyright by Free2Play-Entertainment (2020)

#include "GameJoltAPI.h"
#include "GameJolt.h"

void FGameJoltAPIModule::StartupModule()
{
    GJAPI = NewObject<UGameJolt>();
}

void FGameJoltAPIModule::ShutdownModule()
{
    GJAPI = nullptr;
}

IMPLEMENT_MODULE(FGameJoltAPIModule, GameJoltAPI)