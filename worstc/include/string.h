/* string.h
   Purpose: String manipulation routines */

#pragma once

#ifndef __STRING_H
#define __STRING_H 1

#include "bits/config.h"

#define __need_size_t
#define __need_NULL
#include <stddef.h>

/* Copy _size bytes from _src to _dest */
extern void*
memcpy(void* __restrict _dest, const void* _src, size_t _size);

#ifdef _HAS_C23

/* memcpy, but stop at the first occurence of _c. */
extern void*
memccpy(void* __restrict _dest, const void* _src, int _c, size_t _size);

#endif

extern void*
memmove(void* _dest, const void* _src, size_t _size);

extern void*
memset(void* _buffer, int _ch, size_t _size);

extern int
memcmp(const void* _buf1, const void* _buf2, size_t _size);

extern void*
memchr(const void* _buffer, int _ch, size_t size);

extern char*
strcpy(char* __restrict _dest, const char* __restrict _src);

extern char*
strncpy(char* __restrict _dest, const char* __restrict _src, size_t _size);

extern size_t
strlen(const char* _str);

extern int
strcmp(const char* _str1, const char* _str2);

extern int
strncmp(const char* _buf1, const char* _buf2, size_t _size);

extern char*
strchr(const char* _buffer, int _ch);

extern size_t
strspn(const char* _buffer, const char* _query);

extern size_t
strcspn(const char* _buffer, const char* _query);

extern char*
strpbrk(const char* _buffer, const char* _query);

extern char*
strrchr(const char* _buffer, int _ch);

extern char*
strtok(char* __restrict _string, const char* __restrict _sep);

#ifdef _POSIX_SOURCE

extern char*
strtok_r(char* __restrict _string, const char* __restrict _sep, char** _ctx);

#endif

#endif
