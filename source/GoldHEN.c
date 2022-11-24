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
uint32_t sys_sdk_version() {
    return sys_sdk_cmd(GOLDHEN_SDK_CMD_VERSION, NULL);
}

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

int sys_sdk_proc_rw(struct proc_rw* data) {
    return sys_sdk_cmd(GOLDHEN_SDK_CMD_PROCESS_RW, data);
}

int sys_sdk_proc_prx_load(char* process_name, char* prx_path) {
    struct proc_prx_load args;
    memset(&args, 0, sizeof(struct proc_prx_load));
    strncpy(args.process_name, process_name, sizeof(args.process_name));
    strncpy(args.prx_path, prx_path, sizeof(args.prx_path));

    sys_sdk_cmd(GOLDHEN_SDK_CMD_PROCESS_PRX_LOAD, &args);

    return args.res;
}

int sys_sdk_proc_prx_unload(char* process_name, int prx_handle) {
    struct proc_prx_unload args;
    memset(&args, 0, sizeof(struct proc_prx_unload));
    strncpy(args.process_name, process_name, sizeof(args.process_name));
    args.prx_handle = prx_handle;

    sys_sdk_cmd(GOLDHEN_SDK_CMD_PROCESS_PRX_UNLOAD, &args);

    return args.res;
}