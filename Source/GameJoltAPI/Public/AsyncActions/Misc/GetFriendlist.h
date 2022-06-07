// Copyright by Nick Lamprecht (2020-2023)

#pragma once

#include "CoreMinimal.h"
#include "GameJoltAsyncBase.h"
#include "GetFriendlist.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FGetFriendlistSuccessDelegate, EGJErrors, Error, const TArray<int32>&, Friendlist);

/**
 * Gets the friendlist (array of integers representing user IDs) of the current user
 */
UCLASS()
class GAMEJOLTAPI_API UGetFriendlist final : public UGameJoltAsyncBase
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"))
	static UGetFriendlist* GetFriendlist(UObject* WorldContextObject)
	{ 
		UGetFriendlist* Node = NewObject<UGetFriendlist>();
		Node->WorldContextObject = WorldContextObject;
		return Node;
	}

	UPROPERTY(BlueprintAssignable)
	FGetFriendlistSuccessDelegate Success;

	// UBlueprintAsyncActionBase interface
    virtual void Activate() override;
    //~UBlueprintAsyncActionBase interface

private:

	UFUNCTION()
	virtual void Callback(const bool bSuccess, UJsonData* JSON) override;
};
