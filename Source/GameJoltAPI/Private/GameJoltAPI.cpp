// Copyright by Nick Lamprecht (2020-2021)

#include "GameJoltAPI.h"
#include "GameJolt.h"

void FGameJoltAPIModule::StartupModule()
{
    GJAPI = NewObject<UGameJolt>();
    if(GJAPI)
    {
        UE_LOG(LogTemp, Error, TEXT("Test"));
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("Kein Test"));
    }
}

void FGameJoltAPIModule::ShutdownModule()
{
    GJAPI = nullptr;
}

IMPLEMENT_MODULE(FGameJoltAPIModule, GameJoltAPI)