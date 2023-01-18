---
id: iltnl
title: Release 2.0.0
file_version: 1.1.1
app_version: 1.0.15
---

## Subsystem

<br/>

The prior singleton implementation is replaced with an Unreal-style singleton: a subsystem.

Reference:

*   [https://benui.ca/unreal/subsystem-singleton/](https://benui.ca/unreal/subsystem-singleton/)
    
*   [https://docs.unrealengine.com/5.1/en-US/API/Runtime/Engine/Subsystems/](https://docs.unrealengine.com/5.1/en-US/API/Runtime/Engine/Subsystems/)
<!-- NOTE-swimm-snippet: the lines below link your snippet to Swimm -->
### 📄 Source/GameJoltAPI/Public/GameJoltSubsystem.h
<!-- collapsed -->

```c
1      // Copyright by Nick Lamprecht (2020-2022)
2      
3      #pragma once
4      
5      #include "CoreMinimal.h"
6      #include "Subsystems/GameInstanceSubsystem.h"
7      #include "Kismet/GameplayStatics.h"
8      #include "GameJoltSubsystem.generated.h"
9      
10     /**
11      * 
12      */
13     UCLASS()
14     class GAMEJOLTAPI_API UGameJoltSubsystem : public UGameInstanceSubsystem
15     {
16     	GENERATED_BODY()
17     
18     	FString Server = "";
19     
20         FString Version = "";
21     
22         FString UserName = "";
23     
24         FString UserToken = "";
25     
26         bool bLoggedIn = false;
27     
28         int32 GameID = 0;
29     
30         FString PrivateKey = "";
31     
32         friend class ULogin;
33     
34         friend class UAutoLogin;
35     
36     public:
37     
38     	/**
39          * Sets required information for all API requests
40          * @param Game_ID Required. Can be found in your game's dashboard
41          * @param Private_Key Required. Can be found in your game's dashboard
42          * @param Server Optional. Default is https://api.gamejolt.com/api/game/
43          * @param Version Optional. Default is v1_2
44          */
45     	UFUNCTION(BlueprintCallable, Category = "GameJoltAPI", meta = (AdvancedDisplay="Server, Version", DisplayName="Initialize"))
46         void Setup(const int32 Game_ID, const FString Private_Key, const FString Server = "", const FString Version = "");
47     
48         UFUNCTION(BlueprintPure, Category = "GameJoltAPI")
49         FString GetUsername()
50         {
51             return UserName;
52         }
53     
54         UFUNCTION(BlueprintPure, Category = "GameJoltAPI")
55         FString GetPrivateKey()
56         {
57             return PrivateKey;
58         }
59     
60         UFUNCTION(BlueprintPure, Category = "GameJoltAPI")
61         int32 GetGameID()
62         {
63             return GameID;
64         }
65     
66         UFUNCTION(BlueprintPure, Category = "GameJoltAPI")
67         bool IsLoggedIn()
68         {
69             return bLoggedIn;
70         }
71     
72         void Login(const FString Name, const FString Token);
73     
74         UFUNCTION(BlueprintCallable, Category = "GameJoltAPI")
75         void Logout();
76     
77         FString CreateURL(const FString URL, bool AppendUserInfo = true);
78     
79         friend class ULogin;
80     
81         friend class UAutoLogin;
82     
83     };
```

<br/>

See above.
<!-- NOTE-swimm-snippet: the lines below link your snippet to Swimm -->
### 📄 Source/GameJoltAPI/Private/GameJoltSubsystem.cpp
<!-- collapsed -->

```c++
1      #include "GameJoltSubsystem.h"
2      // Copyright by Nick Lamprecht (2020-2022)
3      
4      #include "GameJoltSubsystem.h"
5      #include "AsyncActions/Users/Login.h"
6      #include "AsyncActions/Users/AutoLogin.h"
7      
8      void UGameJoltSubsystem::Setup(const int32 gameID, const FString privateKey, const FString server, const FString version)
9      {
10         Logout();
11         GameID = gameID;
12         PrivateKey = privateKey;
13         Server = server;
14         Version = version;
15     }
16     
17     void UGameJoltSubsystem::Login(const FString Name, const FString Token)
18     {
19         bLoggedIn = true;
20         UserName = Name;
21         UserToken = Token;
22     }
23     
24     void UGameJoltSubsystem::Logout()
25     {
26         bLoggedIn = false;
27         UserName = "";
28         UserToken = "";
29     }
30     
31     FString UGameJoltSubsystem::CreateURL(const FString URL, bool AppendUserInfo)
32     {
33         FString BaseURL;
34         if(Server == "")
35             BaseURL = TEXT("https://api.gamejolt.com/api/game");
36         else
37             BaseURL = Server;
38         if(Version == "")
39             BaseURL += TEXT("/v1_2");
40         else
41             BaseURL = FPaths::Combine(BaseURL, Version);
42         FPaths::NormalizeDirectoryName(BaseURL);
43         BaseURL = FPaths::Combine(BaseURL, URL + "&game_id=" + FString::FromInt(GameID) + ((bLoggedIn && AppendUserInfo) ? "&username=" + UserName + "&user_token=" + UserToken : ""));
44         return (BaseURL + "&signature=" + FMD5::HashAnsiString(*(BaseURL + PrivateKey)));
45     }
```

<br/>

## Renamed Structs

All structs have been renamed to include a GJ prefix.

<br/>


<!-- NOTE-swimm-snippet: the lines below link your snippet to Swimm -->
### 📄 Source/GameJoltAPI/Public/GameJoltStructs.h
```c
11     struct FGJUserInfo
```

<br/>


<!-- NOTE-swimm-snippet: the lines below link your snippet to Swimm -->
### 📄 Source/GameJoltAPI/Public/GameJoltStructs.h
```c
76     struct FGJTrophyInfo
```

<br/>


<!-- NOTE-swimm-snippet: the lines below link your snippet to Swimm -->
### 📄 Source/GameJoltAPI/Public/GameJoltStructs.h
```c
124    struct FGJScoreInfo
```

<br/>


<!-- NOTE-swimm-snippet: the lines below link your snippet to Swimm -->
### 📄 Source/GameJoltAPI/Public/GameJoltStructs.h
```c
177    struct FGJScoreTableInfo
```

<br/>


<!-- NOTE-swimm-snippet: the lines below link your snippet to Swimm -->
### 📄 Source/GameJoltAPI/Public/GameJoltStructs.h
```c
210    struct FGJServerTime
```

<br/>

Class redirectors have been setup to make migration easier.
<!-- NOTE-swimm-snippet: the lines below link your snippet to Swimm -->
### 📄 Config/DefaultGameJoltAPI.ini
```ini
1      [CoreRedirects]
2      +StructRedirects=(OldName="UserInfo",NewName="GJUserInfo")
3      +StructRedirects=(OldName="TrophyInfo",NewName="GJTrophyInfo")
4      +StructRedirects=(OldName="ScoreInfo",NewName="GJScoreInfo")
5      +StructRedirects=(OldName="ScoreTableInfo",NewName="GJScoreTableInfo")
6      +StructRedirects=(OldName="ServerTime",NewName="GJServerTime")
```

<br/>

## Deprecation

<br/>

Because of the move to a subsystem, everything related to the `UGameJolt`<swm-token data-swm-token=":Source/GameJoltAPI/Public/GameJolt.h:11:4:4:`class GAMEJOLTAPI_API UGameJolt : public UObject`"/> class has been deprecated.
<!-- NOTE-swimm-snippet: the lines below link your snippet to Swimm -->
### 📄 Source/GameJoltAPI/Public/GameJolt.h
<!-- collapsed -->

```c
28         UFUNCTION(BlueprintCallable, Category = "GameJoltAPI", meta = (DeprecatedFunction, DeprecationMessage="Use Setup of the GameJolt-Subsystem instead.", AdvancedDisplay="Server, Version", WorldContext = "WorldContextObject"))
29         static void Initialize(UObject* WorldContextObject, const int32 Game_ID, const FString Private_Key, const FString Server = "", const FString Version = "");
30     
31         UFUNCTION(BlueprintPure, Category = "GameJoltAPI", meta = (WorldContext = "WorldContextObject", DeprecatedFunction, DeprecationMessage="Use GetUsername of the GameJolt-Subsystem instead."))
32         static FString GetUsername(UObject* WorldContextObject);
33     
34         UFUNCTION(BlueprintPure, Category = "GameJoltAPI", meta = (WorldContext = "WorldContextObject", DeprecatedFunction, DeprecationMessage="Use GetPrivateKey of the GameJolt-Subsystem instead."))
35         static FString GetPrivateKey(UObject* WorldContextObject);
36     
37         UFUNCTION(BlueprintPure, Category = "GameJoltAPI", meta = (WorldContext = "WorldContextObject", DeprecatedFunction, DeprecationMessage="Use GetGameID of the GameJolt-Subsystem instead."))
38         static int32 GetGameID(UObject* WorldContextObject);
39     
40         UFUNCTION(BlueprintPure, Category = "GameJoltAPI", meta = (WorldContext = "WorldContextObject", DeprecatedFunction, DeprecationMessage = "Use IsLoggedIn of the GameJolt-Subsystem instead."))
41         static bool IsLoggedIn(UObject* WorldContextObject);
42     
43         UFUNCTION(BlueprintCallable, Category = "GameJoltAPI", meta = (WorldContext = "WorldContextObject", DeprecatedFunction, DeprecationMessage = "Use Logout of the GameJolt-Subsystem instead."))
44         static void Logout(UObject* WorldContextObject);
```

<br/>

## Refactor

<br/>

The constructors of all async-actions have been refactored to be more similar. The reference to the node is always called `Node`<swm-token data-swm-token=":Source/GameJoltAPI/Public/AsyncActions/Misc/GetServerTime.h:26:1:1:`		Node-&gt;WorldContextObject = WorldContextObject;`"/>instead of a class-dependent name.
<!-- NOTE-swimm-snippet: the lines below link your snippet to Swimm -->
### 📄 Source/GameJoltAPI/Public/AsyncActions/Misc/GetServerTime.h
<!-- collapsed -->

```c
23     	static UGetServerTime* GetServerTime(UObject* WorldContextObject)
24     	{
25     		UGetServerTime* Node =  NewObject<UGetServerTime>();
26     		Node->WorldContextObject = WorldContextObject;
27     		return Node;
28     	}
```

<br/>

<br/>

<br/>

This file was generated by Swimm. [Click here to view it in the app](https://app.swimm.io/repos/Z2l0aHViJTNBJTNBdWUtZ2phcGktY29yZSUzQSUzQWZyZWV6ZXJuaWNr/docs/iltnl).
