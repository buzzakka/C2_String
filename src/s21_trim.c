#include "s21_string.h"

int hasCharInArr(char needle, char *haystack);

void *s21_trim(const char *src, const char *trim_chars) {
  char *res_str = s21_NULL;
  int left_trim_len = 0, right_trim_len = 0;
  int src_len = s21_strlen(src);

  for (int i = 0; (*src + i); i++) {
    if (hasCharInArr(*(src + i), (char *)trim_chars))
      left_trim_len++;
    else
      break;
  }

  for (int i = src_len - 1; i >= left_trim_len; i--) {
    if (hasCharInArr(*(src + i), (char *)trim_chars))
      right_trim_len++;
    else
      break;
  }

  int res_str_len = src_len - left_trim_len - right_trim_len;
  res_str = (char *)malloc(sizeof(char *) * res_str_len);

  if (res_str)
    for (int i = left_trim_len, j = 0; j < res_str_len; i++, j++)
      res_str[j] = src[i];

  res_str[res_str_len] = '\0';

  return res_str;
}

int hasCharInArr(char needle, char *haystack) {
  while (*haystack != '\0')
    if ((*haystack) == needle) {
      return 1;
    } else {
      haystack++;
    }
  return 0;
}
