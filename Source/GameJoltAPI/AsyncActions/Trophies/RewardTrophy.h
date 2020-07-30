// Copyright by Free2Play-Entertainment (2020)

#pragma once

#include "CoreMinimal.h"
#include "GameJoltAsyncBase.h"
#include "RewardTrophy.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FRewardTrophySuccessDelegate);

/**
 * Rewards a trophy to the current user.
 */
UCLASS()
class GAMEJOLTAPI_API URewardTrophy final : public UGameJoltAsyncBase
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"))
	static URewardTrophy* RewardTrophy(UGameJolt* GameJoltAPI, const int32 ID);

	UPROPERTY(BlueprintAssignable)
	FRewardTrophySuccessDelegate Success;

	// UBlueprintAsyncActionBase interface
    virtual void Activate() override;
    //~UBlueprintAsyncActionBase interface

private:

	int32 TrophyID;

	UFUNCTION()
	virtual void Callback(const bool bSuccess, UJsonFieldData* JSON, const EJSONResult Status) override;
};
