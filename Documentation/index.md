

# Usage

You'll find short examples for some ways of using the plugin on this page. Here are lists with all types added by the plugin:

- [Async Actions](api/async-actions.md)
- [Classes](api/classes.md)
- [Enums](api/enums.md)
- [Structs](api/structs.md)
- [Subsystem](api/subsystem.md)


## Initialization & Authentication

Before you call any other node of the plugin you want to call the "Setup"-node. There you can set your game's ID and private key.
Optionally you can overwrite the API-version (default is v1_2) used and the address of the API (default is https://api.gamejolt.com/api/game/).   
![](https://user-images.githubusercontent.com/27819706/98440576-d35d8880-20f9-11eb-8601-1fd1330098db.png)

### Auto-Login

The GameJolt-Client places a file with the user's credentials in the game directory on launch. If you want to utilize this feature, you can call the "Auto Login"-node directly after the initialization node.

![](https://user-images.githubusercontent.com/27819706/98440661-3fd88780-20fa-11eb-9835-d4223ba1a5d4.png)

### Login

If you don't want the user to be logged-in automatically or the user doesn't use the GameJolt-Client, you'll have to use the default username/token-based login.

To do this, you should call the "Login"-node.

![](https://user-images.githubusercontent.com/27819706/98440705-7d3d1500-20fa-11eb-832b-85d8481ff5b5.png)

## Sessions

Basically you want to create a new session using the "Open Session"-node. If it was created successfuly you want to ping it every 30 to 120 seconds using a timer. Call the "Close Session"-node when you want the session to end.

![](https://user-images.githubusercontent.com/27819706/98440456-15d29580-20f9-11eb-9b3a-decdba4a8718.png)

You can check the session status for the current user with the "Check Session"-node.

![](https://user-images.githubusercontent.com/27819706/98440518-71048800-20f9-11eb-82a8-a0e96f56b83c.png)

## Scoreboards / High-Scores

![grafik](https://user-images.githubusercontent.com/27819706/154715295-6d19fa5b-ee46-4a31-a81e-b4b893b26e64.png)


## Achievements / Trophies

To reward a trophy you have to call the "Reward Trophy"-node and use the id of the trophy you want to give to the user.

![](https://user-images.githubusercontent.com/27819706/98440825-57fcd680-20fb-11eb-9093-6e58430bea3a.png)

If you want to remove an already rewarded trophy, call the "Remove Trophy"-node.

![](https://user-images.githubusercontent.com/27819706/98440848-7a8eef80-20fb-11eb-8080-b5f984e9d525.png)

## Data-Storage

## Advanced

### Getting the Friendlist

To get the friendlist of the active user, you can use the "Get Friendlist"-node. It returns an array of user-ids which you can directly wire into the "Fetch Users by ID"-node (see below).

![](https://user-images.githubusercontent.com/27819706/98440803-25eb7480-20fb-11eb-9060-4834c7305052.png)

### Fetching User Data

If you want to display more information about some users (e.g. friends in the friendlist) you can use the "Fetch Users by ID" or "Fetch User by Name" nodes. They will return [FGJUserInfo structs](api/structs.md#FGJUserInfo).

![](https://user-images.githubusercontent.com/27819706/98440755-d7d67100-20fa-11eb-9b8d-161a25c9751c.png)

### Fetching Trophies

If you want to get information about trophies at runtime, you can use the "Fetch Trophies"-node.
You can either get trophies based on defined ids or get all, achieved, or unachieved trophies.
It will return an array of [FGJTrophyInfo structs](api/structs.md#FGJTrophyInfo).

![](https://user-images.githubusercontent.com/27819706/98440870-998d8180-20fb-11eb-938a-d6d196a9fb93.png)
