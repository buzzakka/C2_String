#include "s21_string.h"

char *s21_strpbrk(const char *str1, const char *str2) {
  char *check;
  char *str2_tmp = (char *)str2;
  int result = 0;
  for (; *str1 != '\0' && result == 0; str1++) {
    for (; *str2_tmp != '\0' && result == 0; str2_tmp++) {
      if (*str1 == *str2_tmp) {
        check = (char *)str1;
        result = 1;
      }
    }
    str2_tmp = (char *)str2;
  }
  if (result == 0) {
    check = s21_NULL;
  }
  return check;
}