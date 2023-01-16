// Copyright by Nick Lamprecht (2020-2023)


#include "AsyncActions/Sessions/CloseSession.h"

void UCloseSession::Activate()
{
    if(!Super::Validate())
        return;
    FScriptDelegate funcDelegate;
    funcDelegate.BindUFunction(this, "Callback");
    FieldData = UJsonData::GetRequest(CreateURL("/sessions/close/?"));
    FieldData->OnGetResult.AddUnique(funcDelegate);
}

void UCloseSession::Callback(const bool bSuccess, UJsonData* JSON)
{
    if(!Super::VerifyResponse(bSuccess, JSON))
        return;

    Success.Broadcast(EGJErrors::None);
}