// Copyright by Nick Lamprecht (2020-2023)

#pragma once

#include "CoreMinimal.h"
#include "GameJoltAsyncBase.h"
#include "Update.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FUpdateSuccessDelegate, EGJErrors, Error, FString, Data);

/**
 * Updates data in the data store.
 */
UCLASS()
class GAMEJOLTAPI_API UUpdate final : public UGameJoltAsyncBase
{
	GENERATED_BODY()

public:

	/**
	 * Updates data in the data store.
	 * @param Scope If you select 'User', this item will be set for a user's data store. If you select 'Global', it will be set for the game's global data store.
	 * @param Key The key of the data item you'd like to update.
	 * @param Value The value you'd like to apply to the data store item. 
	 * @param Operation The operation you'd like to perform.
	 * You can only perform mathematical operations on numerical data.
	 */
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"))
	static UUpdate* UpdateData(EGJDataStore Scope, const FString Key, const FString Value, EGJDataOperation Operation);

	UPROPERTY(BlueprintAssignable)
	FUpdateSuccessDelegate Success;

	// UBlueprintAsyncActionBase interface
    virtual void Activate() override;
    //~UBlueprintAsyncActionBase interface

private:

	FString DataKey;
	FString DataValue;
	EGJDataStore Filter;
	EGJDataOperation DataOperation;

	UFUNCTION()
	virtual void Callback(const bool bSuccess, UJsonData* JSON) override;
};
