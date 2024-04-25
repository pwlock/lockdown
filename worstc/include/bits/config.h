/* config.h
   Purpose: Macros used throught the library */
#pragma once

#ifndef __WC_BITS_CONFIG_H
#define __WC_BITS_DFS_H

#ifdef __STDC__
    #define __WC_EXTERN_C_BEGIN
    #define __WC_EXTERN_C_END

    #define __restrict restrict
    #define _HAS_C89

    #if defined(__STDC_VERSION__)
        #define _HAS_C99
    #endif

    #if __STDC_VERSION__ > 199901L
        #define _HAS_C11
    #endif

    #if __STDC_VERSION__ > 201112L
        #define _HAS_C17
    #endif

    #if __STDC_VERSION > 201710L
        #define _HAS_C23
    #endif
#else
    #define __WC_EXTERN_C_BEGIN extern "C" {
    #define __WC_EXTERN_C_END   }
    #ifdef __cplusplus
        #if __cplusplus > 199711L
            #define _HAS_C11
        #endif

        #if __cplusplus > 201103L
            #define _HAS_C17
        #endif

        #if __cplusplus > 201703L
            #define _HAS_C23
        #endif
    #endif
#endif

#ifdef _HAS_C23
#define __STDC_WANT_IEC_60559_BFP_EXT__
#endif

#ifndef __has_builtin
#define __has_builtin(B) 0
#endif

#ifdef __GNUC__
#define __WC_GNU_VERSION (__GNUC__ * 100) + __GNUC_MINOR__
#else
#define __WC_GNU_VERSION 0
#endif

#ifdef __FAST_MATH__
#define WC_WANT_FAST_MATH
#endif

#if defined(__GNUC__) || defined(__clang__)
#define __WC_alias(S) __attribute__((alias((S))))
#define __WC_ALIAS_WORKS
#else
#define __WC_alias(S)
#endif

#endif  /* __WC_BITS_CONFIG_H */
