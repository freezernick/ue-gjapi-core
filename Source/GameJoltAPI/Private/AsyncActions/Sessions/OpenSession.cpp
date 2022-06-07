// Copyright by Nick Lamprecht (2020-2023)


#include "AsyncActions/Sessions/OpenSession.h"

void UOpenSession::Activate()
{
    if(!Super::Validate())
        return;
    FScriptDelegate funcDelegate;
    funcDelegate.BindUFunction(this, "Callback");
    FieldData = UJsonData::GetRequest(CreateURL("/sessions/open/?"));
    FieldData->OnGetResult.AddUnique(funcDelegate);
}

void UOpenSession::Callback(const bool bSuccess, UJsonData* JSON)
{
    if(!Super::VerifyResponse(bSuccess, JSON))
        return;

    Success.Broadcast(EGJErrors::None);
}