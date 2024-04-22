/* mem.c 
   Purpose: wrapper for memory syscalls */
#include "power/system.h"
#include "syscall.h"
#include <lockdown.h>
#include <stdint.h>

void* VirtualMap(uint64_t address, size_t size, int flags)
{
    return (void*)SystemCall(SYS_MAPPAGES, address, size, flags, 0);
}

void VirtualUnmap(uint64_t address, size_t size)
{
    SystemCall(SYS_UNMAPPAGES, address, size, 0, 0);
}
