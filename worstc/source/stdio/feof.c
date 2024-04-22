/* feof.c
   Purpose: the implementation of f{eof,error} and clearerr. */
#include "bits/FILE.h"
#include <stdio.h>

void clearerr(FILE* _stream)
{
    _stream->_Flags &= ~(__FILE_EOF | __FILE_ERROR);
}

int feof(FILE* _stream)
{
    return _stream->_Flags & __FILE_EOF;
}

int ferror(FILE* _stream)
{
    return _stream->_Flags & __FILE_ERROR;
}

