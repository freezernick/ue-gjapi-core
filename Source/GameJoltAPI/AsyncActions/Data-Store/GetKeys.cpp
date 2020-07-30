// Copyright by Free2Play-Entertainment (2020)


#include "GetKeys.h"
#include "GenericPlatform/GenericPlatformHttp.h"

UGetKeys* UGetKeys::GetKeys(UGameJolt* GJAPI, EGJDataStore Scope, FString pattern)
{
    UGetKeys* DataStoreNode = NewObject<UGetKeys>();
    DataStoreNode->GameJolt = GJAPI;
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
    
    FieldData = UJsonFieldData::GetRequest(UGameJolt::CreateURL(BaseURL, GameJolt, Filter == EGJDataStore::user ? true : false));
    FieldData->OnGetResult.AddUnique(funcDelegate);
}

void UGetKeys::Callback(const bool bSuccess, UJsonFieldData* JSON, const EJSONResult Status)
{
    Super::Callback(bSuccess, JSON, Status);
    if(!bResponseValid)
    {
        Failure.Broadcast();
        return;
    }

    bool bJsonSuccess = false;
    TArray<UJsonFieldData*> returnArray = response->GetObjectArray("keys", bJsonSuccess);
    if(!bJsonSuccess)
    {
        Failure.Broadcast();
        return;
    }
	TArray<FString> Keys;
	for(int i = 0; i < returnArray.Num(); i++)
        Keys.Add(returnArray[i]->GetString("key", bJsonSuccess));
    Success.Broadcast(Keys);
}