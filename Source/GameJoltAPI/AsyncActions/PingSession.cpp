// Copyright by Free2Play-Entertainment (2020)


#include "PingSession.h"

UPingSession* UPingSession::PingSession(UObject* WCO, UGameJolt* GJAPI)
{
    UPingSession* SessionNode = NewObject<UPingSession>();
    SessionNode->WorldContextObject = WCO;
    SessionNode->GameJolt = GJAPI;
    return SessionNode;
}

void UPingSession::Activate()
{
    if(!Super::Validate())
    {
        Failure.Broadcast();
        return;
    }
    FScriptDelegate funcDelegate;
    funcDelegate.BindUFunction(this, "Callback");
    FieldData = UJsonFieldData::GetRequest(UGameJolt::CreateURL(("/sessions/ping/?"), GameJolt));
    FieldData->OnGetResult.AddUnique(funcDelegate);
}

void UPingSession::Callback(const bool bSuccess, UJsonFieldData* JSON, const EJSONResult Status)
{
    Super::Callback(bSuccess, JSON, Status);
    if(!bResponseValid)
    {
        Failure.Broadcast();
        return;
    }

    Success.Broadcast();
}