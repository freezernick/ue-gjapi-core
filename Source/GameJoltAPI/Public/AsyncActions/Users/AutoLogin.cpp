// Copyright by Free2Play-Entertainment (2020)


#include "AutoLogin.h"
#include "Misc/Paths.h"
#include "Misc/FileHelper.h"

void UAutoLogin::Activate()
{
    if(!Super::Validate() || !FPaths::FileExists(FPaths::Combine(FPaths::RootDir(), TEXT(".gj-credentials"))))
    {
        Failure.Broadcast();
        return;
    }
    FScriptDelegate funcDelegate;
    funcDelegate.BindUFunction(this, "Callback");
    TArray<FString> strings;
	FFileHelper::LoadFileToStringArray(strings, *FPaths::Combine(FPaths::RootDir(), TEXT(".gj-credentials")));
    Name = strings[1];
    Token = strings[2];
    FieldData = UJsonData::GetRequest(UGameJolt::CreateURL(("users/auth/?username=" + Name + "&user_token=" + Token)));
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

    UGameJolt::Get()->Login(Name, Token);
    Success.Broadcast();
}