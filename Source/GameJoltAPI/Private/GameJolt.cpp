// Copyright by Nick Lamprecht (2020-2021)

#include "GameJolt.h"
#include "GameJoltSubsystem.h"
#include "Kismet/GameplayStatics.h"

void UGameJolt::Initialize(UObject* WCO, const int32 Game_ID, const FString Private_Key, const FString Server, const FString Version)
{
    UGameJolt::GetGameJolt(WCO)->Setup(Game_ID, Private_Key, Server, Version);
}

void UGameJolt::Logout(UObject* WCO)
{
    UGameJolt::GetGameJolt(WCO)->Logout();
}

UGameJoltSubsystem* UGameJolt::GetGameJolt(UObject* WCO)
{
    return UGameplayStatics::GetGameInstance(WCO)->GetSubsystem<UGameJoltSubsystem>();
}

bool UGameJolt::IsLoggedIn(UObject* WCO)
{
    return GetGameJolt(WCO)->IsLoggedIn();
}

FString UGameJolt::GetPrivateKey(UObject* WCO)
{
    return GetGameJolt(WCO)->GetPrivateKey();
}

int32 UGameJolt::GetGameID(UObject* WCO)
{
    return GetGameJolt(WCO)->GetGameID();
}

FString UGameJolt::GetUsername(UObject* WCO)
{
    return GetGameJolt(WCO)->GetUsername();
}