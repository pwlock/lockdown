/* fopen.c
   Purpose: The implementation of f{open,close} */
#include "bits/FILE.h"
#include <stdio.h>

#include <lockdown.h>
#include <stdlib.h>
#include <string.h>

static int getopenflags(const char* restrict mode)
{
    int flags = 0;
    if (mode[0] == 'r') {
        flags |= OPENFILE_READ;
        if (mode[1] == '+' 
         || (mode[1] == 'b' && mode[2] == '+')) {
            flags |= OPENFILE_WRITE;
        }
    }

    return flags;
}

FILE* fopen(const char* restrict name, 
            const char* restrict mode)
{
    int flags = getopenflags(mode);
    if (!flags) {
        return NULL;
    }

    int handle = OpenFile(name, 0);
    if (handle < 0) {
        return NULL;
    }

    FILE* f = malloc(sizeof(FILE));
    memset(f, 0, sizeof(FILE));
    
    f->_Handle = handle;
    f->_BufferStack_Begin = calloc(30, sizeof(char));
    return f;
}

void fclose(FILE* _stream)
{
    CloseFile(_stream->_Handle);
    if (!(_stream->_Flags & __FILE_STATIC)) {
        free(_stream->_BufferStack_Begin);
        free(_stream);
    }
}
