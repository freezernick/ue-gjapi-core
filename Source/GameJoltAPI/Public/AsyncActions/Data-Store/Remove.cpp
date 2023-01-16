// Copyright by Nick Lamprecht (2020-2023)


#include "Remove.h"
#include "GenericPlatform/GenericPlatformHttp.h"

URemove* URemove::RemoveData(EGJDataStore Scope, const FString Key)
{
    URemove* DataStoreNode = NewObject<URemove>();
    DataStoreNode->Filter = Scope;
    DataStoreNode->DataKey = Key;
    return DataStoreNode;
}

void URemove::Activate()
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

    FString BaseURL = "/data-store/remove/?";

    BaseURL += "&key=" + FGenericPlatformHttp::UrlEncode(DataKey);
    FieldData = UJsonData::GetRequest(UGameJolt::CreateURL(BaseURL, Filter == EGJDataStore::user ? true : false));
    FieldData->OnGetResult.AddUnique(funcDelegate);
}

void URemove::Callback(const bool bSuccess, UJsonData* JSON)
{
    if(!Super::VerifyResponse(bSuccess, JSON))
        return;
    Success.Broadcast(EGJErrors::None);
}