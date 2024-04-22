/* strlen.c
   Purpose: Implementation of strlen function. */
#include <string.h>

size_t strlen(const char* _str)
{
    /* "What if we used the Smart-Ass BSD Way(tm)
       which is completely unoptimizable to every
       compiler out there?" */
    const char* old = _str;
    while (*_str)
        _str++;
    return _str - old;
}
