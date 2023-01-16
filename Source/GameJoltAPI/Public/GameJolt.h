// Copyright by Nick Lamprecht (2020-2023)

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameJoltEnums.h"

#if __has_include ("Launch/Resources/Version.h")
#include "Launch/Resources/Version.h"
#else
#include "Runtime/Launch/Resources/Version.h"
#endif

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

    FString Server;

    FString Version;

    FString UserName;

    FString UserToken;

    bool bLoggedIn = false;

    int32 GameID = 0;

    FString PrivateKey = "";

    void Login(const FString Name, const FString Token);

    friend class ULogin;

    friend class UAutoLogin;

public:

#if ENGINE_MINOR_VERSION < 20

    virtual void BeginDestroy() override;

    static UGameJolt* Instance;

#endif

    UGameJolt(const FObjectInitializer& ObjectInitializer);

    static UGameJolt& Get();

    /**
     * Sets required information for all API requests
     * @param Game_ID Required. Can be found in your game's dashboard
     * @param Private_Key Required. Can be found in your game's dashboard
     * @param Server Optional. Default is https://api.gamejolt.com/api/game/
     * @param Version Optional. Default is v1_2
     */
    UFUNCTION(BlueprintCallable, Category = "GameJoltAPI", meta = (AdvancedDisplay="Server, Version"))
    static void Initialize(const int32 Game_ID, const FString Private_Key, const FString Server = "", const FString Version = "");

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

