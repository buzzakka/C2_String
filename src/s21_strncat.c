#include "s21_string.h"

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  int dest_length = s21_strlen(dest);
  s21_size_t i = 0;
  while ((*(src + i) != '\0')) {
    if (i == n) {
      break;
    }
    *(dest + dest_length + i) = *(src + i);
    i++;
  }
  *(dest + dest_length + i) = '\0';
  return dest;
}