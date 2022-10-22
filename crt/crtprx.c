/*** Coded by Specter + SiSTRo ***/

#include <stdio.h>

extern int module_start(size_t args, const void *argp);
extern int module_stop(size_t args, const void *argp);

// sce_module_param
__asm__(
        ".intel_syntax noprefix \n"
        ".align 0x8 \n"
        ".section \".data.sce_module_param\" \n"
        "_sceProcessParam: \n"
        // size
        "	.quad 	0x18 \n"
        // magic
        "	.quad   0x13C13F4BF \n"
        // SDK version
        "	.quad 	0x4508101 \n"
        ".att_syntax prefix \n"
        );

// data globals
__asm__(
        ".intel_syntax noprefix \n"
        ".align 0x8 \n"
        ".data \n"
        "__dso_handle: \n"
        "	.quad 	0 \n"
        "_sceLibc: \n"
        "	.quad 	0 \n"
        ".att_syntax prefix \n"
        );

int _init(size_t args, const void *argp)
{
    return module_start(args, argp);
}

int _fini(size_t args, const void *argp)
{
    return module_stop(args, argp);
}
