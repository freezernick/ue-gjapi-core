// Copyright by Free2Play-Entertainment (2020)


#include "OpenSession.h"

UOpenSession* UOpenSession::OpenSession(UObject* WCO, UGameJolt* GJAPI)
{
    UOpenSession* SessionNode = NewObject<UOpenSession>();
    SessionNode->WorldContextObject = WCO;
    SessionNode->GameJolt = GJAPI;
    return SessionNode;
}

void UOpenSession::Activate()
{
    if(!Super::Validate())
    {
        Failure.Broadcast();
        return;
    }
    FScriptDelegate funcDelegate;
    funcDelegate.BindUFunction(this, "Callback");
    FieldData = UJsonFieldData::GetRequest(UGameJolt::CreateURL(("/sessions/open/?"), GameJolt));
    FieldData->OnGetResult.AddUnique(funcDelegate);
}

void UOpenSession::Callback(const bool bSuccess, UJsonFieldData* JSON, const EJSONResult Status)
{
    Super::Callback(bSuccess, JSON, Status);
    if(!bResponseValid)
    {
        Failure.Broadcast();
        return;
    }

    Success.Broadcast();
}