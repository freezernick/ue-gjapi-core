// Copyright by Nick Lamprecht (2020-2023)


#include "AsyncActions/Trophies/RewardTrophy.h"

URewardTrophy* URewardTrophy::RewardTrophy(UObject* WorldContextObject, const int32 ID)
{
    URewardTrophy* Node = NewObject<URewardTrophy>();
    Node->WorldContextObject = WorldContextObject;
    Node->TrophyID = ID;
    return Node;
}

void URewardTrophy::Activate()
{
    if(!Super::Validate())
        return;

    if(TrophyID == 0)
    {
        Failure.Broadcast(EGJErrors::ParametersInvalidOrUnset);
        return;
    }

    FScriptDelegate funcDelegate;
    funcDelegate.BindUFunction(this, "Callback");
    FieldData = UJsonData::GetRequest(CreateURL(("/trophies/add-achieved/?trophy_id=" + FString::FromInt(TrophyID))));
    FieldData->OnGetResult.AddUnique(funcDelegate);
}

void URewardTrophy::Callback(const bool bSuccess, UJsonData* JSON)
{
    if(!Super::VerifyResponse(bSuccess, JSON))
        return;

    Success.Broadcast(EGJErrors::None);
}