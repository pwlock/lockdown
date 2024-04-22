/* syscall.s
   Purpose: System call caller */

.section .text

.global SystemCall
SystemCall:
    push %rbx
    mov %rdi, %rax
    mov %rsi, %rbx 
    /* RDX is already in its place! */
    push %r8
    xchg %r8, %rcx
    pop %r9

    syscall
    pop %rbx
    retq
