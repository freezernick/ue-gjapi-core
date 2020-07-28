// Copyright by Free2Play-Entertainment (2020)

#pragma once

#include "CoreMinimal.h"
#include "GameJoltAsyncBase.h"
#include "GetFriendlist.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FGetFriendlistSuccessDelegate, const TArray<int32>&, Friendlist);

/**
 * Gets the friendlist (array of integers representing user IDs) of the current user
 */
UCLASS()
class GAMEJOLTAPI_API UGetFriendlist final : public UGameJoltAsyncBase
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContext", HidePin = "WorldContext", DefaultToSelf = "WorldContext"))
	static UGetFriendlist* GetFriendlist(UObject* WorldContext, UGameJolt* GameJoltAPI);

	UPROPERTY(BlueprintAssignable)
	FGetFriendlistSuccessDelegate Success;

	// UBlueprintAsyncActionBase interface
    virtual void Activate() override;
    //~UBlueprintAsyncActionBase interface

private:

	UFUNCTION()
	virtual void Callback(const bool bSuccess, UJsonFieldData* JSON, const EJSONResult Status) override;
};
