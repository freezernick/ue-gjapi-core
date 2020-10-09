// Copyright by Free2Play-Entertainment (2020)


#include "GameJoltAsyncBase.h"

void UGameJoltAsyncBase::Callback(const bool bSuccess, UJsonData* JSON)
{
    if(!bSuccess)
    {
        bResponseValid = false;
        return;
    }
    response = JSON->GetObject("response");
    if(!response)
    {
        bResponseValid = false;
        return;
    }

    bool bResponseSuccess = response->GetBool("success");
    if(!bResponseSuccess)
    {
        bResponseValid = false;
        return;
    }
}