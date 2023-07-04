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

#include "Common.h"
#include "Patcher.h"

void Patcher_Construct(Patcher *This)
{
    This->Address = 0;
    This->OriginalData = NULL;
    This->Length = 0;
}

void Patcher_Install_Patch(Patcher *This, uint64_t Address, const void* Data, size_t Length)
{
    if (!Address || !Length)
    {
        klog("[Patcher] Install_Patch: No target (0x%lx) or length (%li) provided!\n", Address, Length);
        return;
    }

    //Backup Params.
    This->Address = Address;
    This->Length = Length;

    //Set protection to all
    sceKernelMprotect((void*)Address, Length, VM_PROT_ALL);

    //Backup data.
    int res = sceKernelMmap(0, Length, VM_PROT_ALL, 0x1000 | 0x2, -1, 0, &This->OriginalData);
    if (res < 0)
    {
#if (DEBUG) == 1
        klog("[Patcher] sceKernelMmap Failed: 0x%X\n", res);
#endif
        return;
    }
    memcpy(This->OriginalData, Data, Length);

    //Write Patch.
    memcpy((void*)Address, Data, Length);

#if (DEBUG) == 1
    klog("[Patcher] Install_Patch: Patch (%p) Written Successfully!\n", (void*)Address);
#endif
}

void Patcher_Restore_Patch(Patcher *This)
{
    if (This->OriginalData)
    {
        //Set protection to all
        sceKernelMprotect((void*)This->Address, This->Length, VM_PROT_ALL);

        //Write original Data back.
        memcpy((void*)This->Address, This->OriginalData, This->Length);

#if (DEBUG) == 1
        klog("[Patcher] Restore_Patch: Patch (%p) Restored Successfully!\n", (void*)This->Address);
#endif
    }
    else {
#if (DEBUG) == 1
        klog("[Patcher] Patch not installed.\n");
#endif
    }
}

void Patcher_Destroy(Patcher *This)
{
    Patcher_Restore_Patch(This);

    //Clean up
    sceKernelMunmap(This->OriginalData, This->Length);
}
