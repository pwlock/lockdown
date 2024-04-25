/* __logX.c
   Purpose: The generic implementation of log{,l,f} */
#include <math.h>

/* Behaviour changes when the following macros are defined:
    * LOG_FUN - function name
    * LOG_TYPE - function type */

#ifndef LOG_FUN
#define LOG_FUN log
#endif

#ifndef LOG_TYPE
#define LOG_TYPE double
#endif

/* https://stackoverflow.com/a/71994145 */
LOG_TYPE LOG_FUN(LOG_TYPE n)
{
    if (n <= 0) {
        return INFINITY;
    }

    static const LOG_TYPE euler = 2.7182818284590452354;
    unsigned a = 0, d;
    LOG_TYPE b, c, e, f;
    if (n > 0) {
        for (c = n < 1 ? 1 / n : n; (c /= euler) > 1; ++a);
        c = 1 / (c * euler - 1), 
            c = c + c + 1, 
            f = c * c, b = 0;
        for (d = 1, c /= 2; e = b, b += 1 / (d * c), b - e/* > 0.0000001 */;)
            d += 2, c *= f;
    } else b = (n == 0) / 0.;
    return n < 1 ? -(a + b) : a + b;
}

#undef LOG_FUN
#undef LOG_TYPE
