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

/** GoldHEN **/

int sys_sdk_cmd(uint64_t cmd, void *data) {
    return orbis_syscall(500, cmd, data);
}

int sys_sdk_jailbreak(struct jailbreak_backup* jb) {
    return sys_sdk_cmd(GOLDHEN_SDK_CMD_JAILBREAK, jb);
}

int sys_sdk_unjailbreak(struct jailbreak_backup* jb) {
    if (!jb) {
        return -1;
    }

    return sys_sdk_cmd(GOLDHEN_SDK_CMD_UNJAILBREAK, jb);
}

int sys_sdk_proc_info(struct proc_info* info) {
    return sys_sdk_cmd(GOLDHEN_SDK_CMD_PROCESS_INFO, info);
}
