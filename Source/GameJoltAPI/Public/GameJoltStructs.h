// Copyright by Nick Lamprecht (2020-2023)

#pragma once

#include "CoreMinimal.h"
#include "GameJoltEnums.h"
#include "GameJoltStructs.generated.h"

/* Contains all available information about a user */
USTRUCT(BlueprintType)
struct FUserInfo
{
	GENERATED_BODY()

	/* The ID of the user. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameJoltAPI")
	int32 UserID = 0;

	/* The type of user. Can be 'User', 'Developer', 'Moderator', or 'Administrator'. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameJoltAPI")
	EGJUserType UserType;

	/* The user's username. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameJoltAPI")
	FString UserName;

	/* The URL of the user's avatar. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameJoltAPI")
	FString AvatarURL;

	/* How long ago the user signed up. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameJoltAPI")
	FString SignedUp;

	/* How long ago the user was last logged in. Will be Online Now if the user is currently online. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameJoltAPI")
	FString LastLoggedIn;

	/* Active if the user is still a member of the site. Banned if they've been banned. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameJoltAPI")
	FString Status;

	/* The user's display name. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameJoltAPI")
	FString DisplayName;

	/* The user's website (or empty string if not specified) */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameJoltAPI")
	FString Website;

	/* The user's profile markdown description. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameJoltAPI")
	FString Description;

	FUserInfo(): UserType()
	{
	}

	FUserInfo(const int32 ID, const EGJUserType Type, const FString Name, const FString URL, const FString Date, const FString Login, const FString State, const FString Display, const FString Site, const FString ProfileDescription)
	{
		UserID = ID;
		UserType = Type;
		UserName = Name;
		AvatarURL = URL;
		SignedUp = Date;
		LastLoggedIn = Login;
		Status = State;
		DisplayName = Display;
		Website = Site;
		Description = ProfileDescription;
	}
};

/* Contains all information about a trophy */
USTRUCT(BlueprintType)
struct FTrophyInfo
{
	GENERATED_BODY()

	/* The ID of the trophy. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameJoltAPI")
	int32 ID = 0;

	/* The title of the trophy on the site. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameJoltAPI")
	FString Name;

	/* The trophy description text. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameJoltAPI")
	FString Description;

	/* The difficulty of the trophy */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameJoltAPI")
	EGJTrophyDifficulty Difficulty;

	/* The URL of the trophy's thumbnail image. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameJoltAPI")
	FString ImageURL;

	/* Whether the current user has achieved the trophy */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameJoltAPI")
	bool bAchieved = false;

	/* Date/time when the trophy was achieved by the user */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameJoltAPI")
	FString Timestamp;

	FTrophyInfo(): Difficulty()
	{
	}

	FTrophyInfo(const int32 id, const FString name, const FString description, const EGJTrophyDifficulty difficulty, const FString imageURL)
	{
		ID = id;
		Name = name;
		Description = description;
		Difficulty = difficulty;
		ImageURL = imageURL;
	}
};

/* Contains all information about an entry in a scoreboard */
USTRUCT(BlueprintType)
struct FScoreInfo
{
	GENERATED_BODY()

	/* The score string. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameJoltAPI")
	FString ScoreString;

	/* The score's numerical sort value. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameJoltAPI")
	int32 ScoreSort = 0;

	/* Any extra data associated with the score. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameJoltAPI")
	FString ExtraData;

	/* If this is a user score, this is the display name for the user. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameJoltAPI")
	FString UserName;

	/* If this is a user score, this is the user's ID. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameJoltAPI")
	int32 UserID = 0;

	/* If this is a guest score, this is the guest's submitted name. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameJoltAPI")
	FString Guest;

	/* Returns when the score was logged by the user. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameJoltAPI")
	FString Stored;

	/* Returns the unix timestamp of when the score was logged by the user. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameJoltAPI")
	int32 StoredTimestamp = 0;
	
	FScoreInfo() {}

	FScoreInfo(const FString scoreString, const int32 scoreSort, const FString extraData, const FString userName, const int32 userID, const FString guest, const FString timestamp, const int32 storedTimestamp)
	{
		ScoreString = scoreString;
		ScoreSort = scoreSort;
		ExtraData = extraData;
		UserName = userName;
		UserID = userID;
		Guest = guest;
		Stored = timestamp;
		StoredTimestamp = storedTimestamp;
	}
};

/* Contains all information about a scoreboard */
USTRUCT(BlueprintType)
struct FScoreTableInfo
{
	GENERATED_BODY()

	/* The ID of the score table. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameJoltAPI")
	int32 ID = 0;

	/* The developer-defined name of the score table. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameJoltAPI")
	FString Name;

	/* The developer-defined description of the score table. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameJoltAPI")
	FString Description;

	/* Whether or not this is the default score table. Scores are submitted to the primary table by default. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameJoltAPI")
	bool Primary = false;

	FScoreTableInfo() {}

	FScoreTableInfo(const int32 tableID, const FString tableName, const FString tableDescription, const bool tablePrimary)
	{
		ID = tableID;
		Name = tableName;
		Description = tableDescription;
		Primary = tablePrimary;
	}
};

/* Contains Server-Time information */
USTRUCT(BlueprintType)
struct FServerTime
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameJoltAPI")
	int32 UnixTimestamp = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameJoltAPI")
	FString Timezone;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameJoltAPI")
	int32 Year = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameJoltAPI")
	int32 Month = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameJoltAPI")
	int32 Day = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameJoltAPI")
	int32 Hour = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameJoltAPI")
	int32 Minute = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameJoltAPI")
	int32 Second = 0;

	FServerTime() {}

	FServerTime(const int32 unix, const FString TZ, const int32 year, const int32 month, const int32 day, const int32 hour, const int32 minute, const int32 second)
	{
		UnixTimestamp = unix;
		Timezone = TZ;
		Year = year;
		Month = month;
		Day = day;
		Hour = hour;
		Minute = minute;
		Second = second;
	}
};
