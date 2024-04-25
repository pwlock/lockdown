/* __acosX.c
   Purpose: The implementation of acos{,f,l} */
#include <math.h>

/* This file expects the following macros to be defined:
    * ACOS_FUN - routine name
    * ACOS_TYPE - return and argument type */

#ifndef ACOS_FUN
#define ACOS_FUN acos
#endif

#ifndef ACOS_TYPE
#define ACOS_TYPE double
#endif

ACOS_TYPE ACOS_FUN (ACOS_TYPE x)
{
    if (x > 1 || x < -1) {
        /* domain error */
        return NAN;
    }

    ACOS_TYPE a = 1.43 + 0.59 * x;
    a = (a + (2 + 2 * x) / a) / 2;
    ACOS_TYPE b = 1.65 - 1.41 * x;
    b = (b + (2 - 2 * x) / b) / 2;
    ACOS_TYPE c = 0.88 - 0.77 * x;
    c = (c + (2 - a) / c) / 2;
    
    return 8.0f / 3.0f * c - b / 3.0f;
}

#undef ACOS_FUN
#undef ACOS_TYPE
