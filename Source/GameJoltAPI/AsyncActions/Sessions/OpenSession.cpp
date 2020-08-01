// Copyright by Free2Play-Entertainment (2020)


#include "OpenSession.h"

UOpenSession* UOpenSession::OpenSession(UGameJolt* GJAPI)
{
    UOpenSession* SessionNode = NewObject<UOpenSession>();
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
    FieldData = UJsonData::GetRequest(UGameJolt::CreateURL(("/sessions/open/?"), GameJolt));
    FieldData->OnGetResult.AddUnique(funcDelegate);
}

void UOpenSession::Callback(const bool bSuccess, UJsonData* JSON)
{
    Super::Callback(bSuccess, JSON);
    if(!bResponseValid)
    {
        Failure.Broadcast();
        return;
    }

    Success.Broadcast();
}