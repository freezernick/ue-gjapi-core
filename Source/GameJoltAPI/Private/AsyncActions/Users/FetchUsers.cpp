// Copyright by Nick Lamprecht (2020-2023)


#include "AsyncActions/Users/FetchUsers.h"

UFetchUsers* UFetchUsers::FetchUsers_ID(UObject* WorldContextObject, TArray<int32> UserIDs)
{
    UFetchUsers* Node = NewObject<UFetchUsers>();
    Node->WorldContextObject = WorldContextObject;
    Node->IDs = UserIDs;
    return Node;
}

UFetchUsers* UFetchUsers::FetchUsers_Name(UObject* WorldContextObject, const FString UserName)
{
    UFetchUsers* Node = NewObject<UFetchUsers>();
    Node->WorldContextObject = WorldContextObject;
    Node->Name = UserName;
    return Node;
}

void UFetchUsers::Activate()
{
    if(!Super::Validate())
        return;
    if(Name == "" && IDs.Num() == 0)
    {
        Failure.Broadcast(EGJErrors::ParametersInvalidOrUnset);
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

    FieldData = UJsonData::GetRequest(CreateURL(BaseURL, false));
    FieldData->OnGetResult.AddUnique(funcDelegate);
}

void UFetchUsers::Callback(const bool bSuccess, UJsonData* JSON)
{
    if(!Super::VerifyResponse(bSuccess, JSON))
        return;

    TArray<UJsonData*> users = response->GetObjectArray("users");
    TArray<FGJUserInfo> UserInfo = TArray<FGJUserInfo>();
    for (int i = 0; i< users.Num(); i++)
	{
        FString UserType = users[i]->GetString("type");
        EGJUserType Type = EGJUserType::User;
        if(UserType == "User")
            Type = EGJUserType::User;
        else if(UserType == "Developer")
            Type = EGJUserType::Developer;
        else if(UserType == "Moderator")
            Type = EGJUserType::Moderator;
        else if(UserType == "Administrator")
            Type = EGJUserType::Administrator;
        UserInfo.Add(FGJUserInfo(
            users[i]->GetInt("id"),
            Type,
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
    Success.Broadcast(EGJErrors::None, UserInfo);
}
