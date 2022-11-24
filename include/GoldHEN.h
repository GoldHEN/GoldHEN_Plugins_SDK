/*
 * GoldHEN Plugin SDK - a prx hook/patch sdk for Orbis OS
 *
 * Credits
 * - SiSTRo <https://github.com/SiSTR0>
 * - ctn123 <https://github.com/ctn123>
 * - OSM <https://github.com/OSM-Made>
 * - jocover <https://github.com/jocover>
 * - bucanero <https://github.com/bucanero>
 * - OpenOrbis Team <https://github.com/OpenOrbis>
 * - nik <https://github.com/nkrapivin>
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

struct proc_rw {
    uint64_t address;
    void *data;
    uint64_t length;
    uint64_t write_flags;
} __attribute__((packed));

struct proc_prx_load {
    char process_name[32];
    char prx_path[100];
    uint64_t res;
} __attribute__((packed));

struct proc_prx_unload {
    char process_name[32];
    uint64_t prx_handle;
    uint64_t res;
} __attribute__((packed));

#define GOLDHEN_SDK_CMD_VERSION            0
#define GOLDHEN_SDK_CMD_KLOG               1
#define GOLDHEN_SDK_CMD_JAILBREAK          2
#define GOLDHEN_SDK_CMD_UNJAILBREAK        3
#define GOLDHEN_SDK_CMD_PROCESS_INFO       4
#define GOLDHEN_SDK_CMD_PROCESS_RW         5
#define GOLDHEN_SDK_CMD_PROCESS_PRX_LOAD   6
#define GOLDHEN_SDK_CMD_PROCESS_PRX_UNLOAD 7

#define GOLDHEN_SDK_VERSION       0x00000100 // 1.00

extern int sys_sdk_cmd(uint64_t cmd, void *data);

extern int sys_sdk_jailbreak(struct jailbreak_backup* jb);

extern int sys_sdk_unjailbreak(struct jailbreak_backup* jb);

uint32_t sys_sdk_version();

int sys_sdk_proc_info(struct proc_info* info);

int sys_sdk_proc_rw(struct proc_rw* data);

int sys_sdk_proc_prx_load(char* process_name, char* prx_path);

int sys_sdk_proc_prx_unload(char* process_name, int prx_handle);

#ifdef __cplusplus
}
#endif
