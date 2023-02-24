# Changelog

All notable changes to this project will be documented in this file. See [commit-and-tag-version](https://github.com/absolute-version/commit-and-tag-version) for commit guidelines.

## [2.0.0-alpha.1](https://github.com/freezernick/ue-gjapi-core/compare/v2.0.0-alpha.0...v2.0.0-alpha.1) (2023-02-24)


### Features

* add plugin settings ([#186](https://github.com/freezernick/ue-gjapi-core/issues/186)) ([7885c19](https://github.com/freezernick/ue-gjapi-core/commits/7885c192ccf0e7bbf727af3ea31af767b3605218))


### Bug Fixes

* fix compile-time error ([7e68d13](https://github.com/freezernick/ue-gjapi-core/commits/7e68d131ba0a101c4c85a9383b8d4c76bf8a3959))

## [2.0.0-alpha.0](https://github.com/freezernick/ue-gjapi-core/compare/v1.1.6...v2.0.0-alpha.0) (2023-02-06)


### ⚠ BREAKING CHANGES

* implement `UGameJoltSubsystem` and remove `UGameJolt` singleton
* move source files in the private folder
* prefix all structs with GJ

### Features

* implement `UGameJoltSubsystem` and remove `UGameJolt` singleton ([a108d0c](https://github.com/freezernick/ue-gjapi-core/commits/a108d0c3d4bf05435c223e0a0f198621fb3eee19)), closes [#161](https://github.com/freezernick/ue-gjapi-core/issues/161) [#172](https://github.com/freezernick/ue-gjapi-core/issues/172)


### Bug Fixes

* prefix all structs with GJ ([ddc6dbd](https://github.com/freezernick/ue-gjapi-core/commits/ddc6dbd05d9145191ae098b16a25ffadc35c27a1)), closes [#153](https://github.com/freezernick/ue-gjapi-core/issues/153)
* remove call to undeclared symbol ([a877339](https://github.com/freezernick/ue-gjapi-core/commits/a877339015c1cbd637e57324f63a41b14a4bf554))
* **Rocket:** add missing World.h include ([31c9b03](https://github.com/freezernick/ue-gjapi-core/commits/31c9b034d82bd653a08957f617086f8d3d9fbb58)), closes [#178](https://github.com/freezernick/ue-gjapi-core/issues/178)


* move source files in the private folder ([a53f17d](https://github.com/freezernick/ue-gjapi-core/commits/a53f17d12137914a82c031834f78831047542646))

### [1.1.6](https://github.com/freezernick/ue-gjapi-core/compare/v1.1.5...v1.1.6) (2023-01-18)


### Bug Fixes

* **FetchTrophies:** fix Error pin not showing ([07932b7](https://github.com/freezernick/ue-gjapi-core/commits/07932b7ce6c5d8d3500390b20e2bce0e53a05a3b)), closes [#162](https://github.com/freezernick/ue-gjapi-core/issues/162)

### [1.1.5](https://github.com/freezernick/ue-gjapi-core/compare/v1.1.4...v1.1.5) (2022-06-20)


### Bug Fixes

* make some error messages clearer when a required parameter is unset ([0720166](https://github.com/freezernick/ue-gjapi-core/commits/0720166cfb87fe9079aab2d9a823bcd261ce2be4))
* prevent some functions to call the failure event twice ([6ad6551](https://github.com/freezernick/ue-gjapi-core/commits/6ad65516da45dcffb92ec56925868c3bb826e91b))

### [1.1.4](https://github.com/freezernick/ue-gjapi-core/compare/v1.1.3...v1.1.4) (2022-04-13)


### Bug Fixes

* add missing member initialization in FTrophyInfo ([89d3fd0](https://github.com/freezernick/ue-gjapi-core/commits/89d3fd062d5a5f39072a5ba55409afd9d6778b8d))
* add missing member initialization in FUserInfo ([c3023c1](https://github.com/freezernick/ue-gjapi-core/commits/c3023c154c54653a8860cfd3e646c9aab58b829d))
* change 'Json' module capitalization to prevent a warning ([3389df6](https://github.com/freezernick/ue-gjapi-core/commits/3389df6cc0e64f8ebc887180b3d5a2e8b1dd2994)), closes [#116](https://github.com/freezernick/ue-gjapi-core/issues/116)
* change preprocessor macro to prevent a warning ([9d73046](https://github.com/freezernick/ue-gjapi-core/commits/9d7304683cb5c8bd45cef8c9868ada8c9187b167)), closes [#117](https://github.com/freezernick/ue-gjapi-core/issues/117)
* make OnReady Response pointer const ([9b41ca3](https://github.com/freezernick/ue-gjapi-core/commits/9b41ca3664f0884844061a599a77383fb8beb1ed))

### [1.1.3](https://github.com/freezernick/ue-gjapi-core/compare/v1.1.2...v1.1.3) (2021-06-20)


### Bug Fixes

* extend preprocessor macro ([2567de1](https://github.com/freezernick/ue-gjapi-core/commits/2567de1cdb291ebf22bfb5a65846d29653e380f3))

### [1.1.2](https://github.com/freezernick/ue-gjapi-core/compare/v1.1.1...v1.1.2) (2021-06-20)


### Bug Fixes

* login related errors after multiple PIE runs ([eb52023](https://github.com/freezernick/ue-gjapi-core/commits/eb52023486224f1768973e72ddfa6e7b0969ef7b)), closes [#85](https://github.com/freezernick/ue-gjapi-core/issues/85)

### [1.1.1](https://github.com/freezernick/ue-gjapi-core/compare/v1.1.0...v1.1.1) (2021-05-26)


### Bug Fixes

* unreal engine 5 compatibility ([cd521d0](https://github.com/freezernick/ue-gjapi-core/commits/cd521d06122948425998d64a428f2ca0a230f5f5))

## [1.1.0](https://github.com/freezernick/ue-gjapi-core/compare/v1.0.0-RC1...v1.1.0) (2021-05-24)


### Features

* async nodes return which error occured (if any) ([2550282](https://github.com/freezernick/ue-gjapi-core/commits/2550282c16f295eba55b98425a1c92ca39a2517e))

## [1.0.0](https://github.com/freezernick/ue-gjapi-core/compare/v1.0.0-RC1...v1.0.0) (2021-05-24)

## [1.0.0](https://github.com/freezernick/ue-gjapi-core/compare/v1.0.0-RC1...v1.0.0) (2021-05-24)
