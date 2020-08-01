// Copyright by Free2Play-Entertainment (2020)


#include "Remove.h"
#include "GenericPlatform/GenericPlatformHttp.h"

URemove* URemove::RemoveData(UGameJolt* GJAPI, EGJDataStore Scope, const FString Key)
{
    URemove* DataStoreNode = NewObject<URemove>();
    DataStoreNode->GameJolt = GJAPI;
    DataStoreNode->Filter = Scope;
    DataStoreNode->DataKey = Key;
    return DataStoreNode;
}

void URemove::Activate()
{
    if(!Super::Validate())
    {
        Failure.Broadcast();
        return;
    }
    FScriptDelegate funcDelegate;
    funcDelegate.BindUFunction(this, "Callback");

    FString BaseURL = "/data-store/remove/?";

    BaseURL += "&key=" + FGenericPlatformHttp::UrlEncode(DataKey);
    FieldData = UJsonData::GetRequest(UGameJolt::CreateURL(BaseURL, GameJolt, Filter == EGJDataStore::user ? true : false));
    FieldData->OnGetResult.AddUnique(funcDelegate);
}

void URemove::Callback(const bool bSuccess, UJsonData* JSON)
{
    Super::Callback(bSuccess, JSON);
    if(!bResponseValid)
    {
        Failure.Broadcast();
        return;
    }
    Success.Broadcast();
}