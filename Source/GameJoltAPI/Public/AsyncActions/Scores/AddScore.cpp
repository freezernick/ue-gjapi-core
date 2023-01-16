// Copyright by Nick Lamprecht (2020-2023)


#include "AddScore.h"
#include "GenericPlatform/GenericPlatformHttp.h"

UAddScore* UAddScore::AddScore(const FString Score, const int32 ScoreSort, const int32 TableID, const FString Guest, const FString ExtraData)
{
    UAddScore* ScoreNode = NewObject<UAddScore>();
    ScoreNode->ScoreString = Score;
    ScoreNode->Sort = ScoreSort;
    ScoreNode->Table = TableID;
    ScoreNode->GuestName = Guest;
    ScoreNode->ExtraScoreData = ExtraData;
    return ScoreNode;
}

void UAddScore::Activate()
{
    if(!Super::Validate())
        return;

    if(Sort == 0 || ScoreString == "" || (!UGameJolt::Get().IsLoggedIn() && GuestName == ""))
    {
        Failure.Broadcast(EGJErrors::ParametersInvalidOrUnset);
        return;
    }

    FScriptDelegate funcDelegate;
    funcDelegate.BindUFunction(this, "Callback");

    FString BaseURL = "/scores/add/?";
    if(!UGameJolt::Get().IsLoggedIn())
        BaseURL += "&guest=" + FGenericPlatformHttp::UrlEncode(GuestName);
    if(Table != 0)
        BaseURL += "&table_id=" + FString::FromInt(Table);
    if(ExtraScoreData != "")
        BaseURL += "&extra_data=" + FGenericPlatformHttp::UrlEncode(ExtraScoreData);
    BaseURL += "&score=" + FGenericPlatformHttp::UrlEncode(ScoreString) + "&sort=" + FString::FromInt(Sort);
    FieldData = UJsonData::GetRequest(UGameJolt::CreateURL(BaseURL));
    FieldData->OnGetResult.AddUnique(funcDelegate);
}

void UAddScore::Callback(const bool bSuccess, UJsonData* JSON)
{
    if(!Super::VerifyResponse(bSuccess, JSON))
        return;

    Success.Broadcast(EGJErrors::None);
}