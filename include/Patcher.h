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

typedef struct _GHSDK_Patcher
{
    uint64_t Address;
    void* OriginalData;
    size_t Length;
} Patcher;

void Patcher_Construct(Patcher *This);
void Patcher_Install_Patch(Patcher *This, uint64_t Address, const void* Data, size_t Length);
void Patcher_Restore_Patch(Patcher *This);
void Patcher_Destroy(Patcher *This);

#ifdef __cplusplus
}
#endif
