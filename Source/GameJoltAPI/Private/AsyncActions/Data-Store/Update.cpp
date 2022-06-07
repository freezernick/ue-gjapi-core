// Copyright by Nick Lamprecht (2020-2023)


#include "AsyncActions/Data-Store/Update.h"
#include "GenericPlatform/GenericPlatformHttp.h"

UUpdate* UUpdate::UpdateData(EGJDataStore Scope, const FString Key, const FString Value, EGJDataOperation Operation)
{
    UUpdate* Node = NewObject<UUpdate>();
    Node->Filter = Scope;
    Node->DataKey = Key;
    Node->DataValue = Value;
    Node->DataOperation = Operation;
    return Node;
}

void UUpdate::Activate()
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
    FString BaseURL = "/data-store/update/?";
    BaseURL += "&key=" + FGenericPlatformHttp::UrlEncode(DataKey) + "&value=" + FGenericPlatformHttp::UrlEncode(DataValue) + "&operation=" +
    StaticEnum<EGJDataOperation>()->GetValueAsString(DataOperation).RightChop(18);
    FieldData = UJsonData::GetRequest(CreateURL(BaseURL, Filter == EGJDataStore::user ? true : false));
    FieldData->OnGetResult.AddUnique(funcDelegate);
}

void UUpdate::Callback(const bool bSuccess, UJsonData* JSON)
{
    if(!Super::VerifyResponse(bSuccess, JSON))
        return;
    Success.Broadcast(EGJErrors::None, response->GetString("data"));
}