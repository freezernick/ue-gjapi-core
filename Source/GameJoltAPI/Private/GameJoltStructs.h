// Copyright by Free2Play-Entertainment (2020)

#pragma once

#include "CoreMinimal.h"
#include "GameJoltStructs.generated.h"

/* Contains all available information about a user */
USTRUCT(BlueprintType)
struct FUserInfo
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 UserID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString UserType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString UserName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString AvatarURL;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString SignedUp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString LastLoggedIn;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Status;
};

/* Contains all information about a trophy */
USTRUCT(BlueprintType)
struct FTrophyInfo
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Trophy_ID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Description;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Difficulty;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString image_url;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString achieved;
};

/* Contains all information about an entry in a scoreboard */
USTRUCT(BlueprintType)
struct FScoreInfo
{
	GENERATED_BODY()

	/* The score string. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString ScoreString;

	/* The score's numerical sort value. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 ScoreSort;

	/* Any extra data associated with the score. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString ExtraData;

	/* If this is a user score, this is the display name for the user. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString UserName;

	/* If this is a user score, this is the user's ID. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 UserID;

	/* If this is a guest score, this is the guest's submitted name. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Guest;

	/* Returns when the score was logged by the user. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Stored;

	/* Returns the unix timestamp of when the score was logged by the user. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 StoredTimestamp;
	
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
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Id;

	/* The developer-defined name of the score table. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Name;

	/* The developer-defined description of the score table. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Description;

	/* Whether or not this is the default score table. Scores are submitted to the primary table by default. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Primary;

};

/* Contains Server-Time information */
USTRUCT(BlueprintType)
struct FServerTime
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 UnixTimestamp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Timezone;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Year;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Month;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Day;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Hour;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Minute;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Second;

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