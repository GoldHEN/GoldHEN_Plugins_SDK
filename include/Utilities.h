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

#define ARRAY_COUNT(arry) sizeof(arry) / sizeof(arry[0])

typedef unsigned char vm_prot_t; /* protection codes */

#define VM_PROT_NONE ((vm_prot_t)0x00)
#define VM_PROT_READ ((vm_prot_t)0x01)
#define VM_PROT_WRITE ((vm_prot_t)0x02)
#define VM_PROT_EXECUTE ((vm_prot_t)0x04)
#define VM_PROT_COPY ((vm_prot_t)0x08) /* copy-on-read */

#define VM_PROT_ALL (VM_PROT_READ | VM_PROT_WRITE | VM_PROT_EXECUTE)
#define VM_PROT_RW (VM_PROT_READ | VM_PROT_WRITE)
#define VM_PROT_DEFAULT VM_PROT_ALL

#define MNT_UPDATE 0x0000000000010000ULL /* not real mount, just update */

typedef unsigned long HA;
#define HA_MANYARGS  HA arg1, HA arg2, HA arg3, HA arg4, HA arg5, HA arg6, HA arg7, HA arg8, HA arg9, HA arg10, HA arg11, HA arg12
#define MANYARGS arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12

#define klog printf

// if you need to define the hook in some header file, this only externs it.
#define HOOK_EXTERN(name) \
        extern Detour Detour_##name

// this defines the actual implementation
#define HOOK_INIT(name)                                                        \
        Detour Detour_##name = { DetourMode_x64 }

// this does a 64bit hook
#define HOOK(name) do { \
    klog("%s:%d HOOK64() Create " #name "\n", __FUNCTION__, __LINE__);  \
    Detour_Construct( (&(Detour_##name)), DetourMode_x64);                                 \
    Detour_DetourFunction( (&(Detour_##name)), (uint64_t)name, (void *)(&(name##_hook)) ); \
} while (0)

// 32bit...
#define HOOK32(name) do { \
    klog("%s:%d HOOK32() Create " #name "\n", __FUNCTION__, __LINE__);  \
    Detour_Construct( (&(Detour_##name)), DetourMode_x32);                                 \
    Detour_DetourFunction( (&(Detour_##name)), (uint64_t)name, (void *)(&(name##_hook)) ); \
} while (0)

// tries to pass arguments
#define HOOK_CONTINUE(name, type, ...) Detour_Stub( (&(Detour_##name)) , type , __VA_ARGS__ )

// unhooks, killing the defined hook, CANNOT BE REUSED
#define UNHOOK(name) Detour_Destroy( (&(Detour_##name)) )

void hex_dump(void *data, size_t size);

#ifdef __cplusplus
}
#endif
