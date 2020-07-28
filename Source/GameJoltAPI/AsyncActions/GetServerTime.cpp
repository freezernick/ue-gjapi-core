// Copyright by Free2Play-Entertainment (2020)


#include "GetServerTime.h"

UGetServerTime* UGetServerTime::GetServerTime(UObject* WCO, UGameJolt* GJAPI)
{
    UGetServerTime* TimeNode = NewObject<UGetServerTime>();
    TimeNode->WorldContextObject = WCO;
    TimeNode->GameJolt = GJAPI;
    return TimeNode;
}

void UGetServerTime::Activate()
{
    if(!Super::Validate())
    {
        Failure.Broadcast();
        return;
    }
    FScriptDelegate funcDelegate;
    funcDelegate.BindUFunction(this, "Callback");
    FieldData = UJsonFieldData::GetRequest(UGameJolt::CreateURL(("/time/?"), GameJolt));
    FieldData->OnGetResult.AddUnique(funcDelegate);
}

void UGetServerTime::Callback(const bool bSuccess, UJsonFieldData* JSON, const EJSONResult Status)
{
    Super::Callback(bSuccess, JSON, Status);
    if(!bResponseValid)
    {
        Failure.Broadcast();
        return;
    }

    bool bTimeSuccess = false;
    FServerTime Time = FServerTime(
        response->GetInt("timestamp", bTimeSuccess),
        response->GetString("timezone", bTimeSuccess),
        response->GetInt("year", bTimeSuccess),
        response->GetInt("month", bTimeSuccess),
        response->GetInt("day", bTimeSuccess),
        response->GetInt("hour", bTimeSuccess),
        response->GetInt("minute", bTimeSuccess),
        response->GetInt("second", bTimeSuccess)
    );
    Success.Broadcast(Time);
}