// Copyright by Nick Lamprecht (2020-2023)

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameJoltEnums.h"
#include "GameJolt.generated.h"

UCLASS(Blueprintable)
class GAMEJOLTAPI_API UGameJolt : public UObject
{
    GENERATED_BODY()

private:

    static class UGameJoltSubsystem* GetGameJolt(UObject* WCO);

public:

    /**
     * Sets required information for all API requests
     * @param Game_ID Required. Can be found in your game's dashboard
     * @param Private_Key Required. Can be found in your game's dashboard
     * @param Server Optional. Default is https://api.gamejolt.com/api/game/
     * @param Version Optional. Default is v1_2
     */
    UFUNCTION(BlueprintCallable, Category = "GameJoltAPI", meta = (DeprecatedFunction, DeprecationMessage="Use Setup of the GameJolt-Subsystem instead.", AdvancedDisplay="Server, Version", WorldContext = "WorldContextObject"))
    static void Initialize(UObject* WorldContextObject, const int32 Game_ID, const FString Private_Key, const FString Server = "", const FString Version = "");

    UFUNCTION(BlueprintPure, Category = "GameJoltAPI", meta = (WorldContext = "WorldContextObject", DeprecatedFunction, DeprecationMessage="Use GetUsername of the GameJolt-Subsystem instead."))
    static FString GetUsername(UObject* WorldContextObject);

    UFUNCTION(BlueprintPure, Category = "GameJoltAPI", meta = (WorldContext = "WorldContextObject", DeprecatedFunction, DeprecationMessage="Use GetPrivateKey of the GameJolt-Subsystem instead."))
    static FString GetPrivateKey(UObject* WorldContextObject);

    UFUNCTION(BlueprintPure, Category = "GameJoltAPI", meta = (WorldContext = "WorldContextObject", DeprecatedFunction, DeprecationMessage="Use GetGameID of the GameJolt-Subsystem instead."))
    static int32 GetGameID(UObject* WorldContextObject);

    UFUNCTION(BlueprintPure, Category = "GameJoltAPI", meta = (WorldContext = "WorldContextObject", DeprecatedFunction, DeprecationMessage = "Use IsLoggedIn of the GameJolt-Subsystem instead."))
    static bool IsLoggedIn(UObject* WorldContextObject);

    UFUNCTION(BlueprintCallable, Category = "GameJoltAPI", meta = (WorldContext = "WorldContextObject", DeprecatedFunction, DeprecationMessage = "Use Logout of the GameJolt-Subsystem instead."))
    static void Logout(UObject* WorldContextObject);
};

