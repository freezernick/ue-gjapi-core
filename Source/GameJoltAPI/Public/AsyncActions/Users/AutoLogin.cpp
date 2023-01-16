// Copyright by Nick Lamprecht (2020-2023)


#include "AutoLogin.h"
#include "Misc/Paths.h"
#include "Misc/FileHelper.h"

void UAutoLogin::Activate()
{
    if(!Super::Validate())
        return;

    if(!FPaths::FileExists(FPaths::Combine(FPaths::RootDir(), TEXT(".gj-credentials"))))
    {
        Failure.Broadcast(EGJErrors::CredentialsNotFound);
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
    if(!Super::VerifyResponse(bSuccess, JSON))
        return;

    UGameJolt::Get().Login(Name, Token);
    Success.Broadcast(EGJErrors::None);
}