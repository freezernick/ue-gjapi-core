// Copyright by Free2Play-Entertainment (2020)

#pragma once

#include "CoreMinimal.h"
#include "GameJoltAsyncBase.h"
#include "GameJoltStructs.h"
#include "FetchUsers.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FFetchUsersSuccessDelegate, const TArray<FUserInfo>&, Users);

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
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"))
	static UFetchUsers* FetchUsers(UGameJolt* GameJoltAPI, const TArray<int32> UserIDs);

	UPROPERTY(BlueprintAssignable)
	FFetchUsersSuccessDelegate Success;

	// UBlueprintAsyncActionBase interface
    virtual void Activate() override;
    //~UBlueprintAsyncActionBase interface

private:

	TArray<int32> IDs;

	UFUNCTION()
	virtual void Callback(const bool bSuccess, UJsonFieldData* JSON, const EJSONResult Status) final override;
};
