// Copyright by Nick Lamprecht (2020-2023)


#include "GetServerTime.h"

void UGetServerTime::Activate()
{
    if(!Super::Validate())
        return;
    FScriptDelegate funcDelegate;
    funcDelegate.BindUFunction(this, "Callback");
    FieldData = UJsonData::GetRequest(UGameJolt::CreateURL("/time/?"));
    FieldData->OnGetResult.AddUnique(funcDelegate);
}

void UGetServerTime::Callback(const bool bSuccess, UJsonData* JSON)
{
    if(!Super::VerifyResponse(bSuccess, JSON))
        return;

    FServerTime Time = FServerTime(
        response->GetInt("timestamp"),
        response->GetString("timezone"),
        response->GetInt("year"),
        response->GetInt("month"),
        response->GetInt("day"),
        response->GetInt("hour"),
        response->GetInt("minute"),
        response->GetInt("second")
    );
    Success.Broadcast(EGJErrors::None, Time);
}