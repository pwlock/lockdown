/* log.c
   Purpose: the definition of log. */
#include <math.h>

#include "__logX.c"

#define LOG_FUN logf
#define LOG_TYPE float
#include "__logX.c"

#define LOG_FUN logl
#define LOG_TYPE long double
#include "__logX.c"
