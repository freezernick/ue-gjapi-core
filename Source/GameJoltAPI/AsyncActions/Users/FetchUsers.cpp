// Copyright by Free2Play-Entertainment (2020)


#include "FetchUsers.h"

UFetchUsers* UFetchUsers::FetchUsers_ID(UGameJolt* GJAPI, TArray<int32> UserIDs)
{
    UFetchUsers* UserNode = NewObject<UFetchUsers>();
    UserNode->GameJolt = GJAPI;
    UserNode->IDs = UserIDs;
    return UserNode;
}

UFetchUsers* UFetchUsers::FetchUsers_Name(UGameJolt* GJAPI, const FString UserName)
{
    UFetchUsers* UserNode = NewObject<UFetchUsers>();
    UserNode->GameJolt = GJAPI;
    UserNode->Name = UserName;
    return UserNode;
}

void UFetchUsers::Activate()
{
    if(!Super::Validate())
    {
        Failure.Broadcast();
        return;
    }
    FScriptDelegate funcDelegate;
    funcDelegate.BindUFunction(this, "Callback");
    FString BaseURL = "/users/?";
    if(IDs.Num() > 0)
    {
        BaseURL += "user_id=";
        for(int i = 0; i < IDs.Num(); i++)
        {
            if(i == 0)
                BaseURL += FString::FromInt(IDs[i]);
            else
                BaseURL += "," + FString::FromInt(IDs[i]);
        }
    }
    else
        BaseURL += "username=" + Name;

    FieldData = UJsonFieldData::GetRequest(UGameJolt::CreateURL(BaseURL, GameJolt, false));
    FieldData->OnGetResult.AddUnique(funcDelegate);
}

void UFetchUsers::Callback(const bool bSuccess, UJsonFieldData* JSON, const EJSONResult Status)
{
    Super::Callback(bSuccess, JSON, Status);
    if(!bResponseValid)
    {
        Failure.Broadcast();
        return;
    }

    bool bJsonSuccess = false;
    TArray<UJsonFieldData*> users = response->GetObjectArray("users", bJsonSuccess);
    TArray<FUserInfo> UserInfo = TArray<FUserInfo>();
    for (int i = 0; i< users.Num(); i++)
	{
        UserInfo.Add(FUserInfo(
            users[i]->GetInt("id", bJsonSuccess),
            users[i]->GetString("type", bJsonSuccess),
            users[i]->GetString("username", bJsonSuccess),
            users[i]->GetString("avatar_url", bJsonSuccess),
            users[i]->GetString("signed_up", bJsonSuccess),
            users[i]->GetString("last_logged_in", bJsonSuccess),
            users[i]->GetString("status", bJsonSuccess),
            users[i]->GetString("developer_name", bJsonSuccess),
            users[i]->GetString("developer_website", bJsonSuccess),
            users[i]->GetString("developer_description", bJsonSuccess)
        ));
	}
    Success.Broadcast(UserInfo);
}