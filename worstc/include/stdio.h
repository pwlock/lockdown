/* stdio.h
   Purpose: Facilities for I/O. */
#pragma once

#ifndef __STDIO_H
#define __STDIO_H 1

#include "bits/config.h"
#include "bits/FILE.h"

#define __need_size_t
#include <stddef.h>

#define EOF -2
#define FOPEN_MAX 32

#define SEEK_CUR 0
#define SEEK_SET 1
#define SEEK_END 2

typedef struct _FILE_struct FILE;

extern FILE* stdout;
extern FILE* stdin;
extern FILE* stderr;

extern FILE*
fopen(const char* __restrict _name, const char* __restrict _mode);

extern void
fclose(FILE* _stream);

extern int
ungetc(int _c, FILE* _stream);

extern int
fgetc(FILE* _stream);

extern size_t
fread(void* __restrict _buffer, size_t _size, size_t _memberSize, FILE* _f);

extern int
fseek(FILE* _stream, long int _off, int _base);

extern long int
ftell(FILE* _stream);

extern void
clearerr(FILE* _stream);

extern int 
feof(FILE* _stream);

extern int
ferror(FILE* _stream);

#endif
