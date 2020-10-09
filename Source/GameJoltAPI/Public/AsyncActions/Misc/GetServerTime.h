// Copyright by Free2Play-Entertainment (2020)

#pragma once

#include "CoreMinimal.h"
#include "GameJoltAsyncBase.h"
#include "GameJoltStructs.h"
#include "GetServerTime.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTimeSuccesDelegate, FServerTime, ServerTime);

/**
 * Returns the time of the Game Jolt server.
 */
UCLASS()
class GAMEJOLTAPI_API UGetServerTime final : public UGameJoltAsyncBase
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"))
	static UGetServerTime* GetServerTime() { return NewObject<UGetServerTime>(); }

	UPROPERTY(BlueprintAssignable)
	FTimeSuccesDelegate Success;

	// UBlueprintAsyncActionBase interface
    virtual void Activate() override;
    //~UBlueprintAsyncActionBase interface

private:

	UFUNCTION()
	virtual void Callback(const bool bSuccess, UJsonData* JSON) override;
};
