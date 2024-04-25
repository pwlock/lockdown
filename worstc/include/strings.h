/* strings.h
   Purpose: String operations */
#pragma once

#ifndef __STRINGS_H
#define __STRINGS_H 1

#include "bits/config.h"

__WC_EXTERN_C_BEGIN

/* Find the first bit set in num. */
extern int ffs(int _num);
extern int ffsl(long _num);

__WC_EXTERN_C_END

#endif

