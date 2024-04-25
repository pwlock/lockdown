/* abs.c
   Purpose: the implementation of fabs{,f,l} */
#include "math.h"

double fabs(double _x)
{
    return _x < 0 ? _x * -1 : _x;
}

float fabsf(float _x)
{
    return _x < 0 ? _x * -1 : _x;
}

long double fabsl(long double _x)
{
    return _x < 0 ? _x * -1 : _x;
}

