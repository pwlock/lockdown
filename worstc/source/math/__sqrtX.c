/* __sqrtX.c
   Purpose: The generic implementation of sqrt{,f,l} */
#include <math.h>

/* Behaviour changes when the following macros are defined:
    * SQRT_FUN - function name
    * SQRT_TYPE - function type */

#ifndef SQRT_FUN
#define SQRT_FUN __generic_sqrt
#endif

#ifndef SQRT_TYPE
#define SQRT_TYPE double
#endif

SQRT_TYPE SQRT_FUN(SQRT_TYPE n)
{
   float x = n;
   float root;
   const float tol = 0.0000001f;
   while (1) {
      root = 0.5f * (x + (n / x));
      if (fabsl((long double)(root - x)) < tol)
         break;
        
      x = root;
   }
    
   return root;
}

#undef SQRT_TYPE
#undef SQRT_FUN
