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
    FieldData = UJsonFieldData::GetRequest(UGameJolt::CreateURL(BaseURL, GameJolt, Filter == EGJDataStore::user ? true : false));
    FieldData->OnGetResult.AddUnique(funcDelegate);
}

void URemove::Callback(const bool bSuccess, UJsonFieldData* JSON, const EJSONResult Status)
{
    Super::Callback(bSuccess, JSON, Status);
    if(!bResponseValid)
    {
        Failure.Broadcast();
        return;
    }
    Success.Broadcast();
}