## FUserInfo

Contains all available information about a user.

|Type|Name|Description|
|-----|-----|------|
|int32|UserID|The ID of the user.|
|EGJUserType|UserType|The type of user. Can be 'User', 'Developer', 'Moderator', or 'Administrator'.|
|FString|UserName|The user's username.|
|FString|AvatarURL|The URL of the user's avatar.|
|FString|SignedUp|How long ago the user signed up.|
|FString|LastLoggedIn|How long ago the user was last logged in. Will be Online Now if the user is currently online.|
|FString|Status|Active if the user is still a member of the site. Banned if they've been banned.|
|FString|DisplayName|The user's display name.|
|FString|Website|The user's website (or empty string if not specified).|
|FString|Description|The user's profile markdown description.|

## FTrophyInfo

Contains all information about a trophy.

|Type|Name|Description|
|-----|-----|------|
|int32|ID|The ID of the trophy.|
|FString|Name|The title of the trophy on the site.|
|FString|Description|The trophy description text.|
|FString|Difficulty|Bronze, Silver, Gold, or Platinum.|
|FString|ImageURL|The URL of the trophy's thumbnail image.|
|bool|bAchieved|Whether the current user has achieved the trophy.|
|FString|Timestamp|Date/time when the trophy was achieved by the user.|

## FScoreInfo

Contains all information about an entry in a scoreboard.

|Type|Name|Description|
|-----|-----|------|
|FString|ScoreString|The score srting.|
|int32|ScoreSort|The score's numerical sort value.|
|FString|ExtraData|Any extra data associated with the score.|
|FString|UserName|If this is a user score, this is the display name for the user.|
|int32|UserID|If this is a user score, this is the user's ID.|
|FString|Guest|If this is a guest score, this is the guest's submitted name.|
|FString|Stored|When the score was logged by the user / guest.|
|int32|ScoredTimestamp|The unix timestamp of when the score was logged.|

## FScoreTableInfo

Contains all information about a scoreboard.

|Type|Name|Description|
|-----|-----|------|
|int32|ID|The ID of the scoreboard table.|
|FString|Name|The developer-defined name of the scoreboard table.|
|FString|Description|The developer-defined description of the scoreboard table.|
|bool|Primary|Whether this is the default scoreboard table. Scores are submitted to the primary table by default.|

## FServerTime

Contains Server-Time information.

|Type|Name|Description|
|-----|-----|------|
|int32|UnixTimestamp|/|
|FString|Timezone|/|
|int32|Year|/|
|int32|Month|/|
|int32|Day|/|
|int32|Hour|/|
|int32|Minute|/|
|int32|Second|/|