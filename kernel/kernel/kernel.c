#include <kernel/tty.h>
#include <stdio.h>
#include <string.h>

void kernel_main(void) 
{
  /* Initialize terminal interface */
  terminal_initialize();
  printf("Hello World from brOS\n");
  char buf[6]; 
  memset(buf, '0', 6);
  printf("%s\n", buf);
}





