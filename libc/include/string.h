#ifndef _STRING_H
#define _STRING_H 1

#include <sys/cdefs.h>

#include <stddef.h>

#ifdef __cplusplus
#define _Restrict
extern "C" {
#else 
#define _Restrict restrict 
#endif

size_t strlen(const char* str);
void* memset(void* ptr, int value, size_t num);
void* memcpy(void* _Restrict destination, const void* _Restrict source, size_t num);

#ifdef __cplusplus
}
#endif

#endif
