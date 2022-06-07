// Copyright by Nick Lamprecht (2020-2023)

#pragma once

#include "CoreMinimal.h"
#include "GameJoltAsyncBase.h"
#include "CloseSession.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCloseSessionSuccessDelegate, EGJErrors, Error);

/**
 * Closes the session for the current user.
 */
UCLASS()
class GAMEJOLTAPI_API UCloseSession final : public UGameJoltAsyncBase
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"))
	static UCloseSession* CloseSession(UObject* WorldContextObject)
	{
		UCloseSession* Node = NewObject<UCloseSession>();
		Node->WorldContextObject = WorldContextObject;
		return Node;
	}

	UPROPERTY(BlueprintAssignable)
	FCloseSessionSuccessDelegate Success;

	// UBlueprintAsyncActionBase interface
    virtual void Activate() override;
    //~UBlueprintAsyncActionBase interface

private:

	UFUNCTION()
	virtual void Callback(const bool bSuccess, UJsonData* JSON) override;
};
