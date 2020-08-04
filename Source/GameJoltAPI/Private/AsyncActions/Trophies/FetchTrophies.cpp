// Copyright by Free2Play-Entertainment (2020)


#include "FetchTrophies.h"

UFetchTrophies* UFetchTrophies::FetchTrophies(UGameJolt* GJAPI, EGJAchievedTrophies TrophyFilter, TArray<int32> TrophyIDs)
{
    UFetchTrophies* TrophyNode = NewObject<UFetchTrophies>();
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
    FieldData = UJsonData::GetRequest(UGameJolt::CreateURL(BaseURL, GameJolt, true));
    FieldData->OnGetResult.AddUnique(funcDelegate);
}

void UFetchTrophies::Callback(const bool bSuccess, UJsonData* JSON)
{
    Super::Callback(bSuccess, JSON);
    if(!bResponseValid)
    {
        Failure.Broadcast();
        return;
    }

    TArray<UJsonData*> returnArray = response->GetObjectArray("trophies");
    TArray<FTrophyInfo> Trophies = TArray<FTrophyInfo>();
    for(int i = 0; i < returnArray.Num(); i++)
    {
        FTrophyInfo Info = FTrophyInfo(
            returnArray[i]->GetInt("id"),
            returnArray[i]->GetString("title"),
            returnArray[i]->GetString("description"),
            returnArray[i]->GetString("difficulty"),
            returnArray[i]->GetString("image_url")
        );
        FString AchievedString = returnArray[i]->GetString("achieved");
        if(AchievedString == "false")
        {
            Info.bAchieved = false;
        }
        else
        {
            Info.bAchieved = true;
            Info.Timestamp = AchievedString;
        }
        Trophies.Add(Info);
    }
    Success.Broadcast(Trophies);
}