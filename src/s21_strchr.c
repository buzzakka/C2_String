#include "s21_string.h"

char *s21_strchr(const char *str, int c) {
  char *check;
  while (*str != c && *str != '\0') {
    str++;
  }
  if (*str == c) {
    check = (char *)str;
  } else {
    check = s21_NULL;
  }
  return check;
}