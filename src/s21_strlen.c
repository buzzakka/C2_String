#include "s21_string.h"

s21_size_t s21_strlen(const char *str) {
  s21_size_t count = 0;
  while (str[count] != s21_NULL) {
    count++;
  }
  if (str[0] == s21_NULL) {
    count = 0;
  }
  return count;
}
