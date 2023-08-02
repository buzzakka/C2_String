#include "s21_string.h"

char *s21_strcpy(char *dest, const char *src) {
  char *ptr = dest;
  if (dest != s21_NULL) {
    while (*src != s21_NULL) {
      *dest = *src;
      ++dest;
      ++src;
    }
    *dest = '\0';
  } else {
    ptr = s21_NULL;
  }
  return ptr;
}