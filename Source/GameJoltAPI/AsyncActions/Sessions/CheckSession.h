// Copyright by Free2Play-Entertainment (2020)

#pragma once

#include "CoreMinimal.h"
#include "GameJoltAsyncBase.h"
#include "CheckSession.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCheckSessionSuccessDelegate, bool, bIsSessionOpen);

/**
 * Checks if the session of the current user is still active.
 */
UCLASS()
class GAMEJOLTAPI_API UCheckSession final : public UGameJoltAsyncBase
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"))
	static UCheckSession* CheckSession(UGameJolt* GameJoltAPI);

	UPROPERTY(BlueprintAssignable)
	FCheckSessionSuccessDelegate Success;

	// UBlueprintAsyncActionBase interface
    virtual void Activate() override;
    //~UBlueprintAsyncActionBase interface

private:

	UFUNCTION()
	virtual void Callback(const bool bSuccess, UJsonFieldData* JSON, const EJSONResult Status) override;
};
