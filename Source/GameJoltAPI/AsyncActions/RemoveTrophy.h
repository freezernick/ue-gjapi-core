// Copyright by Free2Play-Entertainment (2020)

#pragma once

#include "CoreMinimal.h"
#include "GameJoltAsyncBase.h"
#include "RemoveTrophy.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FRemoveTrophySuccessDelegate);

/**
 * Removes a rewarded trophy from the current user.
 */
UCLASS()
class GAMEJOLTAPI_API URemoveTrophy final : public UGameJoltAsyncBase
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContext", HidePin = "WorldContext", DefaultToSelf = "WorldContext"))
	static URemoveTrophy* RemoveTrophy(UObject* WorldContext, UGameJolt* GameJoltAPI, const int32 ID);

	UPROPERTY(BlueprintAssignable)
	FRemoveTrophySuccessDelegate Success;

	// UBlueprintAsyncActionBase interface
    virtual void Activate() override;
    //~UBlueprintAsyncActionBase interface

private:

	int32 TrophyID;

	UFUNCTION()
	virtual void Callback(const bool bSuccess, UJsonFieldData* JSON, const EJSONResult Status) override;
};
