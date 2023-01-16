// Copyright by Nick Lamprecht (2020-2023)

#pragma once

#include "CoreMinimal.h"
#include "GameJoltAsyncBase.h"
#include "OpenSession.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOpenSessionSuccessDelegate, EGJErrors, Error);

/**
 * Opens a session for the current user.
 */
UCLASS()
class GAMEJOLTAPI_API UOpenSession final : public UGameJoltAsyncBase
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"))
	static UOpenSession* OpenSession() { return NewObject<UOpenSession>(); }

	UPROPERTY(BlueprintAssignable)
	FOpenSessionSuccessDelegate Success;

	// UBlueprintAsyncActionBase interface
    virtual void Activate() override;
    //~UBlueprintAsyncActionBase interface

private:

	UFUNCTION()
	virtual void Callback(const bool bSuccess, UJsonData* JSON) override;
};
