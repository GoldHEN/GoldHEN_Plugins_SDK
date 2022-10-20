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

struct jailbreak_backup
{
    uint32_t cr_uid;
    uint32_t cr_ruid;
    uint32_t cr_rgid;
    uint32_t cr_groups;
    uint64_t cr_paid;
    uint64_t cr_caps[2];
    void* cr_prison;

    void* fd_cdir;
    void* fd_jdir;
    void* fd_rdir;
};

struct proc_info {
    int pid;
    char name[40];
    char path[64];
    char titleid[16];
    char contentid[64];
    char version[6];
    uint64_t base_address;
} __attribute__((packed));

struct proc_hook {
    uint64_t function;
    uint64_t hook;
    uint64_t trampoline;
    uint64_t stub;
    uint64_t stub_size;
} __attribute__((packed));

#define GOLDHEN_SDK_CMD_KLOG               1
#define GOLDHEN_SDK_CMD_JAILBREAK          2
#define GOLDHEN_SDK_CMD_UNJAILBREAK        3
#define GOLDHEN_SDK_CMD_PROCESS_INFO       4

extern int sys_sdk_cmd(uint64_t cmd, void *data);

extern int sys_sdk_jailbreak(struct jailbreak_backup* jb);

extern int sys_sdk_unjailbreak(struct jailbreak_backup* jb);

int sys_sdk_proc_info(struct proc_info* info);

#ifdef __cplusplus
}
#endif
