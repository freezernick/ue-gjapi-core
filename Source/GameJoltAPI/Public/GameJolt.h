// Copyright by Free2Play-Entertainment (2020)

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameJoltEnums.h"
#include "GameJoltAPI.h"
#include "GameJolt.generated.h"

/**
 * Class to interact with the GameJolt-API.
 * Usable from Blueprint and C++.
 */
UCLASS(Blueprintable)
class GAMEJOLTAPI_API UGameJolt : public UObject
{
    GENERATED_BODY()
    
private:

    FString UserName;

    FString UserToken;

    bool bLoggedIn = false;

    int32 GameID = 0;

    FString PrivateKey = "";

    void Login(const FString Name, const FString Token);

    friend class ULogin;

    friend class UAutoLogin;

public:

    static UGameJolt& GJ;

    static UGameJolt& Get()
    {
        return GJ;
    }

    UFUNCTION(BlueprintCallable, Category = "GameJoltAPI")
    static void Initialize(const int32 Game_ID, const FString Private_Key);

    UFUNCTION(BlueprintPure, Category = "GameJoltAPI")
    static FString GetUsername()
    {
        return UGameJolt::Get().UserName;
    }

    UFUNCTION(BlueprintPure, Category = "GameJoltAPI")
    static FString GetPrivateKey()
    {
        return UGameJolt::Get().PrivateKey;
    }

    UFUNCTION(BlueprintPure, Category = "GameJoltAPI")
    static int32 GetGameID()
    {
        return UGameJolt::Get().GameID;
    }

    UFUNCTION(BlueprintPure, Category = "GameJoltAPI")
    static bool IsLoggedIn()
    {
        return UGameJolt::Get().bLoggedIn;
    }

    UFUNCTION(BlueprintCallable, Category = "GameJoltAPI")
    static void Logout();

    static FString CreateURL(const FString URL, bool AppendUserInfo = true);
};

