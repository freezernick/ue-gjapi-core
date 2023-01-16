// Copyright by Nick Lamprecht (2020-2023)


#include "GetTables.h"

void UGetTables::Activate()
{
    if(!Super::Validate())
        return;

    FScriptDelegate funcDelegate;
    funcDelegate.BindUFunction(this, "Callback");
    FieldData = UJsonData::GetRequest(UGameJolt::CreateURL("/scores/tables/?", false));
    FieldData->OnGetResult.AddUnique(funcDelegate);
}

void UGetTables::Callback(const bool bSuccess, UJsonData* JSON)
{
    if(!Super::VerifyResponse(bSuccess, JSON))
        return;

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
    Success.Broadcast(EGJErrors::None, Tables);
}