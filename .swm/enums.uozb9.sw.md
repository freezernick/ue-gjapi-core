---
id: uozb9
title: Enums
file_version: 1.1.1
app_version: 1.0.15
---

## `EGJAchievedTrophies`<swm-token data-swm-token=":Source/GameJoltAPI/Public/GameJoltEnums.h:9:4:4:`enum class EGJAchievedTrophies : uint8`"/>

A filter used to fetch trophies.

<br/>

|Value     |DisplayName           |
|----------|----------------------|
|all       |All Trophies          |
|achieved  |User Achieved Trophies|
|unachieved|Unachieved Trophies   |

<br/>

## `EGJSessionStatus`<swm-token data-swm-token=":Source/GameJoltAPI/Public/GameJoltEnums.h:18:4:4:`enum class EGJSessionStatus : uint8`"/>

Represents the state of a session.

<br/>

|Value |DisplayName|
|------|-----------|
|active|Active     |
|idle  |Idle       |

<br/>

## `EGJDataStore`<swm-token data-swm-token=":Source/GameJoltAPI/Public/GameJoltEnums.h:26:4:4:`enum class EGJDataStore : uint8`"/>

Represents the scope of a data-store action.

<br/>

|Value |DisplayName|
|------|-----------|
|global|Global     |
|user  |User       |

<br/>

## `EGJDataOperation`<swm-token data-swm-token=":Source/GameJoltAPI/Public/GameJoltEnums.h:34:4:4:`enum class EGJDataOperation : uint8`"/>

Represents possible operations to perform with stored data

<br/>

|Value    |DisplayName|
|---------|-----------|
|add      |Add        |
|substract|Substract  |
|multiply |Multiply   |
|divide   |Divide     |
|append   |Append     |
|prepend  |Prepend    |

<br/>

## `EGJScoreFilter`<swm-token data-swm-token=":Source/GameJoltAPI/Public/GameJoltEnums.h:46:4:4:`enum class EGJScoreFilter : uint8`"/>

A filter used to fetch high scores.

<br/>

|Value|DisplayName               |
|-----|--------------------------|
|all  |All Scores                |
|guest|Scores of a guest         |
|user |Scores of the current user|

<br/>

## `EGJUserType`<swm-token data-swm-token=":Source/GameJoltAPI/Public/GameJoltEnums.h:55:4:4:`enum class EGJUserType : uint8`"/>

Represents the type of a user.

<br/>

|Value / DisplayName|
|-------------------|
|User               |
|Developer          |
|Moderator          |
|Administrator      |

<br/>

## `EGJTrophyDifficulty`<swm-token data-swm-token=":Source/GameJoltAPI/Public/GameJoltEnums.h:65:4:4:`enum class EGJTrophyDifficulty : uint8`"/>

Represents the difficulty of a trophy.

<br/>

|Value / DisplayName|
|-------------------|
|Bronze             |
|Silver             |
|Gold               |
|Platinum           |

<br/>

## `EGJErrors`<swm-token data-swm-token=":Source/GameJoltAPI/Public/GameJoltEnums.h:74:4:4:`enum class EGJErrors : uint8`"/>

All errors that could occur at runtime.

_You don't have to check every case (or any) for every node. Each node can only ever return a subset of these cases. Check the corresponding API-Reference._

<br/>

|Value                                                                                                                                                                                                                |DisplayName                                       |
|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|--------------------------------------------------|
|None                                                                                                                                                                                                                 |/                                                 |
|`UnknownError`<swm-token data-swm-token=":Source/GameJoltAPI/Public/GameJoltEnums.h:77:1:1:`    UnknownError UMETA(DisplayName = &quot;An unknown error on the plugin&#39;s side has occured.&quot;),`"/>            |An unknown error on the plugin's side has occured.|
|`UnknownError_Server`<swm-token data-swm-token=":Source/GameJoltAPI/Public/GameJoltEnums.h:78:1:1:`    UnknownError_Server UMETA(DisplayName = &quot;An unknown error on GameJolt&#39;s side has occured.&quot;),`"/>|An unknown error on GameJolt's side has occured.  |
|`GameIDUnset`<swm-token data-swm-token=":Source/GameJoltAPI/Public/GameJoltEnums.h:79:1:1:`    GameIDUnset,`"/>                                                                                                      |/                                                 |
|`GameIDInvalid`<swm-token data-swm-token=":Source/GameJoltAPI/Public/GameJoltEnums.h:80:1:1:`    GameIDInvalid,`"/>                                                                                                  |/                                                 |
|`PrivateKeyUnset`<swm-token data-swm-token=":Source/GameJoltAPI/Public/GameJoltEnums.h:81:1:1:`    PrivateKeyUnset,`"/>                                                                                              |/                                                 |
|`ParametersInvalidOrUnset`<swm-token data-swm-token=":Source/GameJoltAPI/Public/GameJoltEnums.h:82:1:1:`    ParametersInvalidOrUnset,`"/>                                                                            |/                                                 |
|`ResponseInvalid`<swm-token data-swm-token=":Source/GameJoltAPI/Public/GameJoltEnums.h:83:1:1:`    ResponseInvalid,`"/>                                                                                              |/                                                 |
|`RequestFailed`<swm-token data-swm-token=":Source/GameJoltAPI/Public/GameJoltEnums.h:84:1:1:`    RequestFailed,`"/>                                                                                                  |/                                                 |
|`CredentialsInvalid`<swm-token data-swm-token=":Source/GameJoltAPI/Public/GameJoltEnums.h:85:1:1:`    CredentialsInvalid,`"/>                                                                                        |/                                                 |
|`RestrictedKey`<swm-token data-swm-token=":Source/GameJoltAPI/Public/GameJoltEnums.h:86:1:1:`    RestrictedKey,`"/>                                                                                                  |/                                                 |
|`KeyNotFound`<swm-token data-swm-token=":Source/GameJoltAPI/Public/GameJoltEnums.h:87:1:1:`    KeyNotFound,`"/>                                                                                                      |/                                                 |
|`OperationFailed`<swm-token data-swm-token=":Source/GameJoltAPI/Public/GameJoltEnums.h:88:1:1:`    OperationFailed,`"/>                                                                                              |/                                                 |
|`SignatureInvalid`<swm-token data-swm-token=":Source/GameJoltAPI/Public/GameJoltEnums.h:89:1:1:`    SignatureInvalid,`"/>                                                                                            |/                                                 |
|`InvalidTrophyID`<swm-token data-swm-token=":Source/GameJoltAPI/Public/GameJoltEnums.h:90:1:1:`    InvalidTrophyID,`"/>                                                                                              |/                                                 |
|`TrophyNotAchieved`<swm-token data-swm-token=":Source/GameJoltAPI/Public/GameJoltEnums.h:91:1:1:`    TrophyNotAchieved,`"/>                                                                                          |/                                                 |
|`TrophyAlreadyAchieved`<swm-token data-swm-token=":Source/GameJoltAPI/Public/GameJoltEnums.h:92:1:1:`    TrophyAlreadyAchieved,`"/>                                                                                  |/                                                 |
|`GuestsNotAllowed`<swm-token data-swm-token=":Source/GameJoltAPI/Public/GameJoltEnums.h:93:1:1:`    GuestsNotAllowed,`"/>                                                                                            |/                                                 |
|`NoSession`<swm-token data-swm-token=":Source/GameJoltAPI/Public/GameJoltEnums.h:94:1:1:`    NoSession,`"/>                                                                                                          |/                                                 |
|`CredentialsNotFound`<swm-token data-swm-token=":Source/GameJoltAPI/Public/GameJoltEnums.h:95:1:1:`    CredentialsNotFound`"/>                                                                                       |/                                                 |

<br/>

### Remarks

**All** nodes _can_ return the following cases:

*   None (Success)
    
*   `UnknownError`<swm-token data-swm-token=":Source/GameJoltAPI/Public/GameJoltEnums.h:77:1:1:`    UnknownError UMETA(DisplayName = &quot;An unknown error on the plugin&#39;s side has occured.&quot;),`"/>
    
*   `UnknownError_Server`<swm-token data-swm-token=":Source/GameJoltAPI/Public/GameJoltEnums.h:78:1:1:`    UnknownError_Server UMETA(DisplayName = &quot;An unknown error on GameJolt&#39;s side has occured.&quot;),`"/>
    
*   `GameIDUnset`<swm-token data-swm-token=":Source/GameJoltAPI/Public/GameJoltEnums.h:79:1:1:`    GameIDUnset,`"/>
    
*   `GameIDInvalid`<swm-token data-swm-token=":Source/GameJoltAPI/Public/GameJoltEnums.h:80:1:1:`    GameIDInvalid,`"/>
    
*   `PrivateKeyUnset`<swm-token data-swm-token=":Source/GameJoltAPI/Public/GameJoltEnums.h:81:1:1:`    PrivateKeyUnset,`"/>
    
*   `ResponseInvalid`<swm-token data-swm-token=":Source/GameJoltAPI/Public/GameJoltEnums.h:83:1:1:`    ResponseInvalid,`"/>
    
*   `RequestFailed`<swm-token data-swm-token=":Source/GameJoltAPI/Public/GameJoltEnums.h:84:1:1:`    RequestFailed,`"/>
    
*   `SignatureInvalid`<swm-token data-swm-token=":Source/GameJoltAPI/Public/GameJoltEnums.h:89:1:1:`    SignatureInvalid,`"/>
    

Additionally each node _can_ return _some_ other cases.

<br/>

This file was generated by Swimm. [Click here to view it in the app](https://app.swimm.io/repos/Z2l0aHViJTNBJTNBdWUtZ2phcGktY29yZSUzQSUzQWZyZWV6ZXJuaWNr/docs/uozb9).
