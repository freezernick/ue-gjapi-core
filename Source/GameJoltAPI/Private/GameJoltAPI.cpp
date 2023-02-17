// Copyright by Nick Lamprecht (2020-2021)

#include "GameJoltAPI.h"
#include "GameJoltSettings.h"
#include "Developer/Settings/Public/ISettingsModule.h"

DEFINE_LOG_CATEGORY(GameJoltAPI);

#define LOCTEXT_NAMESPACE "GameJoltAPI"

void FGameJoltAPIModule::StartupModule()
{
	if (ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
	{
		UGameJoltSettings* PluginSettings = GetMutableDefault<UGameJoltSettings>();

		SettingsModule->RegisterSettings("Project", "Plugins", "GameJoltAPI",
			LOCTEXT("RuntimeSettingsName", "Game Jolt"),
			LOCTEXT("RuntimeSettingsDescription", "Configure the Game Jolt API Plugin"),
			PluginSettings
		);
	}

	UE_LOG(GameJoltAPI, Log, TEXT("Game Jolt API module has been loaded!"));
}

void FGameJoltAPIModule::ShutdownModule()
{
	if (ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
	{
		SettingsModule->UnregisterSettings("Project", "Plugins", "GameJoltAPI");
	}

	UE_LOG(GameJoltAPI, Log, TEXT("Game Jolt API module has been unloaded!"));
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FGameJoltAPIModule, GameJoltAPI)