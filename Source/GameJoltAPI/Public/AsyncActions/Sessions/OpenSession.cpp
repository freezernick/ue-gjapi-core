// Copyright by Free2Play-Entertainment (2020)


#include "OpenSession.h"

void UOpenSession::Activate()
{
    if(!Super::Validate())
        return;
    FScriptDelegate funcDelegate;
    funcDelegate.BindUFunction(this, "Callback");
    FieldData = UJsonData::GetRequest(UGameJolt::CreateURL("/sessions/open/?"));
    FieldData->OnGetResult.AddUnique(funcDelegate);
}

void UOpenSession::Callback(const bool bSuccess, UJsonData* JSON)
{
    if(!Super::VerifyResponse(bSuccess, JSON))
        return;

    Success.Broadcast();
}