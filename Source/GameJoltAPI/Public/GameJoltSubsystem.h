// Copyright by Nick Lamprecht (2020-2022)

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Kismet/GameplayStatics.h"
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

	/**
     * Sets required information for all API requests
     * @param Game_ID Required. Can be found in your game's dashboard
     * @param Private_Key Required. Can be found in your game's dashboard
     * @param Server Optional. Default is https://api.gamejolt.com/api/game/
     * @param Version Optional. Default is v1_2
     */
	UFUNCTION(BlueprintCallable, Category = "GameJoltAPI", meta = (AdvancedDisplay="Server, Version", DisplayName="Initialize"))
    void Setup(const int32 Game_ID, const FString Private_Key, const FString Server = "", const FString Version = "");

    UFUNCTION(BlueprintPure, Category = "GameJoltAPI")
    FString GetUsername()
    {
        return UserName;
    }

    UFUNCTION(BlueprintPure, Category = "GameJoltAPI")
    FString GetPrivateKey()
    {
        return PrivateKey;
    }

    UFUNCTION(BlueprintPure, Category = "GameJoltAPI")
    int32 GetGameID()
    {
        return GameID;
    }

    UFUNCTION(BlueprintPure, Category = "GameJoltAPI")
    bool IsLoggedIn()
    {
        return bLoggedIn;
    }

    void Login(const FString Name, const FString Token);

    UFUNCTION(BlueprintCallable, Category = "GameJoltAPI")
    void Logout();

    FString CreateURL(const FString URL, bool AppendUserInfo = true);

    friend class ULogin;

    friend class UAutoLogin;

};
