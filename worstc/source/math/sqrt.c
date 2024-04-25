/* sqrt.c
   Purpose: the implementation of sqrt. */
#include "bits/i754.h"
#include <math.h>

#define SQRT_FUN __generic_sqrtf
#define SQRT_TYPE float
#include "__sqrtX.c"

float sqrtf(float x)
{
#if WC_PREFER_BUILTINS
    return __builtin_sqrtf(x);
#else
   return __generic_sqrtf(x);
#endif
}

#define SQRT_FUN __generic_sqrtl
#define SQRT_TYPE long double
#include "__sqrtX.c"

long double sqrtl(long double x)
{
#if WC_PREFER_BUILTINS
    return __builtin_sqrtl(x);
#else
   return __generic_sqrtl(x);
#endif
}

#define SQRT_FUN __generic_sqrt
#define SQRT_TYPE double
#include "__sqrtX.c"

double sqrt(double x)
{
#if WC_PREFER_BUILTINS
    return __builtin_sqrt(x);
#else
   return __generic_sqrt(x);
#endif
}
