#include "s21_string.h"

char *s21_strstr(const char *haystack, const char *needle) {
  if (s21_strlen(haystack) >= s21_strlen(needle)) {
    for (s21_size_t i = 0; i <= s21_strlen(haystack) - s21_strlen(needle);
         i++) {
      int found = 1;
      for (s21_size_t j = i, k = 0; needle[k]; k++, j++) {
        if (haystack[j] != needle[k]) {
          found = 0;
          break;
        }
      }
      if (found) {
        return (char *)haystack + i;
      }
    }
  }
  return s21_NULL;
}
