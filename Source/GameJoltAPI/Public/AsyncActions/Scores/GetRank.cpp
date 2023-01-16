// Copyright by Nick Lamprecht (2020-2023)


#include "GetRank.h"

UGetRank* UGetRank::GetRank(const int32 Sort, const int32 TableID)
{
    UGetRank* ScoreNode = NewObject<UGetRank>();
    ScoreNode->ScoreSort = Sort;
    ScoreNode->Table = TableID;
    return ScoreNode;
}

void UGetRank::Activate()
{
    if(!Super::Validate())
        return;

    if(ScoreSort == 0)
    {
        Failure.Broadcast(EGJErrors::ParametersInvalidOrUnset);
        return;
    }

    FScriptDelegate funcDelegate;
    funcDelegate.BindUFunction(this, "Callback");

    FString BaseURL = "/scores/get-rank/?sort=" + FString::FromInt(ScoreSort);
    if(Table != 0)
        BaseURL += "&table_id=" + FString::FromInt(Table);
    FieldData = UJsonData::GetRequest(UGameJolt::CreateURL(BaseURL));
    FieldData->OnGetResult.AddUnique(funcDelegate);
}

void UGetRank::Callback(const bool bSuccess, UJsonData* JSON)
{
    if(!Super::VerifyResponse(bSuccess, JSON))
        return;

    int32 Rank = response->GetInt("rank");
    Success.Broadcast(EGJErrors::None, Rank);
}