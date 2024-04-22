/* __fpclassifyfXX.c
   Purpose: The generic implementation of 
            fpclassify internal functions. */
/* Behaviour changes when the following macros are defined:
    * _FPCLASS_DOUBLE - Use double-precision floating points (defined) 
                        or single-precision (not defined). */
#include <math.h>

#include "ieee754.h"

#ifdef _FPCLASS_DOUBLE
#define __FPCLASS_FUN __fpclassifyf64
#define __ieee_float double
#define __int_raw unsigned long
#define __float_union __i754_float64
#else
#define __FPCLASS_FUN __fpclassifyf32
#define __ieee_float float
#define __int_raw unsigned int
#define __float_union __i754_float32
#endif

int
__FPCLASS_FUN ( __ieee_float f )
{
    union __float_union flt;
    flt.Value = f;

    __int_raw exp, frac;

#ifdef _FPCLASS_DOUBLE
    exp = I754_GET_EXPONENT64(flt.Raw);
    frac = I754_GET_FRACTION64(flt.Raw);
#else
    exp = I754_GET_EXPONENT32(flt.Raw);
    frac = I754_GET_FRACTION32(flt.Raw);
#endif
    if (exp == 0xFF || exp == 0x1FF) {
        if (!frac) {
            return FP_INFINITE;
        }

        return FP_NAN;
    }

    if (!exp) {
        if (!frac) {
            return FP_ZERO;
        }

        return FP_SUBNORMAL;
    }

    return FP_NORMAL;

}
