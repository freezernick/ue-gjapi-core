// Copyright by Nick Lamprecht (2020-2023)

#pragma once

#include "CoreMinimal.h"
#include "GameJoltAsyncBase.h"
#include "GameJoltStructs.h"
#include "FetchScores.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FFetchScoresSuccessDeleagte, EGJErrors, Error, const TArray<FScoreInfo>&, Scores);

/**
 * Returns a list of scores
 */
UCLASS()
class GAMEJOLTAPI_API UFetchScores final : public UGameJoltAsyncBase
{
	GENERATED_BODY()

public:

	/**
	 * Returns a list of scores either for a user or globally for a game.
	 * The maximum amount of scores you can retrieve is 100.
	 * @param Limit The number of scores you'd like to return. The maximum amount of scores you can retrieve is 100.
	 * @param TableID (optional) The scoreboard ID. Uses the game's main board if none is set.
	 * @param Filter Whether you want to fetch scores by all users, a specific guest or the current user
	 * @param Guest Allows you to fetch scores by a specific guest name.
	 * @param BetterThan Fetch only scores better than this score sort value. Mutually exclusive with WorseThan.
	 * @param WorseThan Fetch only scores worse than this score sort value. Mutually exclusive with BetterThan.
	 */
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"))
	static UFetchScores* FetchScores(
		const int32 Limit = 10,
		const int32 TableID = 0,
		EGJScoreFilter Filter = EGJScoreFilter::all,
		const FString Guest = "",
		const int32 BetterThan = 0,
		const int32 WorseThan = 0);

	UPROPERTY(BlueprintAssignable)
	FFetchScoresSuccessDeleagte Success;

	// UBlueprintAsyncActionBase interface
    virtual void Activate() override;
    //~UBlueprintAsyncActionBase interface

private:

	int32 FetchLimit;
	int32 Table;
	EGJScoreFilter ScoreFilter;
	FString GuestName;
	int32 BetterThanFilter;
	int32 WorseThanFilter;

	UFUNCTION()
	virtual void Callback(const bool bSuccess, UJsonData* JSON) override;
};
