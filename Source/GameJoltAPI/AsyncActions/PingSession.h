// Copyright by Free2Play-Entertainment (2020)

#pragma once

#include "CoreMinimal.h"
#include "GameJoltAsyncBase.h"
#include "GameJoltEnums.h"
#include "PingSession.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FPingSessionSuccessDelegate);

/**
 * Pings an open session of the current user.
 */
UCLASS()
class GAMEJOLTAPI_API UPingSession final : public UGameJoltAsyncBase
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"))
	static UPingSession* PingSession(UGameJolt* GameJoltAPI, EGJSessionStatus SessionStatus);

	UPROPERTY(BlueprintAssignable)
	FPingSessionSuccessDelegate Success;

	// UBlueprintAsyncActionBase interface
    virtual void Activate() override;
    //~UBlueprintAsyncActionBase interface

private:

	EGJSessionStatus Status;

	UFUNCTION()
	virtual void Callback(const bool bSuccess, UJsonFieldData* JSON, const EJSONResult Status) override;
};
