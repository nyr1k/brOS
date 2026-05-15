#include <kernel/tty.h>
#include <arch/i386/gdt.h>
#include <stdio.h>
#include <string.h>


#include <stdint.h>

void kernel_main(void) 
{
  /* Initialize terminal interface */
  terminal_initialize();
 
  gdt_init(); 
  printf("GDT is set\n");

  printf("Hello World from brOS\n");
  
  printf("erasik karasyk\n");
  printf("arslanini bituzini\n");
}





