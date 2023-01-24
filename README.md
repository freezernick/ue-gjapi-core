# GameJolt API for Unreal Engine Blueprints & C++

This [Unreal Engine](https://www.unrealengine.com/) plugin allows easy use of [GameJolt's GameAPI](https://gamejolt.com/game-api).

## Installation

### Blueprint-only Project

1. Download the Plugin from one of these sources
    * [GitHub](https://github.com/freezernick/ue-gjapi-core/releases)
    * [GameJolt](https://gamejolt.com/games/gjapi-bp/318270)
2. Put the files in `YOUR_ENGINE_DIR/Engine/Plugins/Marketplace/GameJoltAPI`   
**You may need to create the `Marketplace` folder yourself**
3. Start the Editor and enable the Plugin

### C++ Project

1. Grab the source by
    * cloning the repository directly
    * setting up a [submodule](https://git-scm.com/book/de/v2/Git-Tools-Submodule)
    * or download the repository as a zip.
2. Active the plugin by
    * starting the Editor and using the UI
    * adding the following lines to your `.uproject` file
    ```json
    "Plugins": [
        {
             "Name": "GameJoltAPI",
             "Enabled": true
        }
    ]
    ```
3. Recompile!

## Usage

These examples will show you, how to get started using the plugin. For more in-depth examples, explore the documentation.

### Introduction to Subsystems

The plugin implements a custom subsystem. You can find more information about subsystems [here](https://docs.unrealengine.com/4.27/en-US/ProgrammingAndScripting/Subsystems/).

### Blueprints

Before you can call any other node of the plugin, you have to call the "Initialize"-node. There you can set your game's id and private key.

![Unreal Engine Blueprint Graph](https://user-images.githubusercontent.com/27819706/213867463-ce81d27a-8c20-448b-b3ab-23b9b6f6162f.png)

### C++

The plugin [subsystem (see above)](#introduction-to-subsystems) is called `UGameJoltSubsystem` and is accessible from the `GameInstance`

```c++
#include "GameJoltSubsystem.h"

[...]

// To get started you have to call the `Setup` function of the subsystem
// to provide your game's id and private key.
GetGameInstance()->GetSubsystem<UGameJoltSubsystem>()->Setup(12345, "coolPrivateKey");
```
Then you can use the async-actions provided by the plugin to interact with GameJolt. For an API-Reference for the plugin please refer to the [header files](Source/GameJoltAPI/Public/).

## Contributing
Pull requests are welcome. =)

## License
[BSL-1.0 License](LICENSE.md)
