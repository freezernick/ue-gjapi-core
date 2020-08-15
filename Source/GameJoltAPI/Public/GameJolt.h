// Copyright by Free2Play-Entertainment (2020)

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameJoltEnums.h"
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
    UPROPERTY(BlueprintReadOnly, Category = "GameJolt")
    bool bLoggedIn = false;

    UPROPERTY(BlueprintReadOnly, Category = "GameJolt")
    int32 GameID = 0;

    UPROPERTY(BlueprintReadOnly, Category = "GameJolt")
    FString PrivateKey = "";

    FString Server = "https://api.gamejolt.com/api/game/";

    FString Version = "v1_2";

    UPROPERTY(BlueprintReadOnly, Category = "GameJolt")
    FString UserName;

public:

    UFUNCTION(BlueprintCallable, Category = "GameJoltAPI")
    static UGameJolt* Initialize(const int32 Game_ID, const FString Private_Key);

    void Login(const FString UserName, const FString UserToken);

    UFUNCTION(BlueprintCallable, Category = "GameJoltAPI")
    void Logout();

    static FString CreateURL(const FString URL, const UGameJolt* GameJolt, bool AppendUserInfo = true);
};

