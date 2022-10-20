# GoldHEN Plugin SDK - a prx hook/patch sdk for Orbis OS

This is the GoldHEN Plugin SDK repository.

It requires [OpenOrbis PS4 Toolchain](https://github.com/OpenOrbis/OpenOrbis-PS4-Toolchain) and [LLVM](https://llvm.org/) to be installed.

## Including the SDK as source

It's better if you copy the SDK source files into your project and build the SDK from source *with* your project,
because there may be some compiler or OpenOrbis Toolchain bugfixes which would require rebuilding the GoldHEN SDK.

Just build all files from `source/` as C source code, and include stuff from `include/`.

## Including the SDK as a static library

If you are sure you won't be rebuilding the GoldHEN SDK, then you can include stuff from `include/`,
run `build_static.bat` to build a static library `libGoldHEN_Hook.a` and then use it in your project for the implementation of the headers.

## Credits

- [OSM](https://github.com/OSM-Made)
- [jocover](https://github.com/jocover)
- [bucanero](https://github.com/bucanero)
- [OpenOrbis Team](https://github.com/OpenOrbis)
- [SiSTRo](https://github.com/SiSTR0)
- [nik](https://github.com/nkrapivin)
