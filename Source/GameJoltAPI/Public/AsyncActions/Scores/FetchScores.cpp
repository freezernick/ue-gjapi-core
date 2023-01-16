// Copyright by Nick Lamprecht (2020-2023)


#include "FetchScores.h"
#include "GenericPlatform/GenericPlatformHttp.h"

UFetchScores* UFetchScores::FetchScores(const int32 Limit, int32 TableID, EGJScoreFilter Filter, const FString Guest, const int32 BetterThan, const int32 WorseThan)
{
    UFetchScores* ScoreNode = NewObject<UFetchScores>();
    ScoreNode->FetchLimit = Limit;
    ScoreNode->Table = TableID;
    ScoreNode->ScoreFilter = Filter;
    ScoreNode->GuestName = Guest;
    ScoreNode->BetterThanFilter = BetterThan;
    ScoreNode->WorseThanFilter = WorseThan;
    return ScoreNode;
}

void UFetchScores::Activate()
{
    if(!Super::Validate())
        return;

    if(BetterThanFilter != 0 && WorseThanFilter != 0)
    {
        Failure.Broadcast(EGJErrors::ParametersInvalidOrUnset);
        return;
    }

    FScriptDelegate funcDelegate;
    funcDelegate.BindUFunction(this, "Callback");

    FString BaseURL = "/scores/?";
    if(Table != 0)
        BaseURL += "&table_id=" + FString::FromInt(Table);
    if(FetchLimit > 0 && FetchLimit != 10)
        BaseURL += "&limit=" + FString::FromInt(FetchLimit);
    if(ScoreFilter == EGJScoreFilter::guest)
    {
        if(GuestName == "")
        {
            Failure.Broadcast(EGJErrors::ParametersInvalidOrUnset);
            return;
        }
        BaseURL += "&guest=" + FGenericPlatformHttp::UrlEncode(GuestName);
    }
    if(BetterThanFilter != 0)
        BaseURL += "&better_than=" + FString::FromInt(BetterThanFilter);
    if(WorseThanFilter != 0)
        BaseURL += "&worse_than=" + FString::FromInt(WorseThanFilter);
    FieldData = UJsonData::GetRequest(UGameJolt::CreateURL(BaseURL, (ScoreFilter == EGJScoreFilter::user ? true : false)));
    FieldData->OnGetResult.AddUnique(funcDelegate);
}

void UFetchScores::Callback(const bool bSuccess, UJsonData* JSON)
{
    if(!Super::VerifyResponse(bSuccess, JSON))
        return;

    TArray<UJsonData*> returnArray = response->GetObjectArray("scores");

    TArray<FScoreInfo> Scores = TArray<FScoreInfo>();
    for(int i = 0; i < returnArray.Num(); i++)
    {
        Scores.Add(FScoreInfo(
            returnArray[i]->GetString("score"),
            returnArray[i]->GetInt("sort"),
            returnArray[i]->GetString("extra_data"),
            returnArray[i]->GetString("user"),
            returnArray[i]->GetInt("user_id"),
            returnArray[i]->GetString("guest"),
            returnArray[i]->GetString("stored"),
            returnArray[i]->GetInt("stored_timestamp")
        ));
    }
    Success.Broadcast(EGJErrors::None, Scores);
}