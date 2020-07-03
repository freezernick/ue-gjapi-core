#pragma once

#include "CoreMinimal.h"

UENUM(BlueprintType)
enum class EGJAchievedTrophies : uint8
{
	GJ_ACHIEVEDTROPHY_BLANK UMETA(DisplayName = "All Trophies"),
	GJ_ACHIEVEDTROPHY_USER UMETA(DisplayName = "User Achieved Trophies"),
	GJ_ACHIEVEDTROPHY_GAME UMETA(DisplayName = "Unachieved Trophies")
};

UENUM(BlueprintType)
enum class EGJSessionStatus : uint8
{
	Active,
	Idle
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