// Copyright by Nick Lamprecht (2020-2023)

#pragma once

#include "CoreMinimal.h"
#include "GameJoltAsyncBase.h"
#include "GetKeys.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FGetKeysSuccessDelegate, EGJErrors, Error, const TArray<FString>&, Keys);

/**
 * Returns either a list of keys in the game's global data store, or a list of keys in the current user's data store.
 */
UCLASS()
class GAMEJOLTAPI_API UGetKeys final : public UGameJoltAsyncBase
{
	GENERATED_BODY()

public:

	/**
	 * Returns either a list of keys in the game's global data store, or a list of keys in the current user's data store.
	 * @param Scope If you select 'User', this function will look for keys in a user's data store. If you select 'Global', it will look for keys in the game's global data store.
	 * @param Pattern (optional) The pattern to apply to the key names in the data store. Placeholder character is '*'
	 */
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"))
	static UGetKeys* GetKeys(EGJDataStore Scope, const FString Pattern = "");

	UPROPERTY(BlueprintAssignable)
	FGetKeysSuccessDelegate Success;

	// UBlueprintAsyncActionBase interface
    virtual void Activate() override;
    //~UBlueprintAsyncActionBase interface

private:

	FString Pattern;
	EGJDataStore Filter;

	UFUNCTION()
	virtual void Callback(const bool bSuccess, UJsonData* JSON) override;
};
