// Copyright by Free2Play-Entertainment (2020)


#include "GameJoltAsyncBase.h"
#include "GameJolt.h"

void UGameJoltAsyncBase::Activate()
{
    if(!WorldContextObject || !GameJolt)
    {
        Failure.Broadcast();
        return;
    }
}