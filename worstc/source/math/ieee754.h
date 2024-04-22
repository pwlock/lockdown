/* ieee754.h 
   Purpose: Macros for implementing math functions 
            requirements using IEEE 754.
*/
#pragma once

#define I754_EXPONENT32_MASK (0xFF << 23)
#define I754_GET_EXPONENT32(F) (((F) & I754_EXPONENT32_MASK) >> 23)
#define I754_GET_FRACTION32(F) ((F) & 0x7fffff)

#define I754_EXPONENT64_MASK (0x7FF << 53)
#define I754_GET_EXPONENT64(F) (((F) & I754_EXPONENT64_MASK) >> 53)
#define I754_GET_FRACTION64(F) ((F) & 0x1fffffffffffff)
