// Copyright by Free2Play-Entertainment (2020)


#include "CheckSession.h"

UCheckSession* UCheckSession::CheckSession(UGameJolt* GJAPI)
{
    UCheckSession* SessionNode = NewObject<UCheckSession>();
    SessionNode->GameJolt = GJAPI;
    return SessionNode;
}

void UCheckSession::Activate()
{
    if(!Super::Validate())
    {
        Failure.Broadcast();
        return;
    }
    FScriptDelegate funcDelegate;
    funcDelegate.BindUFunction(this, "Callback");
    FieldData = UJsonData::GetRequest(UGameJolt::CreateURL(("/sessions/check/?"), GameJolt));
    FieldData->OnGetResult.AddUnique(funcDelegate);
}

void UCheckSession::Callback(const bool bSuccess, UJsonData* JSON)
{
    if(!bSuccess)
    {
        Failure.Broadcast();
        return;
    }

    response = JSON->GetObject("response");
    if(!response)
    {
        Failure.Broadcast();
        return;
    }

    bool bResponseSuccess = response->GetBool("success");
    Success.Broadcast(bResponseSuccess);
}