// Copyright by Free2Play-Entertainment (2020)


#include "Login.h"
#include "GameJolt.h"

ULogin* ULogin::Login(UObject* WCO, UGameJolt* GJAPI, const FString UserName, const FString UserToken)
{
    ULogin* LoginNode = NewObject<ULogin>();
    LoginNode->WorldContextObject = WCO;
    LoginNode->GameJolt = GJAPI;
    LoginNode->Name = UserName;
    LoginNode->Token = UserToken;
    return LoginNode;
}

void ULogin::Activate()
{
    Super::Activate();
    FScriptDelegate funcDelegate;
    funcDelegate.BindUFunction(this, "Callback");
    FieldData = UJsonFieldData::GetRequest(UGameJolt::CreateURL(("users/auth/?username=" + Name + "&user_token=" + Token), GameJolt));
    FieldData->OnGetResult.AddUnique(funcDelegate);
}

void ULogin::Callback(const bool bSuccess, UJsonFieldData* JSON, const EJSONResult Status)
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
    bool bLoginSuccess = response->GetBool("success", bJsonSuccess);
    if(!bJsonSuccess || (bJsonSuccess && !bLoginSuccess))
    {
        Failure.Broadcast();
        return;
    }

    GameJolt->Login(Name, Token);
    Success.Broadcast();
}