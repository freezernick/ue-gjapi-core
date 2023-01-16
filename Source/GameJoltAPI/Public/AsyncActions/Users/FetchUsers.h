// Copyright by Nick Lamprecht (2020-2023)

#pragma once

#include "CoreMinimal.h"
#include "GameJoltAsyncBase.h"
#include "GameJoltStructs.h"
#include "FetchUsers.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FFetchUsersSuccessDelegate, EGJErrors, Error, const TArray<FUserInfo>&, Users);

/**
 * Returns a user's data.
 */
UCLASS()
class GAMEJOLTAPI_API UFetchUsers : public UGameJoltAsyncBase
{
	GENERATED_BODY()
	
public:

	/**
	 * Returns a user's data.
	 * @param UserIDs The ID(s) of the user(s) whose data you'd like to fetch.
	 */
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"), DisplayName = "Fetch Users by ID")
	static UFetchUsers* FetchUsers_ID(const TArray<int32> UserIDs);

	/**
	 * Returns a user's data.
	 * @param UserNames The name of the userwhose data you'd like to fetch.
	 */
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"), DisplayName = "Fetch User by Name")
	static UFetchUsers* FetchUsers_Name(const FString UserName);

	UPROPERTY(BlueprintAssignable)
	FFetchUsersSuccessDelegate Success;

	// UBlueprintAsyncActionBase interface
    virtual void Activate() override;
    //~UBlueprintAsyncActionBase interface

private:

	TArray<int32> IDs;
	FString Name;

	UFUNCTION()
	virtual void Callback(const bool bSuccess, UJsonData* JSON) final override;
};
