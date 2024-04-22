/* memset.c
   Purpose: The generic implementation of mem{set,cpy,ccpy}. */
#include <stdint.h>
#include <string.h>

void* memcpy(void* restrict _dest, const void* _src, size_t _size)
{
    if (!_size || _src == _dest)
        return _dest;

    for (size_t i = 0; i < _size; i++) {
        ((uint8_t* restrict)_dest)[i] = ((const uint8_t*)_src)[i];
    }

    return _dest;
}

void* memset(void* _buffer, int _ch, size_t _size)
{
    for (size_t i = 0; i < _size; i++) {
        ((uint8_t*)_buffer)[i] = _ch;
    }

    return _buffer;
}

void*
memccpy(void* restrict _dest, const void* _src, int _c, size_t _size)
{
    /* Is this counterproductive, 
     given what restrict is actually for? */
    unsigned char* restrict dest = _dest;
    const unsigned char* restrict src = _src;

    for (size_t i = 0; i < _size; i++) {
        dest[i] = src[i];
        if (dest[i] == (unsigned char)_c)
            break;
    }

    return _dest;
}
