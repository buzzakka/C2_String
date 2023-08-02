#include "s21_string.h"

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  s21_size_t i = 0;

  char *non_const_str1 = (char *)str1;
  char *non_const_str2 = (char *)str2;

  while (*non_const_str1 != '\0' || *non_const_str2 != '\0') {
    if (*(non_const_str1) != *(non_const_str2) || (i >= n - 1) || n == 0) {
      break;
    }
    ++non_const_str1;
    ++non_const_str2;
    i++;
  }

  return *non_const_str1 - *non_const_str2;
}