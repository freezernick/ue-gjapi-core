// Copyright by Free2Play-Entertainment (2020)


#include "AddScore.h"
#include "GenericPlatform/GenericPlatformHttp.h"

UAddScore* UAddScore::AddScore(UObject* WCO, UGameJolt* GJAPI, const FString Score, const int32 ScoreSort, const int32 TableID, const FString Guest, const FString ExtraData)
{
    UAddScore* ScoreNode = NewObject<UAddScore>();
    ScoreNode->WorldContextObject = WCO;
    ScoreNode->GameJolt = GJAPI;
    ScoreNode->ScoreString = Score;
    ScoreNode->Sort = ScoreSort;
    ScoreNode->Table = TableID;
    ScoreNode->GuestName = Guest;
    ScoreNode->ExtraScoreData = ExtraData;
    return ScoreNode;
}

void UAddScore::Activate()
{
    if(!Super::Validate() || (!GameJolt->bLoggedIn && GuestName == ""))
    {
        Failure.Broadcast();
        return;
    }

    FScriptDelegate funcDelegate;
    funcDelegate.BindUFunction(this, "Callback");

    FString BaseURL = "/scores/add/?";
    if(!GameJolt->bLoggedIn)
        BaseURL += "&guest=" + FGenericPlatformHttp::UrlEncode(GuestName);
    if(Table != 0)
        BaseURL += "&table_id=" + FString::FromInt(Table);
    if(ExtraScoreData != "")
        BaseURL += "&extra_data=" + FGenericPlatformHttp::UrlEncode(ExtraScoreData);
    BaseURL += "&score=" + FGenericPlatformHttp::UrlEncode(ScoreString) + "&sort=" + FString::FromInt(Sort);
    FieldData = UJsonFieldData::GetRequest(UGameJolt::CreateURL(BaseURL, GameJolt));
    FieldData->OnGetResult.AddUnique(funcDelegate);
}

void UAddScore::Callback(const bool bSuccess, UJsonFieldData* JSON, const EJSONResult Status)
{
    Super::Callback(bSuccess, JSON, Status);
    if(!bResponseValid)
    {
        Failure.Broadcast();
        return;
    }

    Success.Broadcast();
}