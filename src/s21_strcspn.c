#include "s21_string.h"

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  int str1_size = s21_strlen(str1);
  int str2_size = s21_strlen(str2);
  int check = 0;
  s21_size_t count = 0;
  for (int i = 0; i < str1_size && check == 0; i++) {
    for (int j = 0; j < str2_size && check == 0; j++) {
      if (str1[i] == str2[j]) {
        check = 1;
      }
    }
    if (check != 1) {
      count++;
    }
  }
  return count;
}