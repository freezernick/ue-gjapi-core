// Copyright by Nick Lamprecht (2020-2023)

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "GameJoltSubsystem.generated.h"

/**
 * 
 */
UCLASS()
class GAMEJOLTAPI_API UGameJoltSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

	FString Server = "";

    FString Version = "";

    FString UserName = "";

    FString UserToken = "";

    bool bLoggedIn = false;

    int32 GameID = 0;

    FString PrivateKey = "";

    friend class ULogin;

    friend class UAutoLogin;

public:

    virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	/**
     * Sets required information for all API requests
     * @param Game_ID Required. Can be found in your game's dashboard
     * @param Private_Key Required. Can be found in your game's dashboard
     * @param Server Optional. Default is https://api.gamejolt.com/api/game/
     * @param Version Optional. Default is v1_2
     */
    UFUNCTION(BlueprintCallable, Category = "GameJoltAPI", meta = (AdvancedDisplay="Server, Version", DisplayName="Initialize", WorldContext = "WCO", DeprecatedFunction, DeprecationMessage = "Please use the new plugin settings instead"))
    static void Setup(UObject* WCO, const int32 Game_ID, const FString Private_Key, const FString Server = "", const FString Version = "");
    void Setup(const int32 Game_ID, const FString Private_Key, const FString Server = "", const FString Version = "");

    UFUNCTION(BlueprintPure, Category = "GameJoltAPI", meta=(WorldContext = "WCO"))
    static FString GetUsername(UObject* WCO);
    FString GetUsername();

    UFUNCTION(BlueprintPure, Category = "GameJoltAPI", meta=(WorldContext = "WCO"))
    static FString GetPrivateKey(UObject* WCO);
    FString GetPrivateKey();

    UFUNCTION(BlueprintPure, Category = "GameJoltAPI", meta=(WorldContext = "WCO"))
    static int32 GetGameID(UObject* WCO);
    int32 GetGameID();

    UFUNCTION(BlueprintPure, Category = "GameJoltAPI", meta=(WorldContext = "WCO"))
    static bool IsLoggedIn(UObject* WCO);
    bool IsLoggedIn();

    void Login(const FString Name, const FString Token);

    UFUNCTION(BlueprintCallable, Category = "GameJoltAPI", meta=(WorldContext = "WCO"))
    static void Logout(UObject* WCO);
    void Logout();

    FString CreateURL(const FString URL, bool AppendUserInfo = true);

    friend class ULogin;

    friend class UAutoLogin;

};
