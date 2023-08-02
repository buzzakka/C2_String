#include "s21_string.h"

int s21_strcmp(char const *str1, char const *str2) {
  int res = 0;

  char *non_const_str1 = (char *)str1;
  char *non_const_str2 = (char *)str2;

  while (*non_const_str1 != '\0' || *non_const_str2 != '\0') {
    if (*(non_const_str1) != *(non_const_str2)) {
      break;
    }
    ++non_const_str1;
    ++non_const_str2;
  }

  if (*non_const_str1 != *non_const_str2) {
    res = (*non_const_str1 > *non_const_str2) ? 1 : -1;
  }

  return res;
}
