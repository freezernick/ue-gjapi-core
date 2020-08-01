// Copyright by Free2Play-Entertainment (2020)


#include "Update.h"
#include "GenericPlatform/GenericPlatformHttp.h"

UUpdate* UUpdate::UpdateData(UGameJolt* GJAPI, EGJDataStore Scope, const FString Key, const FString Value, EGJDataOperation Operation)
{
    UUpdate* DataStoreNode = NewObject<UUpdate>();
    DataStoreNode->GameJolt = GJAPI;
    DataStoreNode->Filter = Scope;
    DataStoreNode->DataKey = Key;
    DataStoreNode->DataValue = Value;
    DataStoreNode->DataOperation = Operation;
    return DataStoreNode;
}

void UUpdate::Activate()
{
    if(!Super::Validate())
    {
        Failure.Broadcast();
        return;
    }
    FScriptDelegate funcDelegate;
    funcDelegate.BindUFunction(this, "Callback");

    FString BaseURL = "/data-store/update/?";

    BaseURL += "&key=" + FGenericPlatformHttp::UrlEncode(DataKey) + "&value=" + FGenericPlatformHttp::UrlEncode(DataValue) + "&operation=" + StaticEnum<EGJDataOperation>()->GetValueAsString(DataOperation).RightChop(18);
    FieldData = UJsonData::GetRequest(UGameJolt::CreateURL(BaseURL, GameJolt, Filter == EGJDataStore::user ? true : false));
    FieldData->OnGetResult.AddUnique(funcDelegate);
}

void UUpdate::Callback(const bool bSuccess, UJsonData* JSON)
{
    Super::Callback(bSuccess, JSON);
    if(!bResponseValid)
    {
        Failure.Broadcast();
        return;
    }
    Success.Broadcast(response->GetString("data"));
}