// Copyright by Nick Lamprecht (2020-2023)

#pragma once

#include "CoreMinimal.h"
#include "GameJoltAsyncBase.h"
#include "Login.generated.h"

class UGameJolt;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FLoginSuccesDelegate, EGJErrors, Error);

/**
 * 
 */
UCLASS()
class GAMEJOLTAPI_API ULogin : public UGameJoltAsyncBase
{
	GENERATED_BODY()
	
public:

	/**
	* Authenticates the user's information. This should be done before you make any calls for the user, to make sure the user's credentials (username and token) are valid.
	*/
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"))
	static ULogin* Login(UObject* WorldContextObject, const FString UserName, const FString UserToken);

	UPROPERTY(BlueprintAssignable)
	FLoginSuccesDelegate Success;

	// UBlueprintAsyncActionBase interface
    virtual void Activate() override;
    //~UBlueprintAsyncActionBase interface

private:

	FString Name;
	FString Token;

	UFUNCTION()
	virtual void Callback(const bool bSuccess, UJsonData* JSON) final override;
};
