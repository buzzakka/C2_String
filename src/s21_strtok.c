#include "s21_string.h"

char *s21_strtok(char *str, const char *delim) {
  int result = 0;
  char *check;
  static char *string;
  if (str != s21_NULL) {
    string = str;
  }
  static char buffer[2048];
  *buffer = s21_NULL;
  char *tmp = buffer;
  char *tmp_delim = (char *)delim;
  while (*string != s21_NULL && result != 1) {
    while (!result && *tmp_delim != s21_NULL) {
      if (*string == *tmp_delim) {
        if (buffer[0] == s21_NULL) {
          result = 2;
        } else {
          result = 1;
        }
      } else {
        result = 0;
      }
      ++tmp_delim;
    }
    tmp_delim = (char *)delim;
    if (result == 0) {
      *tmp = *string;
      ++tmp;
    }
    if (result == 2) {
      result = 0;
    }
    ++string;
  }
  if (buffer[0] != s21_NULL) {
    check = buffer;
  } else {
    check = s21_NULL;
  }
  return check;
}
