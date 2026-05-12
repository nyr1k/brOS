#ifndef __STDIO_H
#define __STDIO_H 1

#include <sys/cdefs.h>

#define EOF (-1)

#ifdef __cplusplus
extern "C" {
#endif

int putchar(int character); 
int puts(const char* str);
int printf(const char* format, ...);

#ifdef __cplusplus
}
#endif

#endif
