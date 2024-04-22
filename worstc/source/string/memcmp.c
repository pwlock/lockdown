/* memcmp.c
   Purpose: The implementation of {mem,str,strn}cmp */
#include <string.h>

int memcmp(const void* _buf1, const void* _buf2, size_t _size)
{
    const unsigned char* b1 = _buf1;
    const unsigned char* b2 = _buf2;

    while (_size) {
        if (*b1 < *b2)
            return -1;
        else if (*b1 > *b2)
            return 1;
        b1++; b2++;
        _size--;
    }

    return 0;
}

int strcmp(const char* _str1, const char* _str2)
{
    return memcmp(_str1, _str2, strlen(_str1));
}

int strncmp(const char* _str1, const char* _str2, size_t _size)
{
    size_t cot = 0;
    while (cot <= _size || *_str1) {
        if (*_str1 < *_str2)
            return -1;
        else if (*_str1 > *_str2)
            return 1;
        _str1++; _str2++;
    }

    return 0;
}

