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

Tries to authentificate a user with the specified credentials.

![](images/api/login.jpg)

#### Inputs

*None*

#### Outputs

|Name|Type|Description|
|----|----|-----|
|Error|[EGJErrors](#egjerrors)|Can return:
- [Default Cases](#remarks)
- CredentialsInvalid