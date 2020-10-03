// Copyright by Free2Play-Entertainment (2020)

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameJoltEnums.h"
#include "GameJoltAPI.h"
#include "GameJolt.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class GAMEJOLTAPI_API UGameJolt : public UObject
{
    GENERATED_BODY()
    
private:

    FString UserToken;

public:

    static UGameJolt* Get() { return FModuleManager::GetModulePtr<FGameJoltAPIModule>("GameJoltAPI")->GameJoltAPI; }

    UPROPERTY(BlueprintReadOnly, Category = "GameJolt")
    bool bLoggedIn = false;

    UPROPERTY(BlueprintReadOnly, Category = "GameJolt")
    int32 GameID = 0;

    UPROPERTY(BlueprintReadOnly, Category = "GameJolt")
    FString PrivateKey = "";

    FString Server = FString("https://api.gamejolt.com/api/game/");

    FString Version = FString("v1_2");

    UPROPERTY(BlueprintReadOnly, Category = "GameJolt")
    FString UserName;

public:

    UFUNCTION(BlueprintCallable, Category = "GameJoltAPI")
    static void Initialize(const int32 Game_ID, const FString Private_Key);

    void Login(const FString UserName, const FString UserToken);

    UFUNCTION(BlueprintCallable, Category = "GameJoltAPI")
    static void Logout();

    static FString CreateURL(const FString URL, bool AppendUserInfo = true);
};

