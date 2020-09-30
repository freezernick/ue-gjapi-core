// Copyright by Free2Play-Entertainment (2020)


#include "AutoLogin.h"
#include "Misc/Paths.h"
#include "Misc/FileHelper.h"

UAutoLogin* UAutoLogin::AutoLogin(UGameJolt* GJAPI)
{
    UAutoLogin* LoginNode = NewObject<UAutoLogin>();
    LoginNode->GameJolt = GJAPI;
    return LoginNode;
}

void UAutoLogin::Activate()
{
    if(!Super::Validate() || !FPaths::FileExists(FPaths::Combine(FPaths::ProjectDir(), TEXT(".gj-credentials"))))
    {
        Failure.Broadcast();
        return;
    }
    FScriptDelegate funcDelegate;
    funcDelegate.BindUFunction(this, "Callback");
    TArray<FString> strings;
	FFileHelper::LoadFileToStringArray(strings, *FPaths::Combine(FPaths::ProjectDir(), TEXT(".gj-credentials")));
    Name = strings[1];
    Token = strings[2];
    FieldData = UJsonData::GetRequest(UGameJolt::CreateURL(("users/auth/?username=" + Name + "&user_token=" + Token), GameJolt));
    FieldData->OnGetResult.AddUnique(funcDelegate);
}

void UAutoLogin::Callback(const bool bSuccess, UJsonData* JSON)
{
    Super::Callback(bSuccess, JSON);
    if(!bResponseValid)
    {
        Failure.Broadcast();
        return;
    }

    GameJolt->Login(Name, Token);
    Success.Broadcast();
}