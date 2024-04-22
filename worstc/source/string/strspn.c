/* strspn.c
   Purpose: The implementation of str{c}spn and strpbrk */
#include "string.h"

/* <https://stackoverflow.com/a/15558528> */
size_t strspn(const char* _buffer, const char* _query)
{
    unsigned char lpt[32];
    size_t count = 0;
    while (*_query) {
        lpt[(*_query) >> 3] |= 1 << (*_query % 8);
        _query++;
    }

    while (*_buffer) {
        if (!((lpt[(*_buffer) >> 3] >> *_buffer % 8) & 0x1)) {
            break;
        }
        _buffer++;
        count++;
    }

    return count;
}

/* Exactly the same as above but the if is not negated. */
size_t strcspn(const char* _buffer, const char* _query)
{
    unsigned char lpt[32];
    size_t count = 0;
    while (*_query) {
        lpt[(*_query) >> 3] |= 1 << (*_query % 8);
        _query++;
    }

    while (*_buffer) {
        if (((lpt[(*_buffer) >> 3] >> *_buffer % 8) & 0x1)) {
            break;
        }
        _buffer++;
        count++;
    }

    return count;
}
