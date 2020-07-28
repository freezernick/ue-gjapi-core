// Copyright by Free2Play-Entertainment (2020)

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "JsonFieldData.h"
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
    virtual void Activate() override;
    //~UBlueprintAsyncActionBase interface

protected:

    bool Validate()
    {
        if(!GameJolt || !WorldContextObject)
            return false;
        return true;
    }

    UObject* WorldContextObject;
    UGameJolt* GameJolt;

    UJsonFieldData* FieldData;

    UJsonFieldData* response;

	virtual void Callback(const bool bSuccess, UJsonFieldData* JSON, const EJSONResult Status);

    bool bResponseValid = true;
};
