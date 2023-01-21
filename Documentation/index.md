
# Usage

You'll find short examples for some ways of using the plugin on this page. Here are lists with all types added by the plugin:

- [Async Actions](api/async-actions.md)
- [Classes](api/classes.md)
- [Enums](api/enums.md)
- [Structs](api/structs.md)
- [Subsystem](api/subsystem.md)

## Initialization

***See [Readme](../README.md#blueprints)***

---

Before you call any other node of the plugin you want to call the "Setup"-node. There you can set your game's ID and private key.
Optionally you can overwrite the API-version (default is v1_2) used and the address of the API (default is `https://api.gamejolt.com/api/game/`).  

![Unreal Engine Blueprint Graph](https://user-images.githubusercontent.com/27819706/98440576-d35d8880-20f9-11eb-8601-1fd1330098db.png)

## Logging In

### Auto-Login

The GameJolt-Client places a file with the user's credentials in the game directory on launch. If you want to utilize this feature, you can call [AutoLogin](api/async-actions.md#auto-login)

![Unreal Engine Blueprint Graph](https://user-images.githubusercontent.com/27819706/213868347-9426f1b6-2490-4346-b44a-3667ca21b79c.png)

### Login

If you don't want the user to be logged-in automatically or the user doesn't use the GameJolt-Client, you have to use the default username/token-based login for authentication.

![Unreal Engine Blueprint Graph](https://user-images.githubusercontent.com/27819706/213869557-916844f3-6b65-4150-b116-3b67b5e99869.png)

## Sessions

Basically you want to create a new session using the "Open Session"-node. If it was created successfuly you want to ping it every 30 to 120 seconds using a timer. Call the "Close Session"-node when you want the session to end.

<!-- todo:  image-->

You can check the session status for the current user with the "Check Session"-node.

<!-- todo:  image-->

## Scoreboards / High-Scores

<!-- todo:  image-->

## Achievements / Trophies

### Reward Trophy

To reward a trophy you have to call the "Reward Trophy"-node and use the id of the trophy you want to give to the user.

<!-- todo:  image-->

### Remove Trophy

If you want to remove an already rewarded trophy, call the "Remove Trophy"-node.

<!-- todo:  image-->

## Data-Storage

<!-- todo: text -->

### Set

<!-- todo: text / image -->

### Update

<!-- todo: text / image -->

### Fetch

<!-- todo: text / image -->

### Get Keys

<!-- todo: text / image -->

### Remove

<!-- todo: text / image -->

## Advanced

### Overwrite Default Settings

<!-- todo: text / image -->

### Getting the Server Time

<!-- todo: text / image -->

### Getting the Friendlist

To get the friendlist of the active user, you can use the "Get Friendlist"-node. It returns an array of user-ids which you can directly wire into the "Fetch Users by ID"-node (see below).

<!-- todo:  image-->

### Fetching User Data

If you want to display more information about some users (e.g. friends in the friendlist) you can use the "Fetch Users by ID" or "Fetch User by Name" nodes. They will return [FGJUserInfo structs](api/structs.md#FGJUserInfo).

<!-- todo:  image-->

### Fetching Trophies

If you want to get information about trophies at runtime, you can use the "Fetch Trophies"-node.
You can either get trophies based on defined ids or get all, achieved, or unachieved trophies.
It will return an array of [FGJTrophyInfo structs](api/structs.md#FGJTrophyInfo).

<!-- todo:  image-->
