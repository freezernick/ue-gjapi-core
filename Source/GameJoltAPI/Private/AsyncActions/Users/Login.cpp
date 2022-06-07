// Copyright by Nick Lamprecht (2020-2023)


#include "AsyncActions/Users/Login.h"

ULogin* ULogin::Login(UObject* WorldContextObject, const FString UserName, const FString UserToken)
{
    ULogin* Node = NewObject<ULogin>();
    Node->WorldContextObject = WorldContextObject;
    Node->Name = UserName;
    Node->Token = UserToken;
    return Node;
}

void ULogin::Activate()
{
    if(!Super::Validate())
        return;

    if(Name == "" || Token == "")
    {
        Failure.Broadcast(EGJErrors::ParametersInvalidOrUnset);
        return;
    }

    FScriptDelegate funcDelegate;
    funcDelegate.BindUFunction(this, "Callback");
    FieldData = UJsonData::GetRequest(GetGameJolt()->CreateURL("users/auth/?username=" + Name + "&user_token=" + Token));
    FieldData->OnGetResult.AddUnique(funcDelegate);
}

void ULogin::Callback(const bool bSuccess, UJsonData* JSON)
{
    if(!Super::VerifyResponse(bSuccess, JSON))
        return;

    GetGameJolt()->Login(Name, Token);
    Success.Broadcast(EGJErrors::None);
}