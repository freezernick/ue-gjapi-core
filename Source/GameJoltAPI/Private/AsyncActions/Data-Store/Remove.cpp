// Copyright by Nick Lamprecht (2020-2023)


#include "AsyncActions/Data-Store/Remove.h"
#include "GenericPlatform/GenericPlatformHttp.h"

URemove* URemove::RemoveData(UObject* WorldContextObject, EGJDataStore Scope, const FString Key)
{
    URemove* Node = NewObject<URemove>();
    Node->WorldContextObject = WorldContextObject;
    Node->Filter = Scope;
    Node->DataKey = Key;
    return Node;
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
    FieldData = UJsonData::GetRequest(CreateURL(BaseURL, Filter == EGJDataStore::user ? true : false));
    FieldData->OnGetResult.AddUnique(funcDelegate);
}

void URemove::Callback(const bool bSuccess, UJsonData* JSON)
{
    if(!Super::VerifyResponse(bSuccess, JSON))
        return;
    Success.Broadcast(EGJErrors::None);
}