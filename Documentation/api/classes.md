## UGameJolt

⚠️ This whole class is deprecated and should no longer be used. Please use the [subsystem](subsystem.md) instead.⚠️

__This class serves only as a wrapper for the subsystem for backwards-compatibility__

### Initialize

**Modifiers:** static

Sets required information for all API requests

#### Inputs

|Type|Name|Description / Notes|
|----|----|-----------|
|int32|GameID|The GameID. Can be found in your game's dashboard|
|String|PrivateKey|Your game's private key. Can be found in your game's dashboard|

#### Outputs

*None*

### GetUsername

Returns the username of the currently authenticated user.

*Modifiers:* static

#### Inputs

*None*

#### Outputs

|Type|Name|Description / Notes|
|----|------------|
|String|?||


### GetPrivateKey

Returns the private key.

**Modifiers:** static

#### Inputs

*None*

#### Outputs

|Type|Name|Description / Notes|
|----|------------|
|String|?||

### GetGameID

Returns the GameID.

**Modifiers:** static

#### Inputs

*None*

#### Outputs

|Type|Name|Description / Notes|
|----|------------|
|int32|?||

### IsLoggedIn

Returns whether a user is currently authenticated or not.

**Modifiers:** static

#### Inputs

*None*

#### Outputs

|Type|Name|Description / Notes|
|----|------------|
|bool|?||

### Logout

*This node does not actually interact with the API and is only used to remove any data associated to an authenticated user from the subsystem*

#### Inputs

*None*

#### Outputs

*None*
