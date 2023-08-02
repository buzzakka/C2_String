#include "s21_string.h"

char *s21_strrchr(const char *str, int c) {
  char *check;
  while (*str != '\0') {
    if (*str == c) {
      check = (char *)str;
    }
    str++;
  }
  if (*check != c) {
    check = s21_NULL;
  }
  return check;
}