// Contributed by @RedCraft86

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameJoltSettings.generated.h"

UCLASS(config = Game, defaultconfig)
class UGameJoltSettings : public UObject
{
	GENERATED_BODY()

public:

	UPROPERTY(config, EditAnywhere, Category = "Gamejolt")
		int32 GameID = 0;

	UPROPERTY(config, EditAnywhere, Category = "Gamejolt")
		FString PrivateKey = "Null";

	UPROPERTY(config, EditAnywhere, Category = "Gamejolt|API")
		FString Server = "https://api.gamejolt.com/api/game/";

	UPROPERTY(config, EditAnywhere, Category = "Gamejolt|API")
		FString Version = "v1_2";

	/** Static getter to get the settings object. */
	static FORCEINLINE UGameJoltSettings* Get()
	{
		UGameJoltSettings* Settings = GetMutableDefault<UGameJoltSettings>();
		check(Settings);

		return Settings;
	}

	FString GetServer() const
	{
		return Server.IsEmpty() ? "https://api.gamejolt.com/api/game/" : Server;
	}

	FString GetVersion() const
	{
		return Version.IsEmpty() ? "v1_2" : Version;
	}
};