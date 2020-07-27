// Copyright by Free2Play-Entertainment (2020)

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "GameJoltAsyncBase.generated.h"

class UGameJolt;

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnFailureOutputPin);

/**
 * 
 */
UCLASS()
class UGameJoltAsyncBase : public UBlueprintAsyncActionBase
{

public:

    GENERATED_BODY()

    UPROPERTY(BlueprintAssignable)
	FOnFailureOutputPin Failure;

    // UBlueprintAsyncActionBase interface
    virtual void Activate() override;
    //~UBlueprintAsyncActionBase interface

protected:
    UObject* WorldContextObject;
    UGameJolt* GameJolt;
};
