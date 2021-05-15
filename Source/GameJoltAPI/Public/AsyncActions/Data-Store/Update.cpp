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

#if ENGINE_MINOR_VERSION >= 19
    const UEnum* EnumPtr = FindObject<UEnum>(ANY_PACKAGE, TEXT("EGJDataOperation"), true);
#endif
    BaseURL += "&key=" + FGenericPlatformHttp::UrlEncode(DataKey) + "&value=" + FGenericPlatformHttp::UrlEncode(DataValue) + "&operation=" +
#if ENGINE_MINOR_VERSION > 20
    StaticEnum<EGJDataOperation>()->GetValueAsString(DataOperation).RightChop(18);
#else
    *EnumPtr->GetDisplayNameTextByIndex((int32) DataOperation).ToString();
#endif
    FieldData = UJsonData::GetRequest(UGameJolt::CreateURL(BaseURL, Filter == EGJDataStore::user ? true : false));
    FieldData->OnGetResult.AddUnique(funcDelegate);
}

void UUpdate::Callback(const bool bSuccess, UJsonData* JSON)
{
    if(!Super::VerifyResponse(bSuccess, JSON))
        return;
    Success.Broadcast(response->GetString("data"));
}