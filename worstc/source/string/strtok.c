/* strtok.c
   Purpose: the implementation of strtok{_r}. */
#define _POSIX_SOURCE
#include "string.h"

static char* _strtokBuffer;

char* strtok(char* __restrict _string, const char* __restrict _sep)
{
    return strtok_r(_string, _sep, &_strtokBuffer);
}

char* 
strtok_r(char* __restrict _string, const char* __restrict _sep, char** _ctx)
{
    if (!*_ctx)
        (*_ctx) = _string;

    char* ptr;
    while (*_sep) {
        if ((ptr = strchr(*_ctx, *_sep))) {
            (*ptr) = 0;
            (*_ctx) = ptr + 1;
            return _string;
        }

        _sep++;
    }

    (*_ctx) = NULL;
    return NULL;
}

