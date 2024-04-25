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

__WC_EXTERN_C_BEGIN

/* Open handle for file located at name. */
extern FILE* fopen(const char* __restrict _name, 
                   const char* __restrict _mode);

/* Close handle stream. */
extern void fclose(FILE* _stream);

/* Push character onto stream's internal buffer */
extern int ungetc(int _c, FILE* _stream);

/* Extract character from stream's internal buffer */
extern int fgetc(FILE* _stream);

/* Read size elements from stream. */
extern size_t fread(void* __restrict _buffer, 
                    size_t _size, 
                    size_t _memberSize, 
                    FILE* _f);

/* Jump to offset relative to stream's base. */
extern int fseek(FILE* _stream, 
                 long int _off, 
                 int _base);

/* Get current file position */
extern long int ftell(FILE* _stream);

/* Remove error status from handle */
extern void clearerr(FILE* _stream);

/* Is there chars left to be read? */
extern int feof(FILE* _stream);

/* Did something went wrong during read/write? */
extern int ferror(FILE* _stream);

extern int printf(const char* _message, ...);

__WC_EXTERN_C_END

#endif
