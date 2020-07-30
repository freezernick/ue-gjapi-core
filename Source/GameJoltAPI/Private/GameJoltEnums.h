// Copyright by Free2Play-Entertainment (2020)

#pragma once

#include "CoreMinimal.h"

UENUM(BlueprintType)
enum class EGJAchievedTrophies : uint8
{
    all UMETA(DisplayName = "All Trophies"),
    achieved UMETA(DisplayName = "User Achieved Trophies"),
    unachieved UMETA(DisplayName = "Unachieved Trophies")
};

UENUM(BlueprintType)
enum class EGJSessionStatus : uint8
{
    active UMETA(DisplayName = "Active"),
    idle UMETA(DisplayName = "Idle")
};

UENUM(BlueprintType)
enum class EGJDataStore : uint8
{
    Global,
    User
};

UENUM(BlueprintType)
enum class EGJDataOperation : uint8
{
    add UMETA(DisplayName = "Add"),
    substract UMETA(DisplayName = "Substract"),
    multiply UMETA(DisplayName = "Multiply"),
    divide UMETA(DisplayName = "Divide"),
    append UMETA(DisplayName = "Append"),
    prepend UMETA(DisplayName = "Prepend")
};

UENUM(BlueprintType)
enum class EGJScoreFilter : uint8
{
    all UMETA(DisplayName = "All Scores"),
    guest UMETA(DisplayName = "Scores of a guest"),
    user UMETA(DisplayName = "Scores of the current user")
};