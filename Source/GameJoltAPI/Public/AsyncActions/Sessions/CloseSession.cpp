// Copyright by Free2Play-Entertainment (2020)


#include "CloseSession.h"

void UCloseSession::Activate()
{
    if(!Super::Validate())
    {
        Failure.Broadcast();
        return;
    }
    FScriptDelegate funcDelegate;
    funcDelegate.BindUFunction(this, "Callback");
    FieldData = UJsonData::GetRequest(UGameJolt::CreateURL("/sessions/close/?"));
    FieldData->OnGetResult.AddUnique(funcDelegate);
}

void UCloseSession::Callback(const bool bSuccess, UJsonData* JSON)
{
    Super::Callback(bSuccess, JSON);
    if(!bResponseValid)
    {
        Failure.Broadcast();
        return;
    }

    Success.Broadcast();
}