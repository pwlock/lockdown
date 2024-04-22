/* file.c
   Purpose: Wrapper for system calls in File API */
#include <lockdown.h>
#include <power/system.h>
#include <stddef.h>

#include "lockdown.h"
#include "power/ioctl.h"
#include "syscall.h"

int OpenFile(const char* name, int flags)
{
    return SystemCall(SYS_OPENFILE, (long)name, flags, 0, 0);
}

void WriteFile(int fh, const void* buffer, size_t size)
{
    SystemCall(SYS_WRITEFILE, fh, (long)buffer, size, 0);
}

void CloseFile(int handle)
{
    SystemCall(SYS_CLOSEFILE, (long)handle, 0, 0, 0);
}

int ReadFile(int fh, void* buffer, size_t size)
{
    return SystemCall(SYS_READFILE, fh, (uint64_t)buffer, size, 0);
}

unsigned long SetFilePointer(int fh, int rel, size_t offset)
{
    return SystemCall(SYS_SETFILEPOINTER, fh, rel, offset, 0);
}

unsigned long IoControl(int ignored, int command,
                        void* buffer, unsigned long bufferSize)
{
    (void)ignored;
    return SystemCall(SYS_DEVICEIOCTL, 0, command, (uint64_t)buffer, bufferSize);
}

int MountVolume(int device, const char* fsType, union ioctl_uuid* uuid, void* reserved)
{
    return SystemCall(SYS_MOUNTVOLUME, device, (uint64_t)fsType, (uint64_t)uuid, (uint64_t)reserved);
}
