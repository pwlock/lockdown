/* fseek.c
   Purpose: the implementation of f{seek,tell}. */
#include <power/system.h>
#include "lockdown.h"
#include <stdio.h>

int fseek(FILE* _stream, long int _off, int _base)
{
   int sk;
   switch (_base) {
   case SEEK_CUR:
      sk = SFILEPTR_REL_CURRENT;
      break;
   case SEEK_END:
      sk = SFILEPTR_REL_END;
      break;
   case SEEK_SET:
      sk = SFILEPTR_REL_BEGIN;
      break;
   default:
      return -1;
   }

   _stream->_Position = SetFilePointer(_stream->_Handle, sk, _off);
   return 0;
}

long int ftell(FILE* _stream)
{
   return _stream->_Position;
}
