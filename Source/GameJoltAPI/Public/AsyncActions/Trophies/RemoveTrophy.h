// Copyright by Nick Lamprecht (2020-2023)

#pragma once

#include "CoreMinimal.h"
#include "GameJoltAsyncBase.h"
#include "RemoveTrophy.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FRemoveTrophySuccessDelegate, EGJErrors, Error);

/**
 * Removes a rewarded trophy from the current user.
 */
UCLASS()
class GAMEJOLTAPI_API URemoveTrophy final : public UGameJoltAsyncBase
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"))
	static URemoveTrophy* RemoveTrophy(const int32 ID);

	UPROPERTY(BlueprintAssignable)
	FRemoveTrophySuccessDelegate Success;

	// UBlueprintAsyncActionBase interface
    virtual void Activate() override;
    //~UBlueprintAsyncActionBase interface

private:

	int32 TrophyID;

	UFUNCTION()
	virtual void Callback(const bool bSuccess, UJsonData* JSON) override;
};
