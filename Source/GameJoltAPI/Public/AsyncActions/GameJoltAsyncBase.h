// Copyright by Nick Lamprecht (2020-2023)

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "JsonData.h"
#include "GameJolt.h"
#include "GameJoltEnums.h"
#include "GameJoltAsyncBase.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnFailureOutputPin, EGJErrors, Error);

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
        UGameJolt& API = UGameJolt::Get();
        if(API.GetPrivateKey() == "")
        {
            Failure.Broadcast(EGJErrors::PrivateKeyUnset);
            return false;
        }
        if(API.GetGameID() == 0)
        {
            Failure.Broadcast(EGJErrors::GameIDUnset);
            return false;
        }
        return true;
    }

    UJsonData* FieldData;

    UJsonData* response;

	virtual void Callback(const bool bSuccess, UJsonData* JSON);

    bool VerifyResponse(const bool bSuccess, UJsonData* JSON);
};
