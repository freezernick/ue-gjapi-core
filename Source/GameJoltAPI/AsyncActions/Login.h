// Copyright by Free2Play-Entertainment (2020)

#pragma once

#include "CoreMinimal.h"
#include "GameJoltAsyncBase.h"
#include "GameJoltStructs.h"
#include "JsonFieldData.h"
#include "Login.generated.h"

class UGameJolt;

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FLoginSuccesDelegate);

/**
 * 
 */
UCLASS()
class GAMEJOLTAPI_API ULogin : public UGameJoltAsyncBase
{
	GENERATED_BODY()
	
public:

	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContext", HidePin = "WorldContext", DefaultToSelf = "WorldContext"))
	static ULogin* Login(UObject* WorldContext, UGameJolt* GameJoltAPI, const FString UserName, const FString UserToken);

	UPROPERTY(BlueprintAssignable)
	FLoginSuccesDelegate Success;

	// UBlueprintAsyncActionBase interface
    virtual void Activate() override;
    //~UBlueprintAsyncActionBase interface

private:

	FString Name;
	FString Token;

	class UJsonFieldData* FieldData;

	UFUNCTION()
	void Callback(const bool bSuccess, UJsonFieldData* JSON, const EJSONResult Status);

};
