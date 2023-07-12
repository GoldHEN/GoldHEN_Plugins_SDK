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

#include <errno.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stddef.h>
#include <stdint.h>
#include <orbis/libkernel.h>

#include "Detour.h"
#include "GoldHEN.h"
#include "Utilities.h"
#include "Syscall.h"

#define STRINGIFY(x) #x
#define STRINGIFY_DEEP(x) STRINGIFY(x)

// these are defined as enums in newest oosdk
/*
#define ORBIS_SYSMODULE_INTERNAL_SYS_CORE            0x80000004
#define ORBIS_SYSMODULE_INTERNAL_NETCTL              0x80000009
#define ORBIS_SYSMODULE_INTERNAL_HTTP                0x8000000A
#define ORBIS_SYSMODULE_INTERNAL_SSL                 0x8000000B
#define ORBIS_SYSMODULE_INTERNAL_NP_COMMON           0x8000000C
#define ORBIS_SYSMODULE_INTERNAL_SYSTEM_SERVICE      0x80000010
#define ORBIS_SYSMODULE_INTERNAL_USER_SERVICE        0x80000011
#define ORBIS_SYSMODULE_INTERNAL_APPINSTUTIL         0x80000014
#define ORBIS_SYSMODULE_INTERNAL_NET                 0x8000001C
#define ORBIS_SYSMODULE_INTERNAL_IPMI                0x8000001D
#define ORBIS_SYSMODULE_INTERNAL_VIDEO_OUT           0x80000022
#define ORBIS_SYSMODULE_INTERNAL_BGFT                0x8000002A
#define ORBIS_SYSMODULE_INTERNAL_PRECOMPILED_SHADERS 0x80000064
*/

#ifdef __cplusplus
}
#endif
