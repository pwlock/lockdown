/* stdout.c
   Purpose: the definition of std{err,out,in} */
#include "stdio.h"
#include "bits/FILE.h"
#include <stddef.h>

static FILE _stdout_inner = {
    NULL, 0, 0, 0, NULL, __FBUFFERING_LINE, 0, __FILE_WRITE_ONLY | __FILE_STATIC
};

static FILE _stdin_inner = {
    NULL, 0, 0, 0, __FBUFFERING_NONE, 1, __FILE_STATIC
};

static FILE _stderr_inner = {
    NULL, 0, 0, 0, NULL, __FBUFFERING_NONE, 2, __FILE_STATIC
};

FILE* stdout = &_stdout_inner;
FILE* stdin = &_stdin_inner;
FILE* stderr = &_stderr_inner;
