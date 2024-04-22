/* start.c
   Purpose: Generic startup code */
#include "power/system.h"
#include <stdlib.h>
#include <lockdown.h>

void __wc_begin(void* main) 
{
    __asm__ volatile("xchg %bx, %bx");
    int stdout = OpenFile("?STDOUT", 0);
}
