#include "s21_string.h"

s21_size_t s21_strspn(const char *str1, const char *str2) {
  int str2_size = s21_strlen(str2);
  s21_size_t count = 0;
  int revert_counter = str2_size;

  for (int i = 0, j = str2_size; i < str2_size; i++, j--) {
    if (str1[i] == str2[i])
      count++;
    else if (str1[i] == str2[--revert_counter])
      count++;
    else
      break;
  }
  return count;
}
