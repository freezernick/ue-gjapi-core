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

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString ScoreString;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 ScoreSort;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString ExtraData;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString UserName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 UserID;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString Guest;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString UnixTimestamp;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		struct FDateTime TimeStamp;
	
	FScoreInfo()
	{
		TimeStamp = FDateTime::Now();
		ScoreSort = 0;
		UserID = 0;
	}
};

/* Contains all information about a scoreboard */
USTRUCT(BlueprintType)
struct FScoreTableInfo
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 Id;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString Name;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString Description;
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