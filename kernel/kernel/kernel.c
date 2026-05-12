#include <kernel/tty.h>

void kernel_main(void) 
{
  /* Initialize terminal interface */
  terminal_initialize();
  
  for(int i = 0; i < 15; i++) 
    terminal_write_string("Hello, bro teams!\n");
}





