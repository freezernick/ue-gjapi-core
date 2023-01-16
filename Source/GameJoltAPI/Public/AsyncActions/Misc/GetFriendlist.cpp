// Copyright by Nick Lamprecht (2020-2023)


#include "GetFriendlist.h"

void UGetFriendlist::Activate()
{
    if(!Super::Validate())
        return;
    FScriptDelegate funcDelegate;
    funcDelegate.BindUFunction(this, "Callback");
    FieldData = UJsonData::GetRequest(UGameJolt::CreateURL("/friends/?"));
    FieldData->OnGetResult.AddUnique(funcDelegate);
}

void UGetFriendlist::Callback(const bool bSuccess, UJsonData* JSON)
{
    if(!Super::VerifyResponse(bSuccess, JSON))
        return;

    TArray<UJsonData*> returnArray = response->GetObjectArray("friends");

	TArray<int32> Friendlist;
	for(int i = 0; i < returnArray.Num(); i++)
        Friendlist.Add(returnArray[i]->GetInt("friend_id"));
    Success.Broadcast(EGJErrors::None, Friendlist);
}