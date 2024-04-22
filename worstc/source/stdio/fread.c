/* fread.c
   Purpose: Implementation of fread. */
#include <stdio.h>
#include "bits/FILE.h"
#include "lockdown.h"

size_t
fread(void* restrict _buffer, size_t _size, 
      size_t _memberSize, FILE* _f)
{
   size_t rs = _size;
   char* restrict cb = _buffer;
   while(_f->_BufferStack_Index) {
      *cb++ = __pop_buffer_char(_f);
      if (_f->_BufferStack_Pos % _memberSize == 0)
         rs--;
   }

   int rd = ReadFile(_f->_Handle, cb, rs * _memberSize);
   if (rd < 0)
      _f->_Flags |= __FILE_ERROR;
   else if (rd != (int)(rs * _memberSize))
      _f->_Flags |= __FILE_EOF;

   _f->_Position += rd;
   return rd / _memberSize;
}
