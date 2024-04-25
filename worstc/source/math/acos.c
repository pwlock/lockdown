/* acos.c
   Purpose: The definition of acos{,f,l} */
#include "__acosX.c"

#define ACOS_FUN acosf
#define ACOS_TYPE float

#include "__acosX.c"

#define ACOS_FUN acosl
#define ACOS_TYPE long double

#include "__acosX.c"
