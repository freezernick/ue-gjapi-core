// Copyright by Nick Lamprecht (2020-2023)


#include "AsyncActions/Scores/AddScore.h"
#include "GenericPlatform/GenericPlatformHttp.h"

UAddScore* UAddScore::AddScore(UObject* WorldContextObject, const FString Score, const int32 ScoreSort, const int32 TableID, const FString Guest, const FString ExtraData)
{
    UAddScore* Node = NewObject<UAddScore>();
    Node->WorldContextObject = WorldContextObject;
    Node->ScoreString = Score;
    Node->Sort = ScoreSort;
    Node->Table = TableID;
    Node->GuestName = Guest;
    Node->ExtraScoreData = ExtraData;
    return Node;
}

void UAddScore::Activate()
{
    if(!Super::Validate())
        return;

    if(Sort == 0 || ScoreString == "" || (!GetGameJolt()->IsLoggedIn() && GuestName == ""))
    {
        Failure.Broadcast(EGJErrors::ParametersInvalidOrUnset);
        return;
    }

    FScriptDelegate funcDelegate;
    funcDelegate.BindUFunction(this, "Callback");

    FString BaseURL = "/scores/add/?";
    if(!GetGameJolt()->IsLoggedIn())
        BaseURL += "&guest=" + FGenericPlatformHttp::UrlEncode(GuestName);
    if(Table != 0)
        BaseURL += "&table_id=" + FString::FromInt(Table);
    if(ExtraScoreData != "")
        BaseURL += "&extra_data=" + FGenericPlatformHttp::UrlEncode(ExtraScoreData);
    BaseURL += "&score=" + FGenericPlatformHttp::UrlEncode(ScoreString) + "&sort=" + FString::FromInt(Sort);
    FieldData = UJsonData::GetRequest(CreateURL(BaseURL));
    FieldData->OnGetResult.AddUnique(funcDelegate);
}

void UAddScore::Callback(const bool bSuccess, UJsonData* JSON)
{
    if(!Super::VerifyResponse(bSuccess, JSON))
        return;

    Success.Broadcast(EGJErrors::None);
}