# GameJolt API for Unreal Engine Blueprints & C++

This Unreal Engine Plugin allows easy use of [GameJolt's GameAPI](https://gamejolt.com/game-api)

## Installation

You can   
#### a: Compile from Source

You can either clone the repository directly, as a [submdoule](https://git-scm.com/book/de/v2/Git-Tools-Submodule) if you are using git for your project, or download the repository as a zip. To compile a plugin you have to put the files in a folder inside your project's plugin folder.

Load your project and open the plugin browser. You'll find the plugin in the "GameJolt"-Category. Enable it and restart the editor. At startup you should be asked to recompile the plugin.

#### b: Use Precompiled Binaries

If you have a Blueprint-only project or just doesn't want to compile the plugin yourself, you can find binaries for every build either on the [GameJolt Page](https://gamejolt.com/games/gjapi-bp/318270) or here on GitHub in the [Releases section](https://github.com/freezernick/ue-gjapi-core/releases).

Extract the archive in a folder inside
 - a) your project's plugins folder (doesn't work in 4.26. See <a href="https://github.com/freezernick/ue-gjapi-core/issues/69">#69</a>)
 - b) your engine's plugins folder

Load your project and open the plugin browser. You'll find the plugin in the "GameJolt"-Category. Enable it and restart the editor. You are good to go.

## Usage

These examples will show you, how to get started using the plugin. For more in-depth examples, explore the documentation.

### Blueprints

@todo: blueprint setup

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
