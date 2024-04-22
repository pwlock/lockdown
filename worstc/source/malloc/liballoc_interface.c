/* liballoc_interface.c
   Purpose: Interface used by liballoc */
#include "liballoc.h"
#include "lockdown.h"
#include "power/system.h"

int liballoc_lock()
{
    /* TODO: lock */
    return 0;
}

int liballoc_unlock()
{
    /* TODO: unlock */
    return 0;
}

void* liballoc_alloc(size_t pages)
{
    unsigned int pa = pages * 4096;
    return VirtualMap(0, pa, MAP_USER_WRITE);
}

int liballoc_free(void* p, size_t length)
{
    VirtualUnmap((uint64_t)p, length * 4096);
    return 0;
}
