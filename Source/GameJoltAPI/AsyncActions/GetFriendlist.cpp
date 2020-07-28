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
    FieldData = UJsonFieldData::GetRequest(UGameJolt::CreateURL(("/sessions/check/?"), GameJolt));
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
    TArray<int32> Friendlist = response->GetIntArray("friend_id", bJsonSuccess);
    if(!bJsonSuccess)
    {
        Failure.Broadcast();
        return;
    }
    Success.Broadcast(Friendlist);
}