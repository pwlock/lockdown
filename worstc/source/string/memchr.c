/* memchr.c
   Purpose: The implementation of {mem,str}chr. */
#include <string.h>

void* memchr(const void* _buffer, int _ch, size_t _size)
{
    unsigned char ch = _ch;
    const unsigned char* buffer = _buffer;

    while (_size) {
        if (*buffer == ch) {
            return (void*)buffer;
        }

        _size--; buffer++;
    }

    return NULL;
}

char* strchr(const char* _buffer, int _ch)
{
    char ch = _ch;
    while (*_buffer) {
        if (*_buffer == ch) {
            return (char*)_buffer;
        }

        _buffer++;
    }

    return NULL;
}