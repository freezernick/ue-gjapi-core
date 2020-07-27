// Copyright by Free2Play-Entertainment (2020)

#pragma once

#include "CoreMinimal.h"
#include "GameJoltAsyncBase.h"
#include "GetServerTime.generated.h"

struct FDateTime;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTimeSuccesDelegate, FDateTime, ServerTime);

/**
 * 
 */
UCLASS()
class GAMEJOLTAPI_API UGetServerTime final : public UGameJoltAsyncBase
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContext", HidePin = "WorldContext", DefaultToSelf = "WorldContext"))
	static UGetServerTime* GetServerTime(UObject* WorldContext, UGameJolt* GameJoltAPI);

	UPROPERTY(BlueprintAssignable)
	FTimeSuccesDelegate Success;

	// UBlueprintAsyncActionBase interface
    virtual void Activate() override;
    //~UBlueprintAsyncActionBase interface

private:

	UFUNCTION()
	virtual void Callback(const bool bSuccess, UJsonFieldData* JSON, const EJSONResult Status) override;
};
