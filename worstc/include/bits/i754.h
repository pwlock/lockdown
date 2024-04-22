/* i754.h
   Purpose: Structs for IEEE 754 */
#pragma once

union __i754_float32
{
   float Value;
   unsigned int Raw;
};

union __i754_float64
{
   double Value;
   unsigned long Raw;
};
