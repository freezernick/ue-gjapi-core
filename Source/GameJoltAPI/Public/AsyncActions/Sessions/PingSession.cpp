// Copyright by Nick Lamprecht (2020-2023)


#include "PingSession.h"

UPingSession* UPingSession::PingSession(EGJSessionStatus SessionStatus)
{
    UPingSession* SessionNode = NewObject<UPingSession>();
    SessionNode->Status = SessionStatus;
    return SessionNode;
}

void UPingSession::Activate()
{
    if(!Super::Validate())
        return;
    FScriptDelegate funcDelegate;
    funcDelegate.BindUFunction(this, "Callback");
    FieldData = UJsonData::GetRequest(UGameJolt::CreateURL("/sessions/ping/?status=" + (Status == EGJSessionStatus::active ? FString("active") : FString("idle"))));
    FieldData->OnGetResult.AddUnique(funcDelegate);
}

void UPingSession::Callback(const bool bSuccess, UJsonData* JSON)
{
    if(!Super::VerifyResponse(bSuccess, JSON))
        return;

    Success.Broadcast(EGJErrors::None);
}