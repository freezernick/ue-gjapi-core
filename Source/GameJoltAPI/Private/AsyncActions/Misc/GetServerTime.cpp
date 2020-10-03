// Copyright by Free2Play-Entertainment (2020)


#include "GetServerTime.h"

void UGetServerTime::Activate()
{
    if(!Super::Validate())
    {
        Failure.Broadcast();
        return;
    }
    FScriptDelegate funcDelegate;
    funcDelegate.BindUFunction(this, "Callback");
    FieldData = UJsonData::GetRequest(UGameJolt::CreateURL("/time/?"));
    FieldData->OnGetResult.AddUnique(funcDelegate);
}

void UGetServerTime::Callback(const bool bSuccess, UJsonData* JSON)
{
    Super::Callback(bSuccess, JSON);
    if(!bResponseValid)
    {
        Failure.Broadcast();
        return;
    }

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
    Success.Broadcast(Time);
}