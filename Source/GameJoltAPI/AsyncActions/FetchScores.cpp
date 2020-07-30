// Copyright by Free2Play-Entertainment (2020)


#include "FetchScores.h"
#include "GenericPlatform/GenericPlatformHttp.h"

UFetchScores* UFetchScores::FetchScores(UGameJolt* GJAPI, const int32 Limit, int32 TableID, EGJScoreFilter Filter, const FString Guest, const int32 BetterThan, const int32 WorseThan)
{
    UFetchScores* ScoreNode = NewObject<UFetchScores>();
    ScoreNode->GameJolt = GJAPI;
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
    if(!Super::Validate() || BetterThanFilter != 0 && WorseThanFilter != 0)
    {
        Failure.Broadcast();
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
            Failure.Broadcast();
            return;
        }
        BaseURL += "&guest=" + FGenericPlatformHttp::UrlEncode(GuestName);
    }
    if(BetterThanFilter != 0)
        BaseURL += "&better_than=" + FString::FromInt(BetterThanFilter);
    if(WorseThanFilter != 0)
        BaseURL += "&worse_than=" + FString::FromInt(WorseThanFilter);
    FieldData = UJsonFieldData::GetRequest(UGameJolt::CreateURL(BaseURL, GameJolt, (ScoreFilter == EGJScoreFilter::user ? true : false)));
    FieldData->OnGetResult.AddUnique(funcDelegate);
}

void UFetchScores::Callback(const bool bSuccess, UJsonFieldData* JSON, const EJSONResult Status)
{
    Super::Callback(bSuccess, JSON, Status);
    if(!bResponseValid)
    {
        Failure.Broadcast();
        return;
    }

    bool bJsonSuccess = false;
    TArray<UJsonFieldData*> returnArray = response->GetObjectArray("scores", bJsonSuccess);
    if(!bJsonSuccess)
    {
        Failure.Broadcast();
        return;
    }
    TArray<FScoreInfo> Scores = TArray<FScoreInfo>();
    for(int i = 0; i < returnArray.Num(); i++)
    {
        Scores.Add(FScoreInfo(
            returnArray[i]->GetString("score", bJsonSuccess),
            returnArray[i]->GetInt("sort", bJsonSuccess),
            returnArray[i]->GetString("extra_data", bJsonSuccess),
            returnArray[i]->GetString("user", bJsonSuccess),
            returnArray[i]->GetInt("user_id", bJsonSuccess),
            returnArray[i]->GetString("guest", bJsonSuccess),
            returnArray[i]->GetString("stored", bJsonSuccess),
            returnArray[i]->GetInt("stored_timestamp", bJsonSuccess)
        ));
    }
    Success.Broadcast(Scores);
}