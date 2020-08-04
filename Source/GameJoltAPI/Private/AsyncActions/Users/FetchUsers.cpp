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

    FieldData = UJsonData::GetRequest(UGameJolt::CreateURL(BaseURL, GameJolt, false));
    FieldData->OnGetResult.AddUnique(funcDelegate);
}

void UFetchUsers::Callback(const bool bSuccess, UJsonData* JSON)
{
    Super::Callback(bSuccess, JSON);
    if(!bResponseValid)
    {
        Failure.Broadcast();
        return;
    }

    TArray<UJsonData*> users = response->GetObjectArray("users");
    TArray<FUserInfo> UserInfo = TArray<FUserInfo>();
    for (int i = 0; i< users.Num(); i++)
	{
        UserInfo.Add(FUserInfo(
            users[i]->GetInt("id"),
            users[i]->GetString("type"),
            users[i]->GetString("username"),
            users[i]->GetString("avatar_url"),
            users[i]->GetString("signed_up"),
            users[i]->GetString("last_logged_in"),
            users[i]->GetString("status"),
            users[i]->GetString("developer_name"),
            users[i]->GetString("developer_website"),
            users[i]->GetString("developer_description")
        ));
	}
    Success.Broadcast(UserInfo);
}