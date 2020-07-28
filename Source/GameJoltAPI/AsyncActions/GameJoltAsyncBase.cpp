// Copyright by Free2Play-Entertainment (2020)


#include "GameJoltAsyncBase.h"

void UGameJoltAsyncBase::Activate()
{
}

void UGameJoltAsyncBase::Callback(const bool bSuccess, UJsonFieldData* JSON, const EJSONResult Status)
{
    if(!bSuccess)
    {
        bResponseValid = false;
        return;
    }
    bool bJsonSuccess = false;
    response = JSON->GetObject("response", bJsonSuccess);
    if(!bJsonSuccess)
    {
        bResponseValid = false;
        return;
    }

    bJsonSuccess = false;
    bool bResponseSuccess = response->GetBool("success", bJsonSuccess);
    if(!bJsonSuccess || (bJsonSuccess && !bResponseSuccess))
    {
        bResponseValid = false;
        return;
    }
}