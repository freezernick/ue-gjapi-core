// Copyright by Free2Play-Entertainment (2020)


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
    {
        Failure.Broadcast();
        return;
    }
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
    Super::Callback(bSuccess, JSON);
    if(!bResponseValid)
    {
        Failure.Broadcast();
        return;
    }

    TArray<UJsonData*> returnArray = response->GetObjectArray("keys");
    if(returnArray.Num() == 0)
    {
        Failure.Broadcast();
        return;
    }
	TArray<FString> Keys;
	for(int i = 0; i < returnArray.Num(); i++)
        Keys.Add(returnArray[i]->GetString("key"));
    Success.Broadcast(Keys);
}