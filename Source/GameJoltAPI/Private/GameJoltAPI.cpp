// Copyright by Nick Lamprecht (2020-2021)

#include "GameJoltAPI.h"

DEFINE_LOG_CATEGORY(GameJoltAPI);

#define LOCTEXT_NAMESPACE "GameJoltAPI"

void FGameJoltAPIModule::StartupModule()
{
}

void FGameJoltAPIModule::ShutdownModule()
{
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FGameJoltAPIModule, GameJoltAPI)