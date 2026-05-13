#include <string.h> 

void* memcpy(void* restrict destination, const void* restrict source, size_t num) 
{
  unsigned char* dst = (unsigned char*) destination;
  const unsigned char* src = (const unsigned char*) source;
  for (; num; num--, dst++, src++) {
    *dst= *src; 
  }
  return destination; 
}
