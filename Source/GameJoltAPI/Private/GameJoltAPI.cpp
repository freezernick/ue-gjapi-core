// Copyright by Nick Lamprecht (2020-2021)

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