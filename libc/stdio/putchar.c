#include <stdio.h>

#if __is_libk
#include <kernel/tty.h>
#endif

int putchar(int character) 
{
#if __is_libk
  unsigned char c = (unsigned char) character;
  terminal_put_char(c);
#else 
  // TODO: userspace via syscalls 
#endif
  return character;
} 
