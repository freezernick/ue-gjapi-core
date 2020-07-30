// Copyright by Free2Play-Entertainment (2020)

#pragma once

#include "CoreMinimal.h"
#include "GameJoltAsyncBase.h"
#include "GameJoltEnums.h"
#include "Set.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FSetSuccessDelegate);

/**
 * Sets data in the data store.
 */
UCLASS()
class GAMEJOLTAPI_API USet final : public UGameJoltAsyncBase
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"))
	static USet* SetData(UGameJolt* GameJoltAPI, EGJDataStore Scope, const FString Key, const FString Data);

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
	virtual void Callback(const bool bSuccess, UJsonFieldData* JSON, const EJSONResult Status) override;
};
