
# Usage

You'll find short examples for some ways of using the plugin on this page. Here are lists with all types added by the plugin:

- [Async Actions](api/async-actions.md)
- [Classes](api/classes.md)
- [Enums](api/enums.md)
- [Structs](api/structs.md)
- [Subsystem](api/subsystem.md)

## Initialization

***See [Readme](../README.md#blueprints) or [Advanced Usage](#overwrite-default-settings)***

---

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

You can overwrite the API-Version (default is `v1_2`) using the advanced options in the `Setup` / `Initialize` function.
Additionally you can overwrite the address of the API-Server (default is `https://api.gamejolt.com/api/game/`). It can point to any spec-compliant server.

![Unreal Engine Blueprint Graph](https://user-images.githubusercontent.com/27819706/214300611-ae989f6f-977b-4f0f-a387-08d4dc9eb2eb.png)

### Getting the Server Time

<!-- todo: text / image -->

### Getting the Friendlist

To get the friendlist of the active user, you can use the "Get Friendlist"-node. It returns an array of user-ids which you can directly wire into the "Fetch Users by ID"-node (see below).

![Unreal Engine Blueprint Graph](https://user-images.githubusercontent.com/27819706/214297809-0c18a655-519a-407b-881a-87a28fe7ddc2.png)

### Fetching User Data

If you want to display more information about some users (e.g. friends in the friendlist) you can use the "Fetch Users by ID" or "Fetch User by Name" nodes. They will return [FGJUserInfo structs](api/structs.md#FGJUserInfo).

![Unreal Engine Blueprint Graph](https://user-images.githubusercontent.com/27819706/214298980-fb390722-7590-4d60-a917-124d753b0226.png)


### Fetching Trophies

If you want to get information about trophies at runtime, you can use the "Fetch Trophies"-node.
You can either get trophies based on defined ids or get all, achieved, or unachieved trophies.
It will return an array of [FGJTrophyInfo structs](api/structs.md#FGJTrophyInfo).

<!-- todo:  image-->
