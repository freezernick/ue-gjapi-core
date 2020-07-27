// Copyright by Free2Play-Entertainment (2020)


#include "GetServerTime.h"
#include "Misc/DateTime.h"

UGetServerTime* UGetServerTime::GetServerTime(UObject* WCO, UGameJolt* GJAPI)
{
    UGetServerTime* TimeNode = NewObject<UGetServerTime>();
    TimeNode->WorldContextObject = WCO;
    TimeNode->GameJolt = GJAPI;
    return TimeNode;
}

void UGetServerTime::Activate()
{
    Super::Activate();
    FScriptDelegate funcDelegate;
    funcDelegate.BindUFunction(this, "Callback");
    FieldData = UJsonFieldData::GetRequest(UGameJolt::CreateURL(("/time/?"), GameJolt));
    FieldData->OnGetResult.AddUnique(funcDelegate);
}

void UGetServerTime::Callback(const bool bSuccess, UJsonFieldData* JSON, const EJSONResult Status)
{
    UE_LOG(LogTemp, Error, TEXT("Callback"));
    if(!bSuccess)
    {
        Failure.Broadcast();
        return;
    }
    bool bJsonSuccess = false;
    UJsonFieldData* response = JSON->GetObject("response", bJsonSuccess);
    if(!bJsonSuccess)
    {
        Failure.Broadcast();
        return;
    }

    bJsonSuccess = false;
    bool bTimeSuccess = response->GetBool("success", bJsonSuccess);
    if(!bJsonSuccess || (bJsonSuccess && !bTimeSuccess))
    {
        Failure.Broadcast();
        return;
    }
    bTimeSuccess = false;
    FDateTime Time = FDateTime::FromUnixTimestamp(response->GetInt("timestamp", bTimeSuccess));
    Success.Broadcast(Time);
}