// Copyright by Free2Play-Entertainment (2020)


#include "Set.h"
#include "GenericPlatform/GenericPlatformHttp.h"

USet* USet::SetData(UGameJolt* GJAPI, EGJDataStore Scope, const FString Key, const FString Data)
{
    USet* DataStoreNode = NewObject<USet>();
    DataStoreNode->GameJolt = GJAPI;
    DataStoreNode->Filter = Scope;
    DataStoreNode->DataKey = Key;
    DataStoreNode->DataValue = Data;
    return DataStoreNode;
}

void USet::Activate()
{
    if(!Super::Validate())
    {
        Failure.Broadcast();
        return;
    }
    FScriptDelegate funcDelegate;
    funcDelegate.BindUFunction(this, "Callback");

    FString BaseURL = "/data-store/set/?";

    BaseURL += "&key=" + DataKey + "&data=" + DataValue;
    FieldData = UJsonFieldData::GetRequest(UGameJolt::CreateURL(BaseURL, GameJolt, Filter == EGJDataStore::user ? true : false));
    FieldData->OnGetResult.AddUnique(funcDelegate);
}

void USet::Callback(const bool bSuccess, UJsonFieldData* JSON, const EJSONResult Status)
{
    Super::Callback(bSuccess, JSON, Status);
    if(!bResponseValid)
    {
        Failure.Broadcast();
        return;
    }
    Success.Broadcast();
}