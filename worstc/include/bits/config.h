/* config.h
   Purpose: Macros used throught the library */
#pragma once

#ifndef __WC_BITS_CONFIG_H
#define __WC_BITS_DFS_H

#ifdef __STDC__
    #define __restrict restrict
    #define _HAS_C89
    #if defined(__STDC_VERSION__)
        #define _HAS_C99
    #elif __STDC_VERSION__ >= 199901L
        #define _HAS_C11
    #elif __STDC_VERSION__ >= 201112L
        #define _HAS_C17
    #elif __STDC_VERSION >= 201710L
        #define _HAS_C23
    #endif
#else
    #ifdef __cplusplus
        #if __cplusplus > 199711L
            #define _HAS_C11
        #elif __cplusplus > 201103L
            #define _HAS_C17
        #elif __cplusplus > 201703L
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

#endif  /* __WC_BITS_CONFIG_H */
