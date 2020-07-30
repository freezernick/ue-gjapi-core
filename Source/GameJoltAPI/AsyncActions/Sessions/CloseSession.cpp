// Copyright by Free2Play-Entertainment (2020)


#include "CloseSession.h"

UCloseSession* UCloseSession::CloseSession(UGameJolt* GJAPI)
{
    UCloseSession* SessionNode = NewObject<UCloseSession>();
    SessionNode->GameJolt = GJAPI;
    return SessionNode;
}

void UCloseSession::Activate()
{
    if(!Super::Validate())
    {
        Failure.Broadcast();
        return;
    }
    FScriptDelegate funcDelegate;
    funcDelegate.BindUFunction(this, "Callback");
    FieldData = UJsonFieldData::GetRequest(UGameJolt::CreateURL(("/sessions/close/?"), GameJolt));
    FieldData->OnGetResult.AddUnique(funcDelegate);
}

void UCloseSession::Callback(const bool bSuccess, UJsonFieldData* JSON, const EJSONResult Status)
{
    Super::Callback(bSuccess, JSON, Status);
    if(!bResponseValid)
    {
        Failure.Broadcast();
        return;
    }

    Success.Broadcast();
}