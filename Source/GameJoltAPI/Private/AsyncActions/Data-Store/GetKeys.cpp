// Copyright by Nick Lamprecht (2020-2023)


#include "AsyncActions/Data-Store/GetKeys.h"
#include "GenericPlatform/GenericPlatformHttp.h"

UGetKeys* UGetKeys::GetKeys(UObject* WorldContextObject, EGJDataStore Scope, FString pattern)
{
    UGetKeys* Node = NewObject<UGetKeys>();
    Node->WorldContextObject = WorldContextObject;
    Node->Filter = Scope;
    Node->Pattern = pattern;
    return Node;
}

void UGetKeys::Activate()
{
    if(!Super::Validate())
        return;

    FScriptDelegate funcDelegate;
    funcDelegate.BindUFunction(this, "Callback");

    FString BaseURL = "/data-store/get-keys/?";
    if(Pattern != "")
        BaseURL += "&pattern=" + FGenericPlatformHttp::UrlEncode(Pattern);
    
    FieldData = UJsonData::GetRequest(CreateURL(BaseURL, Filter == EGJDataStore::user ? true : false));
    FieldData->OnGetResult.AddUnique(funcDelegate);
}

void UGetKeys::Callback(const bool bSuccess, UJsonData* JSON)
{
    if(!Super::VerifyResponse(bSuccess, JSON))
        return;

    TArray<UJsonData*> returnArray = response->GetObjectArray("keys");

	TArray<FString> Keys;
	for(int i = 0; i < returnArray.Num(); i++)
        Keys.Add(returnArray[i]->GetString("key"));
    Success.Broadcast(EGJErrors::None, Keys);
}