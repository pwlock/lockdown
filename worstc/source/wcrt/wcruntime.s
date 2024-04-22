/* wcruntime.s
  Purpose: Executable startup */

.section .text

.global _start
_start:
    movq $0, %rbp
    pushq %rbp 
    pushq %rbp
    movq %rsp, %rbp

    call main
    cli
