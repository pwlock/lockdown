/* strtoul.c
   Purpose: implementation of strtoul */
#include <stdlib.h>

unsigned long int 
strtoul(const char* _string, char** _endptr, int _bs)
{
    while (*_string == ' ') {
        _string++;
    }

    /* We don't really support negative numbers. */
    if (*_string == '+' || *_string == '-')
        _string++;
    
    if (!_bs) {
        _bs = 10;
        if (*_string == '0') {
            _bs = 8;
            _string++;
            if (*(_string) == 'x'
             || *(_string) == 'X') {
                _bs = 16;
                _string++;
            }
        }
    }

    int index;
    unsigned long output = 0;
    while (*_string) {
        index = (*_string) - '0';        
        if (*_string >= 'a')
            index = (*_string) - 87;
        else if (*_string >= 'A')
            index = (*_string) - 55;

        if (index > _bs) {
            /* TODO set errno */
            return 0;
        }

        output *= _bs;
        output += index;        
        _string++;
    }

    (*_endptr) = (char*)_string;
    return output;
}
