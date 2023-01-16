// Copyright by Nick Lamprecht (2020-2023)


#include "GetKeys.h"
#include "GenericPlatform/GenericPlatformHttp.h"

UGetKeys* UGetKeys::GetKeys(EGJDataStore Scope, FString pattern)
{
    UGetKeys* DataStoreNode = NewObject<UGetKeys>();
    DataStoreNode->Filter = Scope;
    DataStoreNode->Pattern = pattern;
    return DataStoreNode;
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
    
    FieldData = UJsonData::GetRequest(UGameJolt::CreateURL(BaseURL, Filter == EGJDataStore::user ? true : false));
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