/* lockdown.h
   Purpose: Syscall wrappers. Enjoy syscalling! */
#pragma once

#include <stddef.h>
#include <stdint.h>

#include "power/system.h"
#include "power/ioctl.h"

#ifndef __LOCKDOWN_H
#define __LOCKDOWN_H

extern unsigned long IoControl(int ignored,
                               int command,
                               void* buffer,
                               unsigned long bufferSize);

extern int MountVolume(int device, const char* fsType, 
                       union ioctl_uuid* uuid, void* reserved);

/* File API */
extern int OpenFile(const char* name, 
                      int flags);
extern void WriteFile(int fh, 
                      const void* buffer, 
                      size_t size);
extern int ReadFile(int fh,
                    void* buffer,
                    size_t size);
extern unsigned long SetFilePointer(int fh,
                                    int rel,
                                    size_t offset);
extern void CloseFile(int handle);

/* Memory API */
extern void* VirtualMap(uint64_t address, 
                        size_t size, 
                        int flags);
extern void VirtualUnmap(uint64_t address, 
                         size_t size);

#endif
