#include <string.h> 

void* memset(void* ptr, int value, size_t num) 
{
  unsigned char* uc_ptr = (unsigned char*) ptr;
  unsigned char c = (unsigned char) value;
  for (; num; num--, uc_ptr++) {
    *uc_ptr = c;
  }
  return ptr;
}
