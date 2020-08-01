// Copyright by Free2Play-Entertainment (2020)

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "JsonData.h"
#include "GameJolt.h"
#include "GameJoltAsyncBase.generated.h"

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
    virtual void Activate() override {};
    //~UBlueprintAsyncActionBase interface

protected:

    bool Validate()
    {
        if(!GameJolt)
            return false;
        return true;
    }

    UGameJolt* GameJolt;

    UJsonData* FieldData;

    UJsonData* response;

	virtual void Callback(const bool bSuccess, UJsonData* JSON);

    bool bResponseValid = true;
};
