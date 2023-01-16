// Copyright by Nick Lamprecht (2020-2023)

#pragma once

#include "CoreMinimal.h"
#include "GameJoltAsyncBase.h"
#include "CheckSession.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FCheckSessionSuccessDelegate, EGJErrors, Error, bool, bIsSessionOpen);

/**
 * Checks if the session of the current user is still active.
 */
UCLASS()
class GAMEJOLTAPI_API UCheckSession final : public UGameJoltAsyncBase
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"))
	static UCheckSession* CheckSession() { return NewObject<UCheckSession>(); }

	UPROPERTY(BlueprintAssignable)
	FCheckSessionSuccessDelegate Success;

	// UBlueprintAsyncActionBase interface
    virtual void Activate() override;
    //~UBlueprintAsyncActionBase interface

private:

	UFUNCTION()
	virtual void Callback(const bool bSuccess, UJsonData* JSON) override;
};
