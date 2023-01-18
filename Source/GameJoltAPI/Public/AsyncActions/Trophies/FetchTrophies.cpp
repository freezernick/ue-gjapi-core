// Copyright by Nick Lamprecht (2020-2023)


#include "FetchTrophies.h"

UFetchTrophies* UFetchTrophies::FetchTrophies(EGJAchievedTrophies TrophyFilter, TArray<int32> TrophyIDs)
{
    UFetchTrophies* TrophyNode = NewObject<UFetchTrophies>();
    TrophyNode->Filter = TrophyFilter;
    TrophyNode->TrophyID = TrophyIDs;
    return TrophyNode;
}

void UFetchTrophies::Activate()
{
    if(!Super::Validate())
        return;

    FScriptDelegate funcDelegate;
    funcDelegate.BindUFunction(this, "Callback");

    FString BaseURL = "/trophies/?";
    if(TrophyID.Num() == 0 && Filter != EGJAchievedTrophies::all)
    {
        BaseURL += FString("achieved=") + (Filter == EGJAchievedTrophies::achieved ? FString("true") : FString("false"));
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
    FieldData = UJsonData::GetRequest(UGameJolt::CreateURL(BaseURL, true));
    FieldData->OnGetResult.AddUnique(funcDelegate);
}

void UFetchTrophies::Callback(const bool bSuccess, UJsonData* JSON)
{
    if(!Super::VerifyResponse(bSuccess, JSON))
        return;

    TArray<UJsonData*> returnArray = response->GetObjectArray("trophies");
    TArray<FTrophyInfo> Trophies = TArray<FTrophyInfo>();
    for(int i = 0; i < returnArray.Num(); i++)
    {
        FString difficultyString = returnArray[i]->GetString("difficulty");
        EGJTrophyDifficulty difficulty = EGJTrophyDifficulty::Bronze;
        if(difficultyString == "Silver")
            difficulty = EGJTrophyDifficulty::Silver;
        else if(difficultyString == "Gold")
            difficulty = EGJTrophyDifficulty::Gold;
        else if(difficultyString == "Platinum")
            difficulty = EGJTrophyDifficulty::Platinum;
        FTrophyInfo Info = FTrophyInfo(
            returnArray[i]->GetInt("id"),
            returnArray[i]->GetString("title"),
            returnArray[i]->GetString("description"),
            difficulty,
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
    Success.Broadcast(EGJErrors::None, Trophies);
}