@echo off
rem GoldHEN SDK static lib build script

rem change these if you need:
rem C compiler
set CC=clang
rem AR archiver
set AR=llvm-ar

rem usually you do not need to change the stuff below:

set CFLAGS=--target=x86_64-pc-freebsd12-elf -DORBIS=1 -D__ORBIS__=1 -DPS4=1 -DOO=1 -D__PS4__=1 -DOOPS4=1 -D__OOPS4__=1 -D__BSD_VISIBLE=1 -D_BSD_SOURCE=1 -march=btver2 -mtune=btver2 -fPIC -std=c11 -isysroot "%OO_PS4_TOOLCHAIN%" -isystem "%OO_PS4_TOOLCHAIN%\include" -Iinclude

rmdir /s /q build
mkdir build

for %%f in (source\*.c) do (
	%CC% %CFLAGS% -c %%f -o build\%%~nf.o
)

%CC% -target x86_64-pc-linux-gnu -ffreestanding -nostdlib -fno-builtin -fPIC -isysroot "%OO_PS4_TOOLCHAIN%" -isystem "%OO_PS4_TOOLCHAIN%\include" -Iinclude -c crt/crtprx.c -o build\crtprx.o
%AR% --format=bsd rcs libGoldHEN_Hook.a build\*.o build\crtprx.o
