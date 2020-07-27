// Copyright by Free2Play-Entertainment (2020)


#include "GameJoltAsyncBase.h"
#include "GameJolt.h"

void UGameJoltAsyncBase::Activate()
{
    UE_LOG(LogTemp, Error, TEXT("Activate in GameJolAsyncBase"));
}

void UGameJoltAsyncBase::Callback(const bool bSuccess, UJsonFieldData* JSON, const EJSONResult Status)
{
}