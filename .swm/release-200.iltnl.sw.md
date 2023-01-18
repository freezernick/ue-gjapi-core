---
id: iltnl
title: Release 2.0.0
file_version: 1.1.1
app_version: 1.0.17
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
7      #include "GameJoltSubsystem.generated.h"
8      
9      /**
10      * 
11      */
12     UCLASS()
13     class GAMEJOLTAPI_API UGameJoltSubsystem : public UGameInstanceSubsystem
14     {
15     	GENERATED_BODY()
16     
17     	FString Server = "";
18     
19         FString Version = "";
20     
21         FString UserName = "";
22     
23         FString UserToken = "";
24     
25         bool bLoggedIn = false;
26     
27         int32 GameID = 0;
28     
29         FString PrivateKey = "";
30     
31         friend class ULogin;
32     
33         friend class UAutoLogin;
34     
35     public:
36     
37     	/**
38          * Sets required information for all API requests
39          * @param Game_ID Required. Can be found in your game's dashboard
40          * @param Private_Key Required. Can be found in your game's dashboard
41          * @param Server Optional. Default is https://api.gamejolt.com/api/game/
42          * @param Version Optional. Default is v1_2
43          */
44     	UFUNCTION(BlueprintCallable, Category = "GameJoltAPI", meta = (AdvancedDisplay="Server, Version", DisplayName="Initialize", WorldContext = "WCO"))
45         static void Setup(UObject* WCO, const int32 Game_ID, const FString Private_Key, const FString Server = "", const FString Version = "");
46         void Setup(const int32 Game_ID, const FString Private_Key, const FString Server = "", const FString Version = "");
47     
48         UFUNCTION(BlueprintPure, Category = "GameJoltAPI", meta=(WorldContext = "WCO"))
49         static FString GetUsername(UObject* WCO);
50         FString GetUsername();
51     
52         UFUNCTION(BlueprintPure, Category = "GameJoltAPI", meta=(WorldContext = "WCO"))
53         static FString GetPrivateKey(UObject* WCO);
54         FString GetPrivateKey();
55     
56         UFUNCTION(BlueprintPure, Category = "GameJoltAPI", meta=(WorldContext = "WCO"))
57         static int32 GetGameID(UObject* WCO);
58         int32 GetGameID();
59     
60         UFUNCTION(BlueprintPure, Category = "GameJoltAPI", meta=(WorldContext = "WCO"))
61         static bool IsLoggedIn(UObject* WCO);
62         bool IsLoggedIn();
63     
64         void Login(const FString Name, const FString Token);
65     
66         UFUNCTION(BlueprintCallable, Category = "GameJoltAPI", meta=(WorldContext = "WCO"))
67         static void Logout(UObject* WCO);
68         void Logout();
69     
70         FString CreateURL(const FString URL, bool AppendUserInfo = true);
71     
72         friend class ULogin;
73     
74         friend class UAutoLogin;
75     
76     };
77     
```

<br/>

See above.
<!-- NOTE-swimm-snippet: the lines below link your snippet to Swimm -->
### 📄 Source/GameJoltAPI/Private/GameJoltSubsystem.cpp
<!-- collapsed -->

```c++
3      #include "GameJoltSubsystem.h"
4      #include "Kismet/GameplayStatics.h"
5      #include "AsyncActions/Users/Login.h"
6      #include "AsyncActions/Users/AutoLogin.h"
7      
8      void UGameJoltSubsystem::Setup(UObject* WCO, const int32 gameID, const FString privateKey, const FString server, const FString version)
9      {
10         return UGameplayStatics::GetGameInstance(WCO)->GetSubsystem<UGameJoltSubsystem>()->Setup(
11             gameID,
12             privateKey,
13             server,
14             version
15         );
16     }
17     
18     void UGameJoltSubsystem::Setup(const int32 gameID, const FString privateKey, const FString server, const FString version)
19     {
20         Logout();
21         GameID = gameID;
22         PrivateKey = privateKey;
23         Server = server;
24         Version = version;
25     }
26     
27     FString UGameJoltSubsystem::GetUsername(UObject* WCO)
28     {
29         return UGameplayStatics::GetGameInstance(WCO)->GetSubsystem<UGameJoltSubsystem>()->GetUsername();
30     }
31     
32     FString UGameJoltSubsystem::GetUsername()
33     {
34         return UserName;
35     }
36     
37     FString UGameJoltSubsystem::GetPrivateKey(UObject* WCO)
38     {
39         return UGameplayStatics::GetGameInstance(WCO)->GetSubsystem<UGameJoltSubsystem>()->GetPrivateKey();
40     }
41     
42     FString UGameJoltSubsystem::GetPrivateKey()
43     {
44         return PrivateKey;
45     }
```

<br/>

### UGameJolt Removal

The `UGameJolt` class has been removed

### Redirects

<br/>

Core Redirects have been setup to make migration easier.
<!-- NOTE-swimm-snippet: the lines below link your snippet to Swimm -->
### 📄 Config/DefaultGameJoltAPI.ini
```ini
1      [CoreRedirects]
2      +ClassRedirects=(OldName="GameJolt",NewName="GameJoltSubsystem")
3      +FunctionRedirects=(OldName="GameJolt.GetUsername",NewName="GameJoltSubsystem.GetUsername")
4      +FunctionRedirects=(OldName="GameJolt.Initialize",NewName="GameJoltSubsystem.Setup")
5      +FunctionRedirects=(OldName="GameJolt.GetPrivateKey",NewName="GameJoltSubsystem.GetPrivateKey")
6      +FunctionRedirects=(OldName="GameJolt.GetGameID",NewName="GameJoltSubsystem.GetGameID")
7      +FunctionRedirects=(OldName="GameJolt.IsLoggedIn",NewName="GameJoltSubsystem.IsLoggedIn")
8      +FunctionRedirects=(OldName="GameJolt.Logout",NewName="GameJoltSubsystem.Logout")
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

Core redirects have been setup to make migration easier.
<!-- NOTE-swimm-snippet: the lines below link your snippet to Swimm -->
### 📄 Config/DefaultGameJoltAPI.ini
```ini
9      +StructRedirects=(OldName="UserInfo",NewName="GJUserInfo")
10     +StructRedirects=(OldName="TrophyInfo",NewName="GJTrophyInfo")
11     +StructRedirects=(OldName="ScoreInfo",NewName="GJScoreInfo")
12     +StructRedirects=(OldName="ScoreTableInfo",NewName="GJScoreTableInfo")
13     +StructRedirects=(OldName="ServerTime",NewName="GJServerTime")
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
