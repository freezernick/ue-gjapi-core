// Copyright by Nick Lamprecht (2020-2023)

#pragma once

#include "CoreMinimal.h"

/* A filter used to fetch trophies */
UENUM(BlueprintType)
enum class EGJAchievedTrophies : uint8
{
    all UMETA(DisplayName = "All Trophies"),
    achieved UMETA(DisplayName = "User Achieved Trophies"),
    unachieved UMETA(DisplayName = "Unachieved Trophies")
};

/* Represents the state of a session. */
UENUM(BlueprintType)
enum class EGJSessionStatus : uint8
{
    active UMETA(DisplayName = "Active"),
    idle UMETA(DisplayName = "Idle")
};

/* Represents the scope of a data-store action */
UENUM(BlueprintType)
enum class EGJDataStore : uint8
{
    global UMETA(DisplayName = "Global"),
    user UMETA(DisplayName = "User")
};

/* Represents possible operations to perform with stored data */
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

/* A filter used to fetch high-scores */
UENUM(BlueprintType)
enum class EGJScoreFilter : uint8
{
    all UMETA(DisplayName = "All Scores"),
    guest UMETA(DisplayName = "Scores of a guest"),
    user UMETA(DisplayName = "Scores of the current user")
};

/* Represents the type of a user */
UENUM(BlueprintType)
enum class EGJUserType : uint8
{
    User,
    Developer,
    Moderator,
    Administrator
};

/* Represents the difficulty of a trophy */
UENUM(BlueprintType)
enum class EGJTrophyDifficulty : uint8
{
    Bronze,
    Silver,
    Gold,
    Platinum
};

UENUM(BlueprintType)
enum class EGJErrors : uint8
{
    None,
    UnknownError UMETA(DisplayName = "An unknown error on the plugin's side has occured."),
    UnknownError_Server UMETA(DisplayName = "An unknown error on GameJolt's side has occured."),
    GameIDUnset,
    GameIDInvalid,
    PrivateKeyUnset,
    ParametersInvalidOrUnset,
    ResponseInvalid,
    RequestFailed,
    CredentialsInvalid,
    RestrictedKey,
    KeyNotFound,
    OperationFailed,
    SignatureInvalid,
    InvalidTrophyID,
    TrophyNotAchieved,
    TrophyAlreadyAchieved,
    GuestsNotAllowed,
    NoSession,
    CredentialsNotFound
};