// Copyright by Free2Play-Entertainment (2020)


#include "RemoveTrophy.h"

URemoveTrophy* URemoveTrophy::RemoveTrophy(UObject* WCO, UGameJolt* GJAPI, const int32 ID)
{
    URemoveTrophy* TrophyNode = NewObject<URemoveTrophy>();
    TrophyNode->WorldContextObject = WCO;
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
    FieldData = UJsonFieldData::GetRequest(UGameJolt::CreateURL(("/trophies/remove-achieved/?trophy_id=" + FString::FromInt(TrophyID)), GameJolt));
    FieldData->OnGetResult.AddUnique(funcDelegate);
}

void URemoveTrophy::Callback(const bool bSuccess, UJsonFieldData* JSON, const EJSONResult Status)
{
    Super::Callback(bSuccess, JSON, Status);
    if(!bResponseValid)
    {
        Failure.Broadcast();
        return;
    }

    Success.Broadcast();
}