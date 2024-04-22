/* strbrk.c
   Purpose: Implementation of strpbrk and strrchr functions. */
#include <string.h>

char* strpbrk(const char* _buffer, const char* _query)
{
    while (*_buffer) {
        if (strchr(_query, *_buffer))
            return (char*)_buffer;
        _buffer++;
    }

    return NULL;
}


char* strrchr(const char* _buffer, int _ch)
{
    char ch = _ch;
    const char* ptr = NULL;
    while (*_buffer) {
        if (*_buffer == ch)
            ptr = _buffer;
        _buffer++;
    }

    return (char*)ptr;
}
