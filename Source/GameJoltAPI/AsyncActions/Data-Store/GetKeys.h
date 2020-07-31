// Copyright by Free2Play-Entertainment (2020)

#pragma once

#include "CoreMinimal.h"
#include "GameJoltAsyncBase.h"
#include "GameJoltEnums.h"
#include "GetKeys.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FGetKeysSuccessDelegate, const TArray<FString>&, Keys);

/**
 * Returns either a list of keys in the game's global data store, or a list of keys in the current user's data store.
 */
UCLASS()
class GAMEJOLTAPI_API UGetKeys final : public UGameJoltAsyncBase
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"))
	static UGetKeys* GetKeys(UGameJolt* GameJoltAPI, EGJDataStore Scope, const FString Pattern = "");

	UPROPERTY(BlueprintAssignable)
	FGetKeysSuccessDelegate Success;

	// UBlueprintAsyncActionBase interface
    virtual void Activate() override;
    //~UBlueprintAsyncActionBase interface

private:

	FString Pattern;
	EGJDataStore Filter;

	UFUNCTION()
	virtual void Callback(const bool bSuccess, UJsonFieldData* JSON, const EJSONResult Status) override;
};