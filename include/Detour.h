/*
 * GoldHEN Plugin SDK - a prx hook/patch sdk for Orbis OS
 *
 * Credits
 * - OSM <https://github.com/OSM-Made>
 * - jocover <https://github.com/jocover>
 * - bucanero <https://github.com/bucanero>
 * - OpenOrbis Team <https://github.com/OpenOrbis>
 * - SiSTRo <https://github.com/SiSTR0>
 */

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

typedef enum _GHSDK_DetourMode {
    DetourMode_x64,
    DetourMode_x32
} DetourMode;

typedef struct _GHSDK_Detour {
    DetourMode Mode;
    void *StubPtr;
    size_t StubSize;
    void *FunctionPtr;
    void *TrampolinePtr;
    void *HookPtr;
    uint8_t JumpInstructions64[14];  // jmp QWORD PTR[Address]
    uint8_t JumpInstructions32[05];  // jmp 32
} Detour;

// usage:
// typedef int(*somefunc_t)(int, void *, const char *);
// int result = Detour_Stub(&SomeHook, somefunc_t, /* arguments begin */ 1, NULL, "hi");
#define Detour_Stub(This, FunctionPointerType, ...) (((FunctionPointerType)((This)->StubPtr))(/* Arguments */__VA_ARGS__))

void *Detour_DetourFunction(Detour *This, uint64_t FunctionPtr, void *HookPtr);

void Detour_RestoreFunction(Detour *This);

void Detour_Construct(Detour *This, DetourMode Mode);

void Detour_Destroy(Detour *This);

#ifdef __cplusplus
}
#endif
