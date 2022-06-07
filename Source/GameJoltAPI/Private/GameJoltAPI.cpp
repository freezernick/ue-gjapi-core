// Copyright by Nick Lamprecht (2020-2022)

#include "GameJoltAPI.h"
#include "GameJolt.h"
#include "UObject/UObjectBaseUtility.h"

void FGameJoltAPIModule::StartupModule()
{
    GJAPI = NewObject<UGameJolt>();
    GJAPI->AddToRoot();
}

void FGameJoltAPIModule::ShutdownModule()
{
    GJAPI = nullptr;
}

IMPLEMENT_MODULE(FGameJoltAPIModule, GameJoltAPI)