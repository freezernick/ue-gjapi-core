// Copyright by Nick Lamprecht (2020-2023)


#include "RemoveTrophy.h"

URemoveTrophy* URemoveTrophy::RemoveTrophy(const int32 ID)
{
    URemoveTrophy* TrophyNode = NewObject<URemoveTrophy>();
    TrophyNode->TrophyID = ID;
    return TrophyNode;
}

void URemoveTrophy::Activate()
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
    FieldData = UJsonData::GetRequest(UGameJolt::CreateURL("/trophies/remove-achieved/?trophy_id=" + FString::FromInt(TrophyID)));
    FieldData->OnGetResult.AddUnique(funcDelegate);
}

void URemoveTrophy::Callback(const bool bSuccess, UJsonData* JSON)
{
    if(!Super::VerifyResponse(bSuccess, JSON))
        return;

    Success.Broadcast(EGJErrors::None);
}