## Users

### Auto-Login

Looks for a .gj-credentials created by the GameJolt Client in order to login the user automatically.

![](images/api/autologin.jpg)

#### Inputs

*None*

#### Outputs

|Name|Type|Description|
|----|----|-----|
|Error|[EGJErrors](#egjerrors)|Can return:
- [Default Cases](#remarks)
- CredentialsInvalid

### Fetch Users

@todo: description

![](images/api/fetchusers.jpg)

#### Inputs

@todo: inputs

#### Outputs

@todo: outputs

### Login

Authenticates the user's information. This should be done before you make any calls for the user, to make sure the user's credentials (username and token) are valid.

![](images/api/login.jpg)

#### Inputs

|Name|Type|Description|
|----|----|-----------|
|UserName|FString|The user's username.|
|UserToken|FString|The user's token.|

#### Outputs

|Name|Type|Description|
|----|----|-----|
|Error|[EGJErrors](#egjerrors)|Can return:
- [Default Cases](#remarks)
- CredentialsInvalid