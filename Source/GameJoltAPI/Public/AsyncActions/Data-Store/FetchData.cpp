// Copyright by Nick Lamprecht (2020-2023)


#include "FetchData.h"
#include "GenericPlatform/GenericPlatformHttp.h"

UFetchData* UFetchData::FetchData(EGJDataStore Scope, const FString Key)
{
    UFetchData* DataStoreNode = NewObject<UFetchData>();
    DataStoreNode->Filter = Scope;
    DataStoreNode->DataKey = Key;
    return DataStoreNode;
}

void UFetchData::Activate()
{
    if(!Super::Validate())
        return;

    if(DataKey == "")
    {
        Failure.Broadcast(EGJErrors::ParametersInvalidOrUnset);
        return;
    }

    FScriptDelegate funcDelegate;
    funcDelegate.BindUFunction(this, "Callback");

    FString BaseURL = "/data-store/?key=" + FGenericPlatformHttp::UrlEncode(DataKey);
    FieldData = UJsonData::GetRequest(UGameJolt::CreateURL(BaseURL, Filter == EGJDataStore::user ? true : false));
    FieldData->OnGetResult.AddUnique(funcDelegate);
}

void UFetchData::Callback(const bool bSuccess, UJsonData* JSON)
{
    if(!Super::VerifyResponse(bSuccess, JSON))
        return;

    FString Data = response->GetString("data");
    Success.Broadcast(EGJErrors::None, Data);
}