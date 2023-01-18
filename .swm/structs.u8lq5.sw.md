---
id: u8lq5
title: Structs
file_version: 1.1.1
app_version: 1.0.15
---

## `FGJUserInfo`<swm-token data-swm-token=":Source/GameJoltAPI/Public/GameJoltStructs.h:11:2:2:`struct FGJUserInfo`"/>

Contains all available information about a user.

<br/>

|Type                                                                                                                   |Name                                                                                                                    |Description                                                                                  |
|-----------------------------------------------------------------------------------------------------------------------|------------------------------------------------------------------------------------------------------------------------|---------------------------------------------------------------------------------------------|
|int32                                                                                                                  |`UserID`<swm-token data-swm-token=":Source/GameJoltAPI/Public/GameJoltStructs.h:17:3:3:`	int32 UserID = 0;`"/>          |The ID of the user.                                                                          |
|`EGJUserType`<swm-token data-swm-token=":Source/GameJoltAPI/Public/GameJoltStructs.h:21:1:1:`	EGJUserType UserType;`"/>|`UserType`<swm-token data-swm-token=":Source/GameJoltAPI/Public/GameJoltStructs.h:21:3:3:`	EGJUserType UserType;`"/>    |The type of user. Can be 'User', 'Developer', 'Moderator', or 'Administrator'.               |
|FString                                                                                                                |UserName                                                                                                                |The user's username.                                                                         |
|FString                                                                                                                |`AvatarURL`<swm-token data-swm-token=":Source/GameJoltAPI/Public/GameJoltStructs.h:29:3:3:`	FString AvatarURL;`"/>      |The URL of the user's avatar.                                                                |
|FString                                                                                                                |`SignedUp`<swm-token data-swm-token=":Source/GameJoltAPI/Public/GameJoltStructs.h:33:3:3:`	FString SignedUp;`"/>        |How long ago the user signed up.                                                             |
|FString                                                                                                                |`LastLoggedIn`<swm-token data-swm-token=":Source/GameJoltAPI/Public/GameJoltStructs.h:37:3:3:`	FString LastLoggedIn;`"/>|How long ago the user was last logged in. Will be Online Now if the user is currently online.|
|FString                                                                                                                |Status                                                                                                                  |Active if the user is still a member of the site. Banned if they've been banned.             |
|FString                                                                                                                |`DisplayName`<swm-token data-swm-token=":Source/GameJoltAPI/Public/GameJoltStructs.h:45:3:3:`	FString DisplayName;`"/>  |The user's display name.                                                                     |
|FString                                                                                                                |Website                                                                                                                 |The user's website (or empty string if not specified).                                       |
|FString                                                                                                                |Description                                                                                                             |The user's profile markdown description.                                                     |

<br/>

## `FGJTrophyInfo`<swm-token data-swm-token=":Source/GameJoltAPI/Public/GameJoltStructs.h:76:2:2:`struct FGJTrophyInfo`"/>

Contains all information about a trophy.

<br/>

|Type   |Name                                                                                                                    |Description                                        |
|-------|------------------------------------------------------------------------------------------------------------------------|---------------------------------------------------|
|int32  |ID                                                                                                                      |The ID of the trophy.                              |
|FString|Name                                                                                                                    |The title of the trophy on the site.               |
|FString|Description                                                                                                             |The trophy description text.                       |
|FString|Difficulty                                                                                                              |Bronze, Silver, Gold, or Platinum.                 |
|FString|`ImageURL`<swm-token data-swm-token=":Source/GameJoltAPI/Public/GameJoltStructs.h:98:3:3:`	FString ImageURL;`"/>        |The URL of the trophy's thumbnail image.           |
|bool   |`bAchieved`<swm-token data-swm-token=":Source/GameJoltAPI/Public/GameJoltStructs.h:102:3:3:`	bool bAchieved = false;`"/>|Whether the current user has achieved the trophy.  |
|FString|Timestamp                                                                                                               |Date/time when the trophy was achieved by the user.|

<br/>

## `FGJScoreInfo`<swm-token data-swm-token=":Source/GameJoltAPI/Public/GameJoltStructs.h:124:2:2:`struct FGJScoreInfo`"/>

Contains all information about an entry in a scoreboard.

<br/>

|Type   |Name                                                                                                               |Description                                                    |
|-------|-------------------------------------------------------------------------------------------------------------------|---------------------------------------------------------------|
|FString|ScoreString                                                                                                        |The score string.                                              |
|int32  |ScoreSort                                                                                                          |The score's numerical sort value.                              |
|FString|`ExtraData`<swm-token data-swm-token=":Source/GameJoltAPI/Public/GameJoltStructs.h:138:3:3:`	FString ExtraData;`"/>|Any extra data associated with the score.                      |
|FString|UserName                                                                                                           |If this is a user score, this is the display name for the user.|
|int32  |`UserID`<swm-token data-swm-token=":Source/GameJoltAPI/Public/GameJoltStructs.h:146:3:3:`	int32 UserID = 0;`"/>    |If this is a user score, this is the user's ID.                |
|FString|Guest                                                                                                              |If this is a guest score, this is the guest's submitted name.  |
|FString|Stored                                                                                                             |When the score was logged by the user / guest.                 |
|int32  |ScoredTimestamp                                                                                                    |The unix timestamp of when the score was logged.               |

<br/>

## `FGJScoreTableInfo`<swm-token data-swm-token=":Source/GameJoltAPI/Public/GameJoltStructs.h:177:2:2:`struct FGJScoreTableInfo`"/>

Contains all information about a scoreboard.

<br/>

|Type   |Name       |Description                                                                                        |
|-------|-----------|---------------------------------------------------------------------------------------------------|
|int32  |ID         |The ID of the scoreboard table.                                                                    |
|FString|Name       |The developer-defined name of the scoreboard table.                                                |
|FString|Description|The developer-defined description of the scoreboard table.                                         |
|bool   |Primary    |Whether this is the default scoreboard table. Scores are submitted to the primary table by default.|

<br/>

## `FGJServerTime`<swm-token data-swm-token=":Source/GameJoltAPI/Public/GameJoltStructs.h:210:2:2:`struct FGJServerTime`"/>

Contains Server-Time information.

<br/>

|Type   |Name                                                                                                                         |Description|
|-------|-----------------------------------------------------------------------------------------------------------------------------|-----------|
|int32  |`UnixTimestamp`<swm-token data-swm-token=":Source/GameJoltAPI/Public/GameJoltStructs.h:215:3:3:`	int32 UnixTimestamp = 0;`"/>|/          |
|FString|Timezone                                                                                                                     |/          |
|int32  |Year                                                                                                                         |/          |
|int32  |Month                                                                                                                        |/          |
|int32  |Day                                                                                                                          |/          |
|int32  |Hour                                                                                                                         |/          |
|int32  |Minute                                                                                                                       |/          |
|int32  |Second                                                                                                                       |/          |

<br/>

<br/>

<br/>

This file was generated by Swimm. [Click here to view it in the app](https://app.swimm.io/repos/Z2l0aHViJTNBJTNBdWUtZ2phcGktY29yZSUzQSUzQWZyZWV6ZXJuaWNr/docs/u8lq5).
