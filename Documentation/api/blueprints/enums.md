## EGJAchievedTrophies

A filter used to fetch trophies.

|Value|DisplayName|
|-----|-----------|
|all|All Trophies|
|achieved|User Achieved Trophies|
|unachieved|Unachieved Trophies|

## EGJSessionStatus

Represents the state of a session.

|Value|DisplayName|
|-----|-----------|
|active|Active|
|idle|Idle|

## EGJDataStore

Represents the scope of a data-store action.

|Value|DisplayName|
|-----|-----------|
|global|Global|
|user|User|

## EGJDataOperation

Represents possible operations to perform with stored data

|Value|DisplayName|
|-----|-----------|
|add|Add|
|substract|Substract|
|multiply|Multiply|
|divide|Divide|
|append|Append|
|prepend|Prepend|

## EGJScoreFilter

A filter used to fetch high-scores.

|Value|DisplayName|
|-----|-----------|
|all|All Scores|
|guest|Scores of a guest|
|user|Scores of the current user|

## EGJUserType

Represents the type of a user.

|Value / DisplayName|
|-----|
|User|
|Developer|
|Moderator|
|Administrator|

## EGJTrophyDifficulty

Represents the difficulty of a trophy.

|Value / DisplayName|
|-----|
|Bronze|
|Silver|
|Gold|
|Platinum|

## EGJErrors

All errors that could occur at runtime.

*You don't have to check every case (or any) for every node. Each node can only ever return a subset of these cases. Check the corresponing API-Reference.*

|Value|DisplayName|
|-----|-----------|
|None| / |
|UnknownError|An unknown error on the plugin's side has occured.|
|UnknownError_Server|An unknown error on GameJolt's side has occured.|
|GameIDUnset| / |
|GameIDInvalid| / |
|PrivateKeyUnset| / |
|ParametersInvalidOrUnset| / |
|ResponseInvalid|/|
|RequestFailed|/|
|CredentialsInvalid|/|
|RestrictedKey|/|
|KeyNotFound|/|
|OperationFailed|/|
|SignatureInvalid|/|
|InvalidTrophyID|/|
|TrophyNotAchieved|/|
|TrophyAlreadyAchieved|/|
|GuestsNotAllowed|/|
|NoSession|/|
|CredentialsNotFound|/|


### Remarks

**All** nodes *can* return the following cases:

- None (Success)
- UnknownError
- UnknownError_Server
- GameIDUnset
- GameIDInvalid
- PrivateKeyUnset
- ResponseInvalid
- RequestFailed
- SignatureInvalid

Additionally each node *can* return *some* other cases. 
