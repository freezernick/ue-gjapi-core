// Copyright by Free2Play-Entertainment (2020)


#include "RemoveTrophy.h"

URemoveTrophy* URemoveTrophy::RemoveTrophy(UGameJolt* GJAPI, const int32 ID)
{
    URemoveTrophy* TrophyNode = NewObject<URemoveTrophy>();
    TrophyNode->GameJolt = GJAPI;
    TrophyNode->TrophyID = ID;
    return TrophyNode;
}

void URemoveTrophy::Activate()
{
    if(!Super::Validate())
    {
        Failure.Broadcast();
        return;
    }
    FScriptDelegate funcDelegate;
    funcDelegate.BindUFunction(this, "Callback");
    FieldData = UJsonData::GetRequest(UGameJolt::CreateURL(("/trophies/remove-achieved/?trophy_id=" + FString::FromInt(TrophyID)), GameJolt));
    FieldData->OnGetResult.AddUnique(funcDelegate);
}

void URemoveTrophy::Callback(const bool bSuccess, UJsonData* JSON)
{
    Super::Callback(bSuccess, JSON);
    if(!bResponseValid)
    {
        Failure.Broadcast();
        return;
    }

    Success.Broadcast();
}