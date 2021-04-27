// Copyright by Nick Lamprecht (2020-2021)


#include "Update.h"
#include "GenericPlatform/GenericPlatformHttp.h"

UUpdate* UUpdate::UpdateData(EGJDataStore Scope, const FString Key, const FString Value, EGJDataOperation Operation)
{
    UUpdate* DataStoreNode = NewObject<UUpdate>();
    DataStoreNode->Filter = Scope;
    DataStoreNode->DataKey = Key;
    DataStoreNode->DataValue = Value;
    DataStoreNode->DataOperation = Operation;
    return DataStoreNode;
}

void UUpdate::Activate()
{
    if(!Super::Validate())
        return;
    FScriptDelegate funcDelegate;
    funcDelegate.BindUFunction(this, "Callback");

    FString BaseURL = "/data-store/update/?";

    BaseURL += "&key=" + FGenericPlatformHttp::UrlEncode(DataKey) + "&value=" + FGenericPlatformHttp::UrlEncode(DataValue) + "&operation=" + StaticEnum<EGJDataOperation>()->GetValueAsString(DataOperation).RightChop(18);
    FieldData = UJsonData::GetRequest(UGameJolt::CreateURL(BaseURL, Filter == EGJDataStore::user ? true : false));
    FieldData->OnGetResult.AddUnique(funcDelegate);
}

void UUpdate::Callback(const bool bSuccess, UJsonData* JSON)
{
    if(!Super::VerifyResponse(bSuccess, JSON))
        return;
    Success.Broadcast(response->GetString("data"));
}