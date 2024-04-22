/* strcpy.c
   Purpose: Implementation of str{n}cpy functions. */
#include <string.h>

char* strcpy(char* restrict _dest, const char* restrict _src)
{
    return memcpy(_dest, _src, strlen(_src) + 1);
}

char*
strncpy(char* restrict _dest, const char* restrict _src, size_t _size)
{
    size_t cot = 0;

    /* This is actually "bad" because our memset is a for-loop.
       TODO: switch the memset impl to a rep stosb */
    memset(_dest, 0, _size);
    while(*_src && cot < _size) {
        if (!*_src)
            return _dest;
      
        _dest[cot] = _src[cot];
        cot++;
    }

   return _dest;
}


