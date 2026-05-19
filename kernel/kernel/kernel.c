#include <kernel/tty.h>
#include <arch/i386/gdt.h>
#include <arch/i386/idt.h>
#include <stdio.h>
#include <string.h>


#include <stdint.h>

void kernel_main(void) 
{
  /* Initialize terminal interface */
  terminal_initialize();
 
  gdt_init(); 
  printf("GDT is set\n"); 
  idt_init();
  printf("IDT is set\n");

  printf("Hello World from brOS\n");
    
  /* Check if the IDT works */ 
  for (int i = 0; i < 10; i++) {
    if (i == 5) {
      printf("%d", i/0);
    }
    printf("%d\n", i);
  }
}





