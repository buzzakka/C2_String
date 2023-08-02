#include "s21_string.h"

void *s21_memchr(const void *str, int c, s21_size_t n) {
  char *res = s21_NULL;

  for (s21_size_t i = 0; i < n; i++) {
    if (*((char *)str + i) == c) {
      res = ((char *)str + i);
      break;
    }
  }

  return res;
}