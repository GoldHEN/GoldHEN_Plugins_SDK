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

void klog(const char* fmt, ...) {
    va_list args;
	char Buffer[0x100] = { '\0' };
	
	va_start(args, fmt);
	vsnprintf(Buffer, sizeof(Buffer), fmt, args);
	va_end(args);

	sys_sdk_cmd(GOLDHEN_SDK_CMD_KLOG, Buffer);
}

void hex_dump(void *data, size_t size) {
    unsigned char *p = (unsigned char *)data;
    int i;

    for(i = 0; i < size; i++) {
        klog("%02X ", *p++);
        if(!(i % 16) && i != 0) {
            klog("\n");
        }
    }

    klog("\n");
}
