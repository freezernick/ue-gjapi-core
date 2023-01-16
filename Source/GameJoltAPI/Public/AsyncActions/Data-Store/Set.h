// Copyright by Nick Lamprecht (2020-2023)

#pragma once

#include "CoreMinimal.h"
#include "GameJoltAsyncBase.h"
#include "Set.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FSetSuccessDelegate, EGJErrors, Error);

/**
 * Sets data in the data store.
 */
UCLASS()
class GAMEJOLTAPI_API USet final : public UGameJoltAsyncBase
{
	GENERATED_BODY()

public:

	/**
	 * Sets data in the data store.
	 * You can update an existing key/value-pair or create a new one.
	 * @param Scope If you select 'User', this item will be set for a user's data store. If you select 'Global', it will be set for the game's global data store.
	 * @param Key The key of the data item you'd like to set.
	 * @param Data The data you'd like to set.
	 */
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"))
	static USet* SetData(EGJDataStore Scope, const FString Key, const FString Data);

	UPROPERTY(BlueprintAssignable)
	FSetSuccessDelegate Success;

	// UBlueprintAsyncActionBase interface
    virtual void Activate() override;
    //~UBlueprintAsyncActionBase interface

private:

	FString DataKey;
	FString DataValue;
	EGJDataStore Filter;

	UFUNCTION()
	virtual void Callback(const bool bSuccess, UJsonData* JSON) override;
};
