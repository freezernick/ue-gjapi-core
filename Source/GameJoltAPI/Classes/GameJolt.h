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

    FString UserName;

    FString UserToken;

public:

    bool bLoggedIn = false;

    int32 GameID = 0;

    FString PrivateKey = "";

    FString Server = "https://api.gamejolt.com/api/game/";

    FString Version = "v1_2";

public:

    UFUNCTION(BlueprintCallable, Category = "GameJoltAPI")
    static UGameJolt* Initialize(const int32 GameID, const FString PrivateKey);

    void Login(const FString UserName, const FString UserToken);

    UFUNCTION(BlueprintCallable, Category = "GameJoltAPI")
    void Logout();

    static FString CreateURL(const FString URL, const UGameJolt* GameJolt);
};

