// Copyright by Nick Lamprecht (2020-2023)


#include "AsyncActions/Sessions/PingSession.h"

UPingSession* UPingSession::PingSession(UObject* WorldContextObject, EGJSessionStatus SessionStatus)
{
    UPingSession* Node = NewObject<UPingSession>();
    Node->WorldContextObject = WorldContextObject;
    Node->Status = SessionStatus;
    return Node;
}

void UPingSession::Activate()
{
    if(!Super::Validate())
        return;
    FScriptDelegate funcDelegate;
    funcDelegate.BindUFunction(this, "Callback");
    FieldData = UJsonData::GetRequest(CreateURL("/sessions/ping/?status=" + (Status == EGJSessionStatus::active ? FString("active") : FString("idle"))));
    FieldData->OnGetResult.AddUnique(funcDelegate);
}

void UPingSession::Callback(const bool bSuccess, UJsonData* JSON)
{
    if(!Super::VerifyResponse(bSuccess, JSON))
        return;

    Success.Broadcast(EGJErrors::None);
}