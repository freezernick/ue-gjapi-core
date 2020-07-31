// Copyright by Free2Play-Entertainment (2020)

#pragma once

#include "CoreMinimal.h"
#include "GameJoltAsyncBase.h"
#include "GameJoltStructs.h"
#include "GameJoltEnums.h"
#include "FetchTrophies.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FFetchTrophiesSuccessDelegate, const TArray<FTrophyInfo>&, Trophies);

/**
 * Returns one trophy or multiple trophies, depending on the parameters passed in.
 */
UCLASS()
class GAMEJOLTAPI_API UFetchTrophies final : public UGameJoltAsyncBase
{
	GENERATED_BODY()

public:

	/**
	 * Returns one trophy or multiple trophies, depending on the parameters passed in.
	 * Passing values in the TrophyIDs parameter will ignore the TrophyFilter parameter.
	 * @param GameJoltAPI A reference to a GameJoltAPI object with a set game id and private key.
	 * @param TropyFilter Whether you want to fetch all, only achieved or only unachieved trophies
	 * @param TrophyIDs (Optional) Either a single trophy ID or multiple.
	 */
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"))
	static UFetchTrophies* FetchTrophies(
		UGameJolt* GameJoltAPI,
		EGJAchievedTrophies TrophyFilter,
		TArray<int32> TrophyIDs);

	UPROPERTY(BlueprintAssignable)
	FFetchTrophiesSuccessDelegate Success;

	// UBlueprintAsyncActionBase interface
    virtual void Activate() override;
    //~UBlueprintAsyncActionBase interface

private:

	EGJAchievedTrophies Filter;
	TArray<int32> TrophyID;

	UFUNCTION()
	virtual void Callback(const bool bSuccess, UJsonFieldData* JSON, const EJSONResult Status) override;
};
