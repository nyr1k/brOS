#include <stdio.h>
#include <string.h>
#include <stddef.h> 
#include <stdarg.h> 
#include <limits.h>
#include <stdbool.h> 

static bool print(const char* str, size_t len) 
{
  const unsigned char* data = (const unsigned char*) str;
  for (size_t i = 0; i < len; i++) {
    if (putchar(data[i]) == EOF) {
      return false;
    }
  }
  return true;
}

int printf(const char* format, ...) 
{
  va_list args; 
  va_start(args, format);

  int written = 0; 

  while (*format != '\0') {
    int maxrem = INT_MAX - written;

    if (format[0] != '%' || format[1] == '%') {
      if (format[0] == '%') {
        format++;
      }
      size_t amount = 1; 
      while (format[amount] != '\0' && format[amount] != '%') {
        amount++;
      }
      if (maxrem < 0 || maxrem < amount) {
        return -1;
      }
      if (!print(format, amount)) {
        return -1;
      }
      format += amount;
      written += amount;
      continue; 
    }
  
    format++;
    if (*format == 'c') {
      format++;
      const char c = (char) va_arg(args, int);
      if (!maxrem) {
        return -1;
      }
      if (!print(&c, sizeof(c))) {
        return -1;
      }
      written++;
    } else if (*format == 's') {
      format++;
      const char* str = va_arg(args, const char*);
      size_t len = strlen(str);
      if (!maxrem) {
        return -1;
      }
      if (!print(str, len)) {
        return -1;
      }
      written += len;
    } else {
      char str[3] = {'%', *format, '\0'};
      if (maxrem < 2) {
        return -1;
      }
      if (!print(str, 2)) {
        return -1;
      }
      format++;
      written += 2; 
    }
  } 
  
  va_end(args);
  return written;
}
