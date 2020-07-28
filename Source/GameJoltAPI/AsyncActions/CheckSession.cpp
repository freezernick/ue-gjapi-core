// Copyright by Free2Play-Entertainment (2020)


#include "CheckSession.h"

UCheckSession* UCheckSession::CheckSession(UObject* WCO, UGameJolt* GJAPI)
{
    UCheckSession* SessionNode = NewObject<UCheckSession>();
    SessionNode->WorldContextObject = WCO;
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
    FieldData = UJsonFieldData::GetRequest(UGameJolt::CreateURL(("/sessions/check/?"), GameJolt));
    FieldData->OnGetResult.AddUnique(funcDelegate);
}

void UCheckSession::Callback(const bool bSuccess, UJsonFieldData* JSON, const EJSONResult Status)
{
    if(!bSuccess)
    {
        Failure.Broadcast();
        return;
    }

    bool bJsonSuccess = false;
    response = JSON->GetObject("response", bJsonSuccess);
    if(!bJsonSuccess)
    {
        Failure.Broadcast();
        return;
    }

    bJsonSuccess = false;
    bool bResponseSuccess = response->GetBool("success", bJsonSuccess);
    if(!bJsonSuccess)
    {
        Failure.Broadcast();
        return;
    }

    Success.Broadcast(bResponseSuccess);
}