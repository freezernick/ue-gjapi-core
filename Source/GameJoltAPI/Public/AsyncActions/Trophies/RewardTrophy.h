// Copyright by Nick Lamprecht (2020-2023)

#pragma once

#include "CoreMinimal.h"
#include "GameJoltAsyncBase.h"
#include "RewardTrophy.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FRewardTrophySuccessDelegate, EGJErrors, Error);

/**
 * Rewards a trophy to the current user.
 */
UCLASS()
class GAMEJOLTAPI_API URewardTrophy final : public UGameJoltAsyncBase
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"))
	static URewardTrophy* RewardTrophy(const int32 ID);

	UPROPERTY(BlueprintAssignable)
	FRewardTrophySuccessDelegate Success;

	// UBlueprintAsyncActionBase interface
    virtual void Activate() override;
    //~UBlueprintAsyncActionBase interface

private:

	int32 TrophyID;

	UFUNCTION()
	virtual void Callback(const bool bSuccess, UJsonData* JSON) override;
};
