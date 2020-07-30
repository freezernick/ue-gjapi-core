// Copyright by Free2Play-Entertainment (2020)


#include "FetchTrophies.h"
#include "GenericPlatform/GenericPlatformHttp.h"

UFetchTrophies* UFetchTrophies::FetchTrophies(UObject* WCO, UGameJolt* GJAPI, EGJAchievedTrophies TrophyFilter, TArray<int32> TrophyIDs)
{
    UFetchTrophies* TrophyNode = NewObject<UFetchTrophies>();
    TrophyNode->WorldContextObject = WCO;
    TrophyNode->GameJolt = GJAPI;
    TrophyNode->Filter = TrophyFilter;
    TrophyNode->TrophyID = TrophyIDs;
    return TrophyNode;
}

void UFetchTrophies::Activate()
{
    if(!Super::Validate())
    {
        Failure.Broadcast();
        return;
    }

    FScriptDelegate funcDelegate;
    funcDelegate.BindUFunction(this, "Callback");

    FString BaseURL = "/trophies/?";
    if(TrophyID.Num() == 0 && Filter != EGJAchievedTrophies::all)
    {
        BaseURL += "achieved=" + (Filter == EGJAchievedTrophies::achieved) ? "true" : "false";
    }
    else
    {
        BaseURL += "trophy_id=";
        for(int i = 0; i < TrophyID.Num(); i++)
        {
            BaseURL += FString::FromInt(TrophyID[i]);
            if(i != TrophyID.Num() - 1)
                BaseURL += ",";
        }
    }
    FieldData = UJsonFieldData::GetRequest(UGameJolt::CreateURL(BaseURL, GameJolt, true));
    FieldData->OnGetResult.AddUnique(funcDelegate);
}

void UFetchTrophies::Callback(const bool bSuccess, UJsonFieldData* JSON, const EJSONResult Status)
{
    Super::Callback(bSuccess, JSON, Status);
    if(!bResponseValid)
    {
        Failure.Broadcast();
        return;
    }

    bool bJsonSuccess = false;
    TArray<UJsonFieldData*> returnArray = response->GetObjectArray("trophies", bJsonSuccess);
    if(!bJsonSuccess)
    {
        Failure.Broadcast();
        return;
    }
    TArray<FTrophyInfo> Trophies = TArray<FTrophyInfo>();
    for(int i = 0; i < returnArray.Num(); i++)
    {
        FTrophyInfo Info = FTrophyInfo(
            returnArray[i]->GetInt("id", bJsonSuccess),
            returnArray[i]->GetString("title", bJsonSuccess),
            returnArray[i]->GetString("description", bJsonSuccess),
            returnArray[i]->GetString("difficulty", bJsonSuccess),
            returnArray[i]->GetString("image_url", bJsonSuccess)
        );
        FString AchievedString = returnArray[i]->GetString("achieved", bJsonSuccess);
        if(AchievedString == "false")
        {
            Info.bAchieved = false;
            Info.Timestamp = FDateTime();
        }
        else
        {
            Info.bAchieved = true;
            FDateTime::Parse(AchievedString, Info.Timestamp);
        }
        Trophies.Add(Info);
    }
    Success.Broadcast(Trophies);
}