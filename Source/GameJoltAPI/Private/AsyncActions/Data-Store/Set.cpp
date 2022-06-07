// Copyright by Nick Lamprecht (2020-2023)


#include "AsyncActions/Data-Store/Set.h"
#include "GenericPlatform/GenericPlatformHttp.h"

USet* USet::SetData(EGJDataStore Scope, const FString Key, const FString Data)
{
    USet* Node = NewObject<USet>();
    Node->Filter = Scope;
    Node->DataKey = Key;
    Node->DataValue = Data;
    return Node;
}

void USet::Activate()
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

    FString BaseURL = "/data-store/set/?";

    BaseURL += "&key=" + FGenericPlatformHttp::UrlEncode(DataKey) + "&data=" + FGenericPlatformHttp::UrlEncode(DataValue);
    FieldData = UJsonData::GetRequest(UGameJolt::CreateURL(BaseURL, Filter == EGJDataStore::user ? true : false));
    FieldData->OnGetResult.AddUnique(funcDelegate);
}

void USet::Callback(const bool bSuccess, UJsonData* JSON)
{
    if(!Super::VerifyResponse(bSuccess, JSON))
        return;

    Success.Broadcast(EGJErrors::None);
}