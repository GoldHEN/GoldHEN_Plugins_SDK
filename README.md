# GoldHEN Plugin SDK - a PRX hook/patch SDK for Orbis OS

[![Build library check](https://github.com/GoldHEN/GoldHEN_Plugins_SDK/actions/workflows/build_lib.yml/badge.svg)](https://github.com/GoldHEN/GoldHEN_Plugins_SDK/actions/workflows/build_lib.yml)
[![MIT Licensed](https://img.shields.io/github/license/GoldHEN/GoldHEN_Plugins_SDK.svg?maxAge=2592000)](https://github.com/GoldHEN/GoldHEN_Plugins_SDK/blob/main/LICENSE)

This is the GoldHEN Plugin SDK repository.

It requires [OpenOrbis PS4 Toolchain](https://github.com/OpenOrbis/OpenOrbis-PS4-Toolchain) and [LLVM 10+](https://llvm.org/) to be installed.

## Including the SDK as source

It's better if you copy the SDK source files into your project and build the SDK from source *with* your project,
because there may be some compiler or OpenOrbis Toolchain bugfixes which would require rebuilding the GoldHEN SDK.

Just build all files from `source/` as C source code, and include stuff from `include/`.

## Including the SDK as a static library

If you are sure you won't be rebuilding the GoldHEN SDK, then you can include stuff from `include/`,
run `make` for Linux or `build_static.bat` for Windows to build a static library `libGoldHEN_Hook.a` and then use it in your project for the implementation of the headers.

# Troubleshooting log crashes

If you ran into crashes related to print logging (usually during VA args assignment clearing stack) you can try building with printf `make PRINTF=1` and `./build.sh -printf` in main plugin repository.

## Credits

- [Everyone at Mira/OpenOrbis Team](https://github.com/OpenOrbis)
- [SiSTRo](https://github.com/SiSTR0)
- [ctn123](https://github.com/ctn123)
- [OSM](https://github.com/OSM-Made)
- [jocover](https://github.com/jocover)
- [bucanero](https://github.com/bucanero)
- [nik](https://github.com/nkrapivin)

## License

GoldHEN Plugin SDK is released under the [MIT License](https://github.com/GoldHEN/GoldHEN_Plugins_SDK/blob/main/LICENSE).
