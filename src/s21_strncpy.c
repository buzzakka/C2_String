#include "s21_string.h"

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  char *ptr = dest;
  s21_size_t count = 0;
  if (dest != s21_NULL) {
    while (*src != s21_NULL && count < n) {
      *dest = *src;
      ++dest;
      ++src;
      count++;
    }
    *dest = '\0';
  } else {
    ptr = s21_NULL;
  }
  return ptr;
}