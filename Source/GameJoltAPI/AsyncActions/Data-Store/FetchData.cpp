// Copyright by Free2Play-Entertainment (2020)


#include "FetchData.h"
#include "GenericPlatform/GenericPlatformHttp.h"

UFetchData* UFetchData::FetchData(UGameJolt* GJAPI, EGJDataStore Scope, const FString Key)
{
    UFetchData* DataStoreNode = NewObject<UFetchData>();
    DataStoreNode->GameJolt = GJAPI;
    DataStoreNode->Filter = Scope;
    DataStoreNode->DataKey = Key;
    return DataStoreNode;
}

void UFetchData::Activate()
{
    if(!Super::Validate())
    {
        Failure.Broadcast();
        return;
    }
    FScriptDelegate funcDelegate;
    funcDelegate.BindUFunction(this, "Callback");

    FString BaseURL = "/data-store/?key=" + FGenericPlatformHttp::UrlEncode(DataKey);
    FieldData = UJsonFieldData::GetRequest(UGameJolt::CreateURL(BaseURL, GameJolt, Filter == EGJDataStore::user ? true : false));
    FieldData->OnGetResult.AddUnique(funcDelegate);
}

void UFetchData::Callback(const bool bSuccess, UJsonFieldData* JSON, const EJSONResult Status)
{
    Super::Callback(bSuccess, JSON, Status);
    if(!bResponseValid)
    {
        Failure.Broadcast();
        return;
    }

    bool bJsonSuccess = false;
    FString Data = response->GetString("data", bJsonSuccess);
    if(!bJsonSuccess)
    {
        Failure.Broadcast();
        return;
    }
    Success.Broadcast(Data);
}