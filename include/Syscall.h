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

int orbis_syscall(int num, ...);

int sys_dynlib_dlsym(int loadedModuleID, const char *name, void *destination);

int sys_dynlib_load_prx(const char *name, int *idDestination);

#ifdef __cplusplus
}
#endif
