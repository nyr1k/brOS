#include <stdio.h>
#include <string.h>
#include <stddef.h> 
#include <stdarg.h> 
#include <limits.h>
#include <stdbool.h> 



static char* itoa(int value, char *str,  const int base) 
{ 
  const char map[] = "0123456789ABCDEF";
  char* s = str; 
  if (base == 16) {
    *s++ = '0';
    *s++ = 'x';
  }
  
  if (value == 0) {
    *s++ = '0';
    *s++ = '\0';
    return str;
  }
  
  unsigned int u_value;
  if (value < 0 && base == 10) {
    u_value = (unsigned int) (-value);  
    *s++ = '-';
  } else {
    u_value = (unsigned int) (value); 
  }
  
  char* start = s;
  while (u_value) {
    *s++ = map[u_value%base];
    u_value /= base;
  }
  *s = '\0';
  char* end = s-1;

  while (start < end) {
    char temp = *start;
    *start = *end;
    *end = temp; 
    start++;
    end--;
  }

  return str;
}

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
      
      if (maxrem < 0 || maxrem < len) {
        return -1;
      }
      
      if (!print(str, len)) {
        return -1;
      }
      
      written += len;
    } else if (*format == 'd') {
      format++;
      char buffer [12];  
      const char* num_str = itoa(va_arg(args, int), buffer, 10);
      size_t len = strlen(num_str);
      
      if (maxrem < 0 || maxrem < len) {
        return -1;
      }

      if (!print(num_str, len)) {
        return -1;
      }

      written += len; 
    } else if (*format == 'x') {
      format++;
      char buffer [12];
      const char* hex_str = itoa(va_arg(args, int), buffer, 16);
      size_t len = strlen(hex_str);

      if (maxrem < 0 || maxrem < len) {
        return -1;
      }

      if (!print(hex_str, len)) {
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
