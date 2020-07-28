// Copyright by Free2Play-Entertainment (2020)


#include "GetFriendlist.h"

UGetFriendlist* UGetFriendlist::GetFriendlist(UObject* WCO, UGameJolt* GJAPI)
{
    UGetFriendlist* SessionNode = NewObject<UGetFriendlist>();
    SessionNode->WorldContextObject = WCO;
    SessionNode->GameJolt = GJAPI;
    return SessionNode;
}

void UGetFriendlist::Activate()
{
    if(!Super::Validate())
    {
        Failure.Broadcast();
        return;
    }
    FScriptDelegate funcDelegate;
    funcDelegate.BindUFunction(this, "Callback");
    FieldData = UJsonFieldData::GetRequest(UGameJolt::CreateURL(("/friends/?"), GameJolt));
    FieldData->OnGetResult.AddUnique(funcDelegate);
}

void UGetFriendlist::Callback(const bool bSuccess, UJsonFieldData* JSON, const EJSONResult Status)
{
    Super::Callback(bSuccess, JSON, Status);
    if(!bResponseValid)
    {
        Failure.Broadcast();
        return;
    }

    bool bJsonSuccess = false;
    TArray<UJsonFieldData*> returnArray = response->GetObjectArray("friends", bJsonSuccess);
    if(!bJsonSuccess)
    {
        Failure.Broadcast();
        return;
    }
	TArray<int32> Friendlist;
	for(int i = 0; i < returnArray.Num(); i++)
        Friendlist.Add(returnArray[i]->GetInt("friend_id", bJsonSuccess));
    Success.Broadcast(Friendlist);
}