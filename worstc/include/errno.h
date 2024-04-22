/* errno.h
   Purpose: error signaling */
#pragma once

#define errno (*_get_errno())

extern int*
_get_errno();
