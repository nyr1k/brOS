#include <stdio.h>
#include <stddef.h> 

int puts(const char* str) 
{
  size_t i = 0;
  while (str[i] != '\0') {
    putchar(str[i]);
    i++; 
  }
  putchar('\n');
  return 0; 
}
