/* stdlib.h
   Purpose: General utility routines */
#pragma once

#include "bits/config.h"
#include <stddef.h>

#ifndef __STDLIB_H
#define __STDLIB_H 1

__WC_EXTERN_C_BEGIN

extern void*
calloc(size_t _arraySize, size_t _arrayItemSize);

extern void
free(void* _ptr);

extern void*
malloc(size_t _size);

extern void*
realloc(void* _ptr, size_t _size);

extern unsigned long int
strtoul(const char* _string, char** _endptr, int _bs);

__WC_EXTERN_C_END

#endif
