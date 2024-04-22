/* getc.c
   Purpose: The implementation of {un,f}getc */
#include "power/system.h"
#include <stdio.h>
#include <lockdown.h>

int __pop_buffer_char(FILE* stream)
{
    unsigned char c = stream->_BufferStack_Begin[stream->_BufferStack_Pos];
    stream->_BufferStack_Pos++;
    if (stream->_BufferStack_Pos == stream->_BufferStack_Index) {
        stream->_BufferStack_Pos = 0;
        stream->_BufferStack_Index = 0;
    }

    return c;
}

int ungetc(int c, FILE* stream)
{
    unsigned char cw = c;
    stream->_BufferStack_Begin[stream->_BufferStack_Index] = cw;
    stream->_BufferStack_Index++;
    return cw;
}

int fgetc(FILE* stream)
{
    if (stream->_BufferStack_Index) {
        return __pop_buffer_char(stream);
    }

    char c;
    ReadFile(stream->_Handle, &c, 1);
    SetFilePointer(stream->_Handle, SFILEPTR_REL_CURRENT, 1);
    stream->_Position++;
    return c;
}
