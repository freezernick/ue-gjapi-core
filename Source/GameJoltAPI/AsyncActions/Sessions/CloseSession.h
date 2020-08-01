// Copyright by Free2Play-Entertainment (2020)

#pragma once

#include "CoreMinimal.h"
#include "GameJoltAsyncBase.h"
#include "CloseSession.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FCloseSessionSuccessDelegate);

/**
 * Closes the session for the current user.
 */
UCLASS()
class GAMEJOLTAPI_API UCloseSession final : public UGameJoltAsyncBase
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"))
	static UCloseSession* CloseSession(UGameJolt* GameJoltAPI);

	UPROPERTY(BlueprintAssignable)
	FCloseSessionSuccessDelegate Success;

	// UBlueprintAsyncActionBase interface
    virtual void Activate() override;
    //~UBlueprintAsyncActionBase interface

private:

	UFUNCTION()
	virtual void Callback(const bool bSuccess, UJsonData* JSON) override;
};
