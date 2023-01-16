// Copyright by Nick Lamprecht (2020-2023)

#pragma once

#include "CoreMinimal.h"
#include "GameJoltAsyncBase.h"
#include "PingSession.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FPingSessionSuccessDelegate, EGJErrors, Error);

/**
 * Pings an open session of the current user.
 */
UCLASS()
class GAMEJOLTAPI_API UPingSession final : public UGameJoltAsyncBase
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"))
	static UPingSession* PingSession(EGJSessionStatus SessionStatus);

	UPROPERTY(BlueprintAssignable)
	FPingSessionSuccessDelegate Success;

	// UBlueprintAsyncActionBase interface
    virtual void Activate() override;
    //~UBlueprintAsyncActionBase interface

private:

	EGJSessionStatus Status;

	UFUNCTION()
	virtual void Callback(const bool bSuccess, UJsonData* JSON) override;
};
