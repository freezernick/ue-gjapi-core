// Copyright by Free2Play-Entertainment (2020)


#include "GetTables.h"

UGetTables* UGetTables::GetTables(UObject* WCO, UGameJolt* GJAPI)
{
    UGetTables* ScoreNode = NewObject<UGetTables>();
    ScoreNode->WorldContextObject = WCO;
    ScoreNode->GameJolt = GJAPI;
    return ScoreNode;
}

void UGetTables::Activate()
{
    if(!Super::Validate())
    {
        Failure.Broadcast();
        return;
    }

    FScriptDelegate funcDelegate;
    funcDelegate.BindUFunction(this, "Callback");
    FieldData = UJsonFieldData::GetRequest(UGameJolt::CreateURL("/scores/tables/?", GameJolt, false));
    FieldData->OnGetResult.AddUnique(funcDelegate);
}

void UGetTables::Callback(const bool bSuccess, UJsonFieldData* JSON, const EJSONResult Status)
{
    Super::Callback(bSuccess, JSON, Status);
    if(!bResponseValid)
    {
        Failure.Broadcast();
        return;
    }

    bool bJsonSuccess = false;
    TArray<UJsonFieldData*> returnArray = response->GetObjectArray("tables", bJsonSuccess);
    if(!bJsonSuccess)
    {
        Failure.Broadcast();
        return;
    }
    TArray<FScoreTableInfo> Tables = TArray<FScoreTableInfo>();
    for(int i = 0; i < returnArray.Num(); i++)
    {
        Tables.Add(FScoreTableInfo(
            returnArray[i]->GetInt("id", bJsonSuccess),
            returnArray[i]->GetString("name", bJsonSuccess),
            returnArray[i]->GetString("description", bJsonSuccess),
            returnArray[i]->GetBool("primary", bJsonSuccess)
        ));
    }
    Success.Broadcast(Tables);
}