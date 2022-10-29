# GameJolt API for Unreal Engine Blueprints & C++

This [Unreal Engine](https://www.unrealengine.com/) plugin allows easy use of [GameJolt's GameAPI](https://gamejolt.com/game-api).

## Installation

You can   
#### a: Compile from Source

You can either clone the repository directly, as a [submodule](https://git-scm.com/book/de/v2/Git-Tools-Submodule) if you are using git for your project, or download the repository as a zip. To compile a plugin you have to put the files in a folder inside your project's plugin folder.

Load your project and open the plugin browser. You'll find the plugin in the "GameJolt"-Category. Enable it and restart the editor. At startup you should be asked to recompile the plugin.

#### b: Use Precompiled Binaries

If you have a Blueprint-only project or just don't want to compile the plugin yourself, you can find binaries for every build either on the [GameJolt Page](https://gamejolt.com/games/gjapi-bp/318270) or here on GitHub in the [Releases section](https://github.com/freezernick/ue-gjapi-core/releases).

Extract the archive in a folder inside
 - a) your [project's plugins folder](https://docs.unrealengine.com/4.27/en-US/ProductionPipelines/Plugins/#pluginfolders) (doesn't work in 4.26. See <a href="https://github.com/freezernick/ue-gjapi-core/issues/69">#69</a>)
 - b) your [engine's plugins folder](https://docs.unrealengine.com/4.27/en-US/ProductionPipelines/Plugins/#pluginfolders)

Load your project and open the plugin browser. You'll find the plugin in the "GameJolt"-Category. Enable it and restart the editor. You are good to go.

## Usage

These examples will show you, how to get started using the plugin. For more in-depth examples, explore the documentation.

### Blueprints

Before you can call any other node of the plugin, you have to call the "Initialize"-node. There you can set your game's id and private key.
Optionally you can overwrite the API-version used and the address of the API (default is https://api.gamejolt.com/api/game/).

![](https://user-images.githubusercontent.com/27819706/98440576-d35d8880-20f9-11eb-8601-1fd1330098db.png)

### C++

The plugin utilizes a singleton to store your data. All of the plugin functionality is static and globally accessible.

```c++
// To get started you have to call the `UGameJolt::Initialize` function
// to provide your game's id and private key.
UGameJolt::Initialize(12345, "coolPrivateKey");

// Then you can do whatever you want
UAutoLogin::AutoLogin()->Activate();
```

## Contributing
Pull requests are welcome. =)

## License
[BSL-1.0 License](LICENSE)
