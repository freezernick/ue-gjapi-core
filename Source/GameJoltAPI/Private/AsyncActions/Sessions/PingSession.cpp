// Copyright by Free2Play-Entertainment (2020)


#include "PingSession.h"

UPingSession* UPingSession::PingSession(UGameJolt* GJAPI, EGJSessionStatus SessionStatus)
{
    UPingSession* SessionNode = NewObject<UPingSession>();
    SessionNode->GameJolt = GJAPI;
    SessionNode->Status = SessionStatus;
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
    FieldData = UJsonData::GetRequest(UGameJolt::CreateURL(("/sessions/ping/?status=" + (Status == EGJSessionStatus::active ? FString("active") : FString("idle"))), GameJolt));
    FieldData->OnGetResult.AddUnique(funcDelegate);
}

void UPingSession::Callback(const bool bSuccess, UJsonData* JSON)
{
    Super::Callback(bSuccess, JSON);
    if(!bResponseValid)
    {
        Failure.Broadcast();
        return;
    }

    Success.Broadcast();
}