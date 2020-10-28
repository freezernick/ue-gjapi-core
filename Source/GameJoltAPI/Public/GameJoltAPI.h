// Copyright by Free2Play-Entertainment (2020)

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"


class FGameJoltAPIModule : public IModuleInterface
{
public:

    class UGameJolt* GJAPI;

public:

    /** IModuleInterface implementation */
    virtual void StartupModule() override;
    virtual void ShutdownModule() override;
};
