/* memmove.c
   Purpose: The implementaton of memmove. */
#include <string.h>

void* memmove(void* _dest, const void* _src, size_t _size)
{
    unsigned char* dest = _dest;
    const unsigned char* src = _src;
    
    if (dest > src && (size_t)(dest - src) < _size) {
        while (_size--) {
            *--dest = *--src;
            _size--;
        }

        return dest;
    }
    else if (src > dest && (size_t)(dest - src) < _size) {
        while (_size) {
            *dest++ = *src++;
            _size--;
        }
    }

    memcpy(_dest, _src, _size);
    return dest;
}
