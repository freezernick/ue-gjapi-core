// Copyright by Free2Play-Entertainment (2020)


#include "GetTables.h"

void UGetTables::Activate()
{
    if(!Super::Validate())
    {
        Failure.Broadcast();
        return;
    }

    FScriptDelegate funcDelegate;
    funcDelegate.BindUFunction(this, "Callback");
    FieldData = UJsonData::GetRequest(UGameJolt::CreateURL("/scores/tables/?", false));
    FieldData->OnGetResult.AddUnique(funcDelegate);
}

void UGetTables::Callback(const bool bSuccess, UJsonData* JSON)
{
    Super::Callback(bSuccess, JSON);
    if(!bResponseValid)
    {
        Failure.Broadcast();
        return;
    }

    TArray<UJsonData*> returnArray = response->GetObjectArray("tables");
    TArray<FScoreTableInfo> Tables = TArray<FScoreTableInfo>();
    for(int i = 0; i < returnArray.Num(); i++)
    {
        Tables.Add(FScoreTableInfo(
            returnArray[i]->GetInt("id"),
            returnArray[i]->GetString("name"),
            returnArray[i]->GetString("description"),
            returnArray[i]->GetBool("primary")
        ));
    }
    Success.Broadcast(Tables);
}