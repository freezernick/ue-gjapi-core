// Copyright by Nick Lamprecht (2020-2021)

#include "GameJoltAPI.h"
#include "GameJolt.h"

void FGameJoltAPIModule::StartupModule()
{
#if ENGINE_MINOR_VERSION > 19
    GJAPI = NewObject<UGameJolt>();
#endif
}

void FGameJoltAPIModule::ShutdownModule()
{
    GJAPI = nullptr;
}

IMPLEMENT_MODULE(FGameJoltAPIModule, GameJoltAPI)