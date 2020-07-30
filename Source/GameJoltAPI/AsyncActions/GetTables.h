// Copyright by Free2Play-Entertainment (2020)

#pragma once

#include "CoreMinimal.h"
#include "GameJoltAsyncBase.h"
#include "GameJoltStructs.h"
#include "GetTables.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FGetTablesSuccessDelegate, const TArray<FScoreTableInfo>&, Tables);

/**
 * Returns a list of high score tables for a game.
 */
UCLASS()
class GAMEJOLTAPI_API UGetTables final : public UGameJoltAsyncBase
{
	GENERATED_BODY()

public:

	/**
	 * Returns a list of high score tables for a game.
	 */
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"))
	static UGetTables* GetTables(UGameJolt* GameJoltAPI);

	UPROPERTY(BlueprintAssignable)
	FGetTablesSuccessDelegate Success;

	// UBlueprintAsyncActionBase interface
    virtual void Activate() override;
    //~UBlueprintAsyncActionBase interface

private:

	UFUNCTION()
	virtual void Callback(const bool bSuccess, UJsonFieldData* JSON, const EJSONResult Status) override;
};
