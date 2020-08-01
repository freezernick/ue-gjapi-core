// Copyright by Free2Play-Entertainment (2020)


#include "GetFriendlist.h"

UGetFriendlist* UGetFriendlist::GetFriendlist(UGameJolt* GJAPI)
{
    UGetFriendlist* SessionNode = NewObject<UGetFriendlist>();
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
    FieldData = UJsonData::GetRequest(UGameJolt::CreateURL(("/friends/?"), GameJolt));
    FieldData->OnGetResult.AddUnique(funcDelegate);
}

void UGetFriendlist::Callback(const bool bSuccess, UJsonData* JSON)
{
    Super::Callback(bSuccess, JSON);
    if(!bResponseValid)
    {
        Failure.Broadcast();
        return;
    }

    TArray<UJsonData*> returnArray = response->GetObjectArray("friends");
    if(returnArray.Num() == 0)
    {
        Failure.Broadcast();
        return;
    }
	TArray<int32> Friendlist;
	for(int i = 0; i < returnArray.Num(); i++)
        Friendlist.Add(returnArray[i]->GetInt("friend_id"));
    Success.Broadcast(Friendlist);
}