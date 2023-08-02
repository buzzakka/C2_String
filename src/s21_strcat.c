#include "s21_string.h"

char *s21_strcat(char *dest, const char *src) {
  int dest_length = s21_strlen(dest);
  int i = 0;
  while (*(src + i) != '\0') {
    *(dest + dest_length + i) = *(src + i);
    i++;
  }
  *(dest + dest_length + i) = '\0';
  return dest;
}
