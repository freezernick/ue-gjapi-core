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