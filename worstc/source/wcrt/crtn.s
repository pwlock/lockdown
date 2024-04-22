/* crtn.s 
   Purpose: Global ctors finish stub */

.section .init
   popq %rbp
   ret

.section .fini
   popq %rbp
   ret

