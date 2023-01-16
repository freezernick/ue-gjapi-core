// Copyright by Nick Lamprecht (2020-2023)

#pragma once

#include "CoreMinimal.h"
#include "GameJoltAsyncBase.h"
#include "Remove.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FRemoveDataSuccessDelegate, EGJErrors, Error);

/**
 * Removes data from the data store.
 */
UCLASS()
class GAMEJOLTAPI_API URemove final : public UGameJoltAsyncBase
{
	GENERATED_BODY()

public:

	/**
	 * Removes data from the data store.
	 * @param Scope If you select 'User', the item will be removed from a user's data store. If you select 'Global', it will be removed from the game's global data store.
	 * @param Key The key of the data item you'd like to remove.
	 */
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"))
	static URemove* RemoveData(EGJDataStore Scope, const FString Key);

	UPROPERTY(BlueprintAssignable)
	FRemoveDataSuccessDelegate Success;

	// UBlueprintAsyncActionBase interface
    virtual void Activate() override;
    //~UBlueprintAsyncActionBase interface

private:

	FString DataKey;
	EGJDataStore Filter;

	UFUNCTION()
	virtual void Callback(const bool bSuccess, UJsonData* JSON) override;
};
