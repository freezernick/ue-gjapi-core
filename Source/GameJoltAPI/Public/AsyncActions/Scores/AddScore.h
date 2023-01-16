// Copyright by Nick Lamprecht (2020-2023)

#pragma once

#include "CoreMinimal.h"
#include "GameJoltAsyncBase.h"
#include "AddScore.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FAddScoreSuccessDelegate, EGJErrors, Error);

/**
 * Adds a score for a user or guest.
 */
UCLASS()
class GAMEJOLTAPI_API UAddScore final : public UGameJoltAsyncBase
{
	GENERATED_BODY()

public:

	/**
	 * You can either store a score for a user or a guest.
	 * If you're storing for a (logged in) user, the plugin will handle that for you.
	 * If you're storing for a guest, you must pass in the guest parameter.
	 * 
	 * @param Score A string representing the score. (500 Jumps)
	 * @param ScoreSort An integer for sorting the score (500)
	 * @param TableID (optional) The scoreboard ID. Uses the game's main board if none is set
	 * @param Guest Only use this when there is no user logged in and you want to save a score for a guest.
	 * @param ExtraData (optional) If there's any extra data you would like to store as a string, you can use this.
	 */
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"))
	static UAddScore* AddScore(const FString Score, const int32 ScoreSort, const int32 TableID = 0, const FString Guest = "", const FString ExtraData = "");
	static UAddScore* AddScore(const FString Score, const int32 ScoreSort, const FString Guest = "", const int32 TableID = 0, const FString ExtraData = "");

	UPROPERTY(BlueprintAssignable)
	FAddScoreSuccessDelegate Success;

	// UBlueprintAsyncActionBase interface
    virtual void Activate() override;
    //~UBlueprintAsyncActionBase interface

private:

	FString ScoreString;
	int32 Sort;
	FString GuestName;
	int32 Table;
	FString ExtraScoreData;

	UFUNCTION()
	virtual void Callback(const bool bSuccess, UJsonData* JSON) override;
};
