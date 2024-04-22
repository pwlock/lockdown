/* buddy.h
   Purpose: implementation of malloc */
#pragma once

#define __need_size_t
#include <stddef.h>

void bdyinit();

void bdyalloc(size_t size);
