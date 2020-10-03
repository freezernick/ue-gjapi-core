// Copyright by Free2Play-Entertainment (2020)


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
    {
        Failure.Broadcast();
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
    Super::Callback(bSuccess, JSON);
    if(!bResponseValid)
    {
        Failure.Broadcast();
        return;
    }

    FString Data = response->GetString("data");
    if(Data == "")
    {
        Failure.Broadcast();
        return;
    }
    Success.Broadcast(Data);
}