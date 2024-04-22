/* math.h
   Purpose: Mathematical functions. */
#pragma once

#include "bits/config.h"
#include "bits/i754.h"

#ifndef __MATH_H
#define __MATH_H 1

#define FP_INFINITE  (1 << 0)
#define FP_NAN       (1 << 1)
#define FP_NORMAL    (1 << 2)
#define FP_SUBNORMAL (1 << 3)
#define FP_ZERO      (1 << 4)

extern int __fpclassifyf32(float _f);
extern int __fpclassifyf64(double _f);

#define fpclassify(X) \
    sizeof(X) == sizeof(float) ? __fpclassifyf32(X) : __fpclassifyf64(X)

#define isfinite(X) (fpclassify(X) & ~(FP_NAN | FP_INFINITE))
#define isnormal(X) (fpclassify(X) == FP_NORMAL)
#define isnan(X)       (fpclassify(X) == FP_NAN)
#define isinf(X)       (fpclassify(X) == FP_INFINITE)

inline int __extract_signbit_32(float _x)
{
    union __i754_float32 __flt;
    __flt.Value = _x;
    return __flt.Raw & (1 << 31);
}

inline int __extract_signbit_64(double _x)
{
    union __i754_float64 __flt;
    __flt.Value = _x;
    return (__flt.Raw & ((unsigned long)1 << 63)) >> 63;
}

#ifdef __STDC_WANT_IEC_60559_BFP_EXT__
/* TODO: issignaling */
#define issubnormal(X) (fpclassify(X) == FP_SUBNORMAL)
#define iszero(X)      (fpclassify(X) == FP_ZERO)
#endif /* defined(WANT FP TS)*/

#if __has_builtin(__builtin_signbit)
#define signbit(X) __builtin_signbit(X)
#else
#define signbit(X) sizeof(X) == sizeof(float) \
    ? __extract_signbit_32(X) \
    : __extract_signbit_64(X)
#endif /* __has_builtin(__builtin_signbit) */



#endif
