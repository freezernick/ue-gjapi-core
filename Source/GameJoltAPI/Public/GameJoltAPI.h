// Copyright by Nick Lamprecht (2020-2023)

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

class FGameJoltAPIModule : public IModuleInterface
{
public:
    FGameJoltAPIModule() {};

    /** IModuleInterface implementation */
    virtual void StartupModule() override;
    virtual void ShutdownModule() override;
};
