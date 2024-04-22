/* FILE.h
   Purpose: The definition of FILE (internally). */
#pragma once

#ifndef __BITS_FILE_H
#define __BITS_FILE_H 1

#define __need_size_t
#include <stddef.h>

#define __FILE_EOF        0x00000001
#define __FILE_ERROR      0x00000010
#define __FILE_WRITE_ONLY 0x00000100
#define __FILE_STATIC     0x00001000

#define __FBUFFERING_NONE 0 /*< No buffering */
#define __FBUFFERING_LINE 1 /*< Line buffering */
#define __FBUFFERING_BUFFER 2 /*< Full bufferring */

struct _FILE_struct {
    char* _BufferStack_Begin;
    size_t _BufferStack_Index, _BufferStack_Pos; /*< for ungetc. */
    size_t _Position;
    char* _BufferingBuffer;
    int _BufferingMode; /*< One of __FBUFFERING_*. */
    int _Handle;
    int _Flags;
};

int __pop_buffer_char(struct _FILE_struct* stream);

#endif

