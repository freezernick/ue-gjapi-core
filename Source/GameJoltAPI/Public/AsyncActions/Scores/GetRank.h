// Copyright by Nick Lamprecht (2020-2023)

#pragma once

#include "CoreMinimal.h"
#include "GameJoltAsyncBase.h"
#include "GetRank.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FGetRankSuccessDelegate, EGJErrors, Error, int32, Rank);

/**
 * Returns the rank of a particular score on a score table.
 */
UCLASS()
class GAMEJOLTAPI_API UGetRank final : public UGameJoltAsyncBase
{
	GENERATED_BODY()

public:

	/**
	 * Returns the rank of a particular score on a score table.
	 * If the score is not represented by any rank on the score table, the request will return the rank that is closest to the requested score.
	 * 
	 * @param Sort This is a numerical sorting value that is represented by a rank on the score table.
	 * @param TableID (optional) The scoreboard ID. Uses the game's main board if none is set
	 */
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"))
	static UGetRank* GetRank(const int32 ScoreSort, const int32 TableID = 0);

	UPROPERTY(BlueprintAssignable)
	FGetRankSuccessDelegate Success;

	// UBlueprintAsyncActionBase interface
    virtual void Activate() override;
    //~UBlueprintAsyncActionBase interface

private:

	int32 ScoreSort;
	int32 Table;

	UFUNCTION()
	virtual void Callback(const bool bSuccess, UJsonData* JSON) override;
};
