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

	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"))
	static ULogin* Login(const FString UserName, const FString UserToken);

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
