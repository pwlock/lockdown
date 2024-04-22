/* errno.c
   Purpose: the definitition of internal 
            errno variable and _get_errno */
#include <errno.h>

_Thread_local int __errno;
int* _get_errno()
{
    return &__errno;
}
