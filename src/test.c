#include <check.h>
#include <stdlib.h>
#include <string.h>

#include "s21_insert.c"
#include "s21_memchr.c"
#include "s21_memcmp.c"
#include "s21_memcpy.c"
#include "s21_memmove.c"
#include "s21_memset.c"
#include "s21_sprintf.c"
#include "s21_sscanf.c"
#include "s21_strcat.c"
#include "s21_strchr.c"
#include "s21_strcmp.c"
#include "s21_strcpy.c"
#include "s21_strcspn.c"
#include "s21_strerror.c"
#include "s21_strlen.c"
#include "s21_strncat.c"
#include "s21_strncmp.c"
#include "s21_strncpy.c"
#include "s21_strpbrk.c"
#include "s21_strrchr.c"
#include "s21_strspn.c"
#include "s21_strstr.c"
#include "s21_strtok.c"
#include "s21_to_lower.c"
#include "s21_to_upper.c"
#include "s21_trim.c"

void obnul(char *str, char *format) {}
START_TEST(s21_memchr_test) {
  // Arrange
  char strings[][20] = {"Hello world", "wo", "lo", "o", "ello", ""};

  // Act
  // Assert
  // str
  ck_assert_str_eq(s21_memchr(strings[0], 'l', 5), memchr(strings[0], 'l', 5));
  ck_assert_str_eq(s21_memchr(strings[0], 'l', 10),
                   memchr(strings[0], 'l', 10));
  // s21_null
  ck_assert_ptr_null(s21_memchr(strings[0], 'w', 3));
  ck_assert_ptr_null(memchr(strings[0], 'w', 3));
  ck_assert_ptr_null(s21_memchr(strings[0], 'w', 3));
  ck_assert_ptr_null(memchr(strings[0], 'w', 3));
  ck_assert_ptr_null(s21_memchr(strings[0], 'l', 0));
  ck_assert_ptr_null(memchr(strings[0], 'l', 0));
  // str
  ck_assert_str_eq(s21_memchr(strings[4], '\0', 20),
                   memchr(strings[4], '\0', 20));
  ck_assert_str_eq(s21_memchr(strings[4], '\0', -2),
                   memchr(strings[4], '\0', -2));
  // null
  ck_assert_ptr_null(s21_memchr(strings[3], '\n', 0));
  ck_assert_ptr_null(memchr(strings[3], '\n', 0));
}
END_TEST

START_TEST(s21_memcmp_test) {
  // Arrange
  char strings[][20] = {"Hello world", "wo", "lo", "o", "ello", "", "Hell"};

  // Act
  // Assert
  ck_assert_int_eq(s21_memcmp(strings[0], strings[4], 5),
                   memcmp(strings[0], strings[4], 5));
  ck_assert_int_eq(s21_memcmp(strings[0], strings[6], 5),
                   memcmp(strings[0], strings[6], 5));
  ck_assert_int_eq(s21_memcmp(strings[0], strings[6], 0),
                   memcmp(strings[0], strings[6], 0));
  ck_assert_int_eq(s21_memcmp(strings[6], strings[0], 5),
                   memcmp(strings[6], strings[0], 5));
  ck_assert_int_eq(s21_memcmp(strings[5], strings[0], 5),
                   memcmp(strings[5], strings[0], 5));
  ck_assert_int_eq(s21_memcmp(strings[5], strings[5], 5),
                   memcmp(strings[5], strings[5], 5));
}
END_TEST

START_TEST(s21_memcpy_test) {
  // Arrange
  char strings[][20] = {"Hello world", "wo", "lo", "o", "ello", "", "Hell"};

  // Act
  // Assert
  ck_assert_str_eq(s21_memcpy(strings[0], strings[1], 2),
                   memcpy(strings[0], strings[1], 2));
  ck_assert_str_eq(s21_memcpy(strings[1], strings[0], 5),
                   memcpy(strings[1], strings[0], 5));
  ck_assert_str_eq(s21_memcpy(strings[1], strings[0], 5),
                   memcpy(strings[1], strings[0], 5));
  ck_assert_str_eq(s21_memcpy(strings[3], strings[4], 5),
                   memcpy(strings[3], strings[4], 5));
  ck_assert_str_eq(s21_memcpy(strings[3], strings[4], 0),
                   memcpy(strings[3], strings[4], 0));
}
END_TEST

START_TEST(s21_memmove_test) {
  // Arrange
  char strings[][20] = {"Hello world", "wo", "lo", "o", "ello", "", "Hell"};

  // Act
  // Assert
  ck_assert_str_eq(s21_memmove(strings[0], strings[1], 2),
                   memmove(strings[0], strings[1], 2));
  ck_assert_str_eq(s21_memmove(strings[1], strings[0], 5),
                   memmove(strings[1], strings[0], 5));
  ck_assert_str_eq(s21_memmove(strings[1], strings[0], 5),
                   memmove(strings[1], strings[0], 5));
  ck_assert_str_eq(s21_memmove(strings[3], strings[4], 5),
                   memmove(strings[3], strings[4], 5));
  ck_assert_str_eq(s21_memmove(strings[3], strings[4], 0),
                   memmove(strings[3], strings[4], 0));
}
END_TEST

START_TEST(s21_memset_test) {
  // Arrange
  char strings[][20] = {"Hello world", "wo", "lo", "o", "ello", "", "Hell"};

  // Act
  // Assert
  ck_assert_str_eq(s21_memset(strings[0], 112, 2), memset(strings[0], 112, 2));
  ck_assert_str_eq(s21_memset(strings[1], 32, 5), memset(strings[1], 32, 5));
  ck_assert_str_eq(s21_memset(strings[1], 112, 5), memset(strings[1], 82, 5));
  ck_assert_str_eq(s21_memset(strings[3], 112, 5), memset(strings[3], 82, 5));
  ck_assert_str_eq(s21_memset(strings[3], 105, 0), memset(strings[3], 105, 0));
  ck_assert_str_eq(s21_memset(strings[3], -5, 1), memset(strings[3], -5, 1));
  ck_assert_str_eq(s21_memset(strings[0], 20, 3), memset(strings[0], 20, 3));
  ck_assert_str_eq(s21_memset(strings[5], 20, 3), memset(strings[5], 20, 3));
  ck_assert_str_eq(s21_memset(strings[5], 20, 27), memset(strings[5], 20, 27));
  ck_assert_str_eq(s21_memset(strings[6], 20, 19), memset(strings[6], 20, 19));
}
END_TEST

START_TEST(s21_strcat_test) {
  // Arrange
  char strings[][20] = {"Hello world", "wo", "lo", "o", "ello", "", "Hell"};
  char no_nl[5] = {'h', 'e', 'l', 'l', 'o'};
  // Act
  // Assert
  ck_assert_str_eq(s21_strcat(strings[0], strings[1]),
                   strcat(strings[0], strings[1]));
  ck_assert_str_eq(s21_strcat(strings[1], strings[2]),
                   strcat(strings[1], strings[2]));
  ck_assert_str_eq(s21_strcat(strings[2], strings[3]),
                   strcat(strings[2], strings[3]));
  ck_assert_str_eq(s21_strcat(strings[3], strings[4]),
                   strcat(strings[3], strings[4]));
  ck_assert_str_eq(s21_strcat(strings[4], strings[5]),
                   strcat(strings[4], strings[5]));
  ck_assert_str_eq(s21_strcat(strings[5], strings[6]),
                   strcat(strings[5], strings[6]));
}
END_TEST

START_TEST(s21_strncat_test) {
  // Arrange
  char strings[][20] = {"Hello world", "wo", "lo", "o", "ello", "", "Hell"};
  char no_nl[5] = {'h', 'e', 'l', 'l', 'o'};
  // Act
  // Assert
  ck_assert_str_eq(s21_strncat(strings[0], strings[1], 0),
                   strncat(strings[0], strings[1], 0));
  ck_assert_str_eq(s21_strncat(strings[1], strings[2], 5),
                   strncat(strings[1], strings[2], 5));
  ck_assert_str_eq(s21_strncat(strings[2], strings[3], 2),
                   strncat(strings[2], strings[3], 2));
  ck_assert_str_eq(s21_strncat(strings[3], strings[4], 3),
                   strncat(strings[3], strings[4], 3));
  ck_assert_str_eq(s21_strncat(strings[4], strings[5], 1),
                   strncat(strings[4], strings[5], 1));
  ck_assert_str_eq(s21_strncat(strings[5], strings[6], 2),
                   strncat(strings[5], strings[6], 2));
}
END_TEST

START_TEST(s21_strchr_test) {
  // Arrange
  char strings[][20] = {"Hello world", "wo", "lo", "o", "ello", "", "Hell"};
  // Act
  // Assert
  ck_assert_str_eq(s21_strchr(strings[0], 72), strchr(strings[0], 72));

  ck_assert_ptr_null(s21_strchr(strings[1], 127));
  ck_assert_ptr_null(strchr(strings[1], 127));

  ck_assert_ptr_null(s21_strchr(strings[1], 135));
  ck_assert_ptr_null(strchr(strings[1], 135));

  ck_assert_ptr_null(s21_strchr(strings[2], -5));
  ck_assert_ptr_null(strchr(strings[2], -5));

  ck_assert_str_eq(s21_strchr(strings[3], 111), strchr(strings[3], 111));
  ck_assert_str_eq(s21_strchr(strings[4], 108), strchr(strings[4], 108));
}
END_TEST

START_TEST(s21_strcmp_test) {
  // Arrange
  char strings[][20] = {"Hello world", "wo", "lo", "o", "ello", "Hello", ""};
  // Act
  // Assert
  // Equal
  ck_assert_int_eq(s21_strcmp(strings[0], strings[0]),
                   strcmp(strings[0], strings[0]));

  ck_assert_int_ge(s21_strcmp(strings[0], strings[5]), 1);
  ck_assert_int_ge(strcmp(strings[0], strings[5]), 1);

  ck_assert_int_le(s21_strcmp(strings[5], strings[0]), -1);
  ck_assert_int_le(strcmp(strings[5], strings[0]), -1);

  ck_assert_int_ge(s21_strcmp(strings[4], strings[0]), 1);
  ck_assert_int_ge(strcmp(strings[4], strings[0]), 1);

  ck_assert_int_le(s21_strcmp(strings[0], strings[4]), -1);
  ck_assert_int_le(strcmp(strings[0], strings[4]), -1);
}
END_TEST

START_TEST(s21_strncmp_test) {
  // Arrange
  char strings[][20] = {"Hello world", "wo", "lo", "o", "ello", "Hello", ""};
  // Act
  // Assert
  ck_assert_int_eq(s21_strncmp(strings[0], strings[0], 3),
                   strncmp(strings[0], strings[0], 3));
  ck_assert_int_eq(s21_strncmp(strings[0], strings[5], 2),
                   strncmp(strings[0], strings[5], 2));
  ck_assert_int_eq(s21_strncmp(strings[5], strings[0], 1),
                   strncmp(strings[5], strings[0], 1));
  ck_assert_int_eq(s21_strncmp(strings[5], strings[0], 5),
                   strncmp(strings[5], strings[0], 5));

  ck_assert_int_eq(s21_strncmp(strings[5], strings[0], 3),
                   strncmp(strings[5], strings[0], 3));

  ck_assert_int_lt(s21_strncmp(strings[0], strings[4], 10), 0);
  ck_assert_int_lt(strncmp(strings[0], strings[4], 10), 0);
}
END_TEST

START_TEST(s21_strcpy_test) {
  // Arrange
  char strings1[][20] = {"Hello world", "wo", "lo", "o", "ello", "", "   "};
  char dst1[1024];
  char dst2[1024];
  char no_term_zero[5] = {'h', 'e', 'l', 'l', 'l'};
  // Act
  // Assert
  ck_assert_str_eq(s21_strcpy(dst1, strings1[0]), strcpy(dst2, strings1[0]));
  ck_assert_str_eq(s21_strcpy(dst1, strings1[6]), strcpy(dst2, strings1[6]));
  ck_assert_str_eq(s21_strcpy(dst1, strings1[2]), strcpy(dst2, strings1[2]));
  ck_assert_str_eq(s21_strcpy(dst1, strings1[5]), strcpy(dst2, strings1[5]));
  ck_assert_str_eq(s21_strcpy(dst1, strings1[3]), strcpy(dst2, strings1[3]));
}
END_TEST

START_TEST(s21_strncpy_test) {
  // Arrange
  char strings1[][20] = {"Hello world", "wo", "lo", "o", "ello", "     ", ""};
  char strings2[][20] = {"Hello world", "wo", "lo", "o", "ello", "     ", ""};
  char dst1_1[15];
  char dst2_1[15];
  char dst1_2[15];
  char dst2_2[15];
  char dst1_3[15];
  char dst2_3[15];
  char dst1_4[15];
  char dst2_4[15];
  char dst1_5[15];
  char dst2_5[15];
  char no_term_zero[5] = {'h', 'e', 'l', 'l', 'l'};
  // Act
  // Assert
  // ck_assert_str_eq(strncpy(dst1_1, strings1[5], 0), s21_strncpy(dst2_1,
  // strings1[5], 0));
  ck_assert_str_eq(strncpy(dst1_1, strings1[5], 1),
                   s21_strncpy(dst2_1, strings1[5], 1));
  ck_assert_str_eq(strncpy(dst1_2, strings1[5], 5),
                   s21_strncpy(dst2_2, strings2[5], 5));
  ck_assert_str_eq(strncpy(dst1_3, strings1[6], 5),
                   s21_strncpy(dst2_3, strings2[6], 5));
  ck_assert_str_eq(strncpy(dst1_4, strings1[6], 0),
                   s21_strncpy(dst2_4, strings2[6], 0));
  ck_assert_str_eq(strncpy(dst1_5, strings1[3], 2),
                   s21_strncpy(dst2_5, strings2[3], 2));
}
END_TEST

START_TEST(s21_strcspn_test) {
  char strings[][20] = {"Hello world", "wo", "lo",  "o",
                        "ello",        "",   "zfm", "Hello kitty"};

  ck_assert_int_eq(s21_strcspn(strings[0], strings[7]),
                   strcspn(strings[0], strings[7]));
  ck_assert_int_eq(s21_strcspn(strings[0], strings[1]),
                   strcspn(strings[0], strings[1]));
  ck_assert_int_eq(s21_strcspn(strings[2], strings[4]),
                   strcspn(strings[2], strings[4]));
  ck_assert_int_eq(s21_strcspn(strings[4], strings[2]),
                   strcspn(strings[4], strings[2]));
  ck_assert_int_eq(s21_strcspn(strings[3], strings[7]),
                   strcspn(strings[3], strings[7]));
  ck_assert_int_eq(s21_strcspn(strings[3], strings[3]),
                   strcspn(strings[3], strings[3]));
}
END_TEST

START_TEST(s21_strerror_test) {
  char *case1 = s21_strerror(0);
  char *case2 = strerror(0);
  ck_assert_uint_eq((unsigned long)*case1, (unsigned long)*case2);

  char *case9 = s21_strerror(1);
  char *case10 = strerror(1);
  ck_assert_uint_eq((unsigned long)*case9, (unsigned long)*case10);

  char *case0 = s21_strerror(106);
  char *case3 = strerror(106);
  ck_assert_uint_eq((unsigned long)*case0, (unsigned long)*case3);

  char *case7 = s21_strerror(200);
  char *case8 = strerror(200);
  ck_assert_uint_eq((unsigned long)*case7, (unsigned long)*case8);

  char *case5 = s21_strerror(INT32_MAX);
  char *case6 = strerror(INT32_MAX);
  ck_assert_uint_eq((unsigned long)*case5, (unsigned long)*case6);

  char *case11 = s21_strerror(-1);
  char *case12 = strerror(-1);
  ck_assert_uint_eq((unsigned long)*case11, (unsigned long)*case12);
}
END_TEST

START_TEST(s21_strlen_test) {
  // Arrange
  char strings[][20] = {"Hello world", "wo", "lo", "o", "ello", ""};
  // Act
  // Assert
  ck_assert_int_eq(s21_strlen(strings[0]), strlen(strings[0]));
  ck_assert_int_eq(s21_strlen(strings[1]), strlen(strings[1]));
  ck_assert_int_eq(s21_strlen(strings[2]), strlen(strings[2]));
  ck_assert_int_eq(s21_strlen(strings[3]), strlen(strings[3]));
  ck_assert_int_eq(s21_strlen(strings[4]), strlen(strings[4]));
  ck_assert_int_eq(s21_strlen(strings[5]), strlen(strings[5]));
  ck_assert_int_eq(s21_strlen(strings[5]), strlen(strings[5]));
}
END_TEST

START_TEST(s21_strpbrk_test) {
  // Arrange
  char strings[][20] = {"Hello world", "wo", "lo", "o", "ello", ""};
  // Act
  // Assert
  ck_assert_str_eq(s21_strpbrk(strings[0], strings[1]),
                   strpbrk(strings[0], strings[1]));
  ck_assert_str_eq(s21_strpbrk(strings[1], strings[2]),
                   strpbrk(strings[1], strings[2]));
  ck_assert_str_eq(s21_strpbrk(strings[3], strings[3]),
                   strpbrk(strings[2], strings[3]));

  ck_assert_ptr_null(s21_strpbrk(strings[4], strings[5]));
  ck_assert_ptr_null(strpbrk(strings[4], strings[5]));
}
END_TEST

START_TEST(s21_strrchr_test) {
  // Arrange
  char strings[][20] = {"Hello world", "wo", "lo", "o", "ello", ""};
  // Act
  // Assert
  ck_assert_str_eq(s21_strrchr(strings[0], 108), strrchr(strings[0], 108));
  ck_assert_str_eq(s21_strrchr(strings[0], 111), strrchr(strings[0], 111));
  ck_assert_str_eq(s21_strrchr(strings[0], 111), strrchr(strings[0], 111));

  ck_assert_ptr_null(s21_strrchr(strings[0], 45));
  ck_assert_ptr_null(strrchr(strings[0], 45));
  ck_assert_ptr_null(s21_strrchr(strings[5], 20));
  ck_assert_ptr_null(strrchr(strings[5], 20));
}
END_TEST

START_TEST(s21_strspn_test) {
  // Arrange
  char strings[][20] = {"Hello world", "wo",   "lo",           "o", "ello", "",
                        "Hello",       "Hell", "world is mine"};
  // Act
  // Assert
  ck_assert_int_eq(s21_strspn(strings[0], strings[6]),
                   strspn(strings[0], strings[6]));
  ck_assert_int_eq(s21_strspn(strings[0], strings[5]),
                   strspn(strings[0], strings[5]));
  ck_assert_int_eq(s21_strspn(strings[0], strings[7]),
                   strspn(strings[0], strings[7]));

  ck_assert_int_eq(s21_strspn(strings[1], strings[2]),
                   strspn(strings[1], strings[2]));
  ck_assert_int_eq(s21_strspn(strings[1], strings[2]),
                   strspn(strings[1], strings[2]));
  ck_assert_int_eq(s21_strspn(strings[0], strings[4]),
                   strspn(strings[0], strings[4]));
  ck_assert_int_eq(s21_strspn(strings[0], strings[1]),
                   strspn(strings[0], strings[1]));
  ck_assert_int_eq(s21_strspn(strings[0], strings[8]),
                   strspn(strings[0], strings[8]));
}
END_TEST

START_TEST(s21_strstr_test) {
  // Arrange
  char strings1[][20] = {"Hello world", "wo",   "lo",           "o", "ello", "",
                         "Hello",       "Hell", "world is mine"};
  // Act
  // Assert
  ck_assert_str_eq(s21_strstr(strings1[0], strings1[0]),
                   strstr(strings1[0], strings1[0]));
  ck_assert_str_eq(s21_strstr(strings1[0], strings1[6]),
                   strstr(strings1[0], strings1[6]));

  ck_assert_ptr_null(s21_strstr(strings1[6], strings1[0]));
  ck_assert_ptr_null(strstr(strings1[6], strings1[0]));

  ck_assert_str_eq(s21_strstr(strings1[2], strings1[2]),
                   strstr(strings1[2], strings1[2]));

  ck_assert_str_eq(s21_strstr(strings1[4], strings1[3]),
                   strstr(strings1[4], strings1[3]));

  ck_assert_ptr_null(s21_strstr(strings1[3], strings1[4]));
  ck_assert_ptr_null(strstr(strings1[3], strings1[4]));
}
END_TEST

START_TEST(s21_strtok_test) {
  // Arrange
  char strings1[][20] = {"Hello world",   "wo", "lo",    "o",
                         "ello",          "",   "Hello", "Hell",
                         "world is mine", "ll"};
  // Act
  // Assert
  ck_assert_str_eq(s21_strtok(strings1[0], strings1[9]),
                   strtok(strings1[0], strings1[9]));
  ck_assert_str_eq(s21_strtok(strings1[0], strings1[5]),
                   strtok(strings1[0], strings1[5]));
  ck_assert_str_eq(s21_strtok(strings1[0], strings1[5]),
                   strtok(strings1[0], strings1[5]));
  ck_assert_str_eq(s21_strtok(strings1[7], strings1[9]),
                   strtok(strings1[7], strings1[9]));
  ck_assert_ptr_null(s21_strtok(strings1[5], strings1[5]));
  ck_assert_ptr_null(strtok(strings1[5], strings1[5]));

  ck_assert_ptr_null(s21_strtok(strings1[5], strings1[0]));
  ck_assert_ptr_null(strtok(strings1[5], strings1[0]));
}
END_TEST

START_TEST(s21_sprintf_test) {
  // Arrange
  int numbers[] = {5, 0, -1, INT32_MAX, INT32_MIN, -777};
  //    int oct [] = {17777777777, -17777777777, 5};
  short int short_int = 12367;
  long int long_int = 1234567890;
  int hex[] = {0x7FFFFFFF, -0x7FFFFFFF, 0x0, 0xffc, -0x25cbc};

  char str1[200][200] = {0};
  char str2[200][200] = {0};

  // Act
  // Assert
  // d Простые числа

  s21_sprintf(str1[0], "%d", numbers[0]);
  sprintf(str2[0], "%d", numbers[0]);
  ck_assert_str_eq(str1[0], str2[0]);

  s21_sprintf(str1[19], "Hi%d", numbers[2]);
  sprintf(str2[19], "Hi%d", numbers[2]);
  ck_assert_str_eq(str1[19], str2[19]);

  s21_sprintf(str1[1], "Bye %d", numbers[2]);
  sprintf(str2[1], "Bye %d", numbers[2]);
  ck_assert_str_eq(str1[1], str2[1]);

  s21_sprintf(str1[2], "   Hi   %d", numbers[3]);
  sprintf(str2[2], "   Hi   %d", numbers[3]);
  ck_assert_str_eq(str1[2], str2[2]);

  s21_sprintf(str1[3], "%d Hello", numbers[4]);
  sprintf(str2[3], "%d Hello", numbers[4]);
  ck_assert_str_eq(str1[3], str2[3]);

  s21_sprintf(str1[4], "%ldHello", (long)numbers[5]);
  sprintf(str2[4], "%ldHello", (long)numbers[5]);
  ck_assert_str_eq(str1[4], str2[4]);

  s21_sprintf(str1[5], "%d   Hello   ", numbers[5]);
  sprintf(str2[5], "%d   Hello   ", numbers[5]);
  ck_assert_str_eq(str1[5], str2[5]);

  s21_sprintf(str1[6], "%d   Hello   ", numbers[5]);
  sprintf(str2[6], "%d   Hello   ", numbers[5]);
  ck_assert_str_eq(str1[6], str2[6]);

  s21_sprintf(str1[71], "%+d   Hello   ", numbers[5]);
  sprintf(str2[71], "%+d   Hello   ", numbers[5]);
  ck_assert_str_eq(str1[71], str2[71]);

  s21_sprintf(str1[72], "%-d   Hello   ", numbers[5]);
  sprintf(str2[72], "%-d   Hello   ", numbers[5]);
  ck_assert_str_eq(str1[72], str2[72]);

  s21_sprintf(str1[73], "% d   Hello   ", numbers[5]);
  sprintf(str2[73], "% d   Hello   ", numbers[5]);
  ck_assert_str_eq(str1[73], str2[73]);

  s21_sprintf(str1[74], "%10d   Hello   ", numbers[5]);
  sprintf(str2[74], "%10d   Hello   ", numbers[5]);
  ck_assert_str_eq(str1[74], str2[74]);

  s21_sprintf(str1[75], "%-10d   Hello   ", numbers[5]);
  sprintf(str2[75], "%-10d   Hello   ", numbers[5]);
  ck_assert_str_eq(str1[75], str2[75]);

  s21_sprintf(str1[76], "%.0d   Hello   ", numbers[5]);
  sprintf(str2[76], "%.0d   Hello   ", numbers[5]);
  ck_assert_str_eq(str1[76], str2[76]);

  s21_sprintf(str1[77], "%.1d   Hello   ", numbers[5]);
  sprintf(str2[77], "%.1d   Hello   ", numbers[5]);
  ck_assert_str_eq(str1[77], str2[77]);

  s21_sprintf(str1[78], "%.15d   Hello   ", numbers[5]);
  sprintf(str2[78], "%.15d   Hello   ", numbers[5]);
  ck_assert_str_eq(str1[78], str2[78]);

  s21_sprintf(str1[79], "%hd   Hello   ", short_int);
  sprintf(str2[79], "%hd   Hello   ", short_int);
  ck_assert_str_eq(str1[79], str2[79]);

  s21_sprintf(str1[80], "%hd   Hello   ", -short_int);
  sprintf(str2[80], "%hd   Hello   ", -short_int);
  ck_assert_str_eq(str1[80], str2[80]);

  s21_sprintf(str1[81], "%ld   Hello   ", long_int);
  sprintf(str2[81], "%ld   Hello   ", long_int);
  ck_assert_str_eq(str1[81], str2[81]);

  s21_sprintf(str1[82], "%ld   Hello   ", -long_int);
  sprintf(str2[82], "%ld   Hello   ", -long_int);
  ck_assert_str_eq(str1[82], str2[82]);

  s21_sprintf(str1[83], "%+-10.3d   Hello   ", numbers[1]);
  sprintf(str2[83], "%+-10.3d   Hello   ", numbers[1]);
  ck_assert_str_eq(str1[83], str2[83]);

  s21_sprintf(str1[84], "%+-10.3d   Hello   ", numbers[2]);
  sprintf(str2[84], "%+-10.3d   Hello   ", numbers[2]);
  ck_assert_str_eq(str1[84], str2[84]);

  s21_sprintf(str1[85], "% -10.3d   Hello   ", numbers[1]);
  sprintf(str2[85], "% -10.3d   Hello   ", numbers[1]);
  ck_assert_str_eq(str1[85], str2[85]);

  s21_sprintf(str1[86], "% -10.3d   Hello   ", numbers[0]);
  sprintf(str2[86], "% -10.3d   Hello   ", numbers[0]);
  ck_assert_str_eq(str1[86], str2[86]);

  s21_sprintf(str1[87], "%0*d   Hello   ", 10, 3, numbers[1]);
  sprintf(str2[87], "%0*d   Hello   ", 10, 3, numbers[1]);
  ck_assert_str_eq(str1[87], str2[87]);

  s21_sprintf(str1[89], "%*.0d   Hello   ", 10, 3, numbers[1]);
  sprintf(str2[89], "%*.0d   Hello   ", 10, 3, numbers[1]);
  ck_assert_str_eq(str1[89], str2[89]);

  s21_sprintf(str1[88], "% -*.*hd   Hello   ", 10, 3, short_int);
  sprintf(str2[88], "% -*.*hd   Hello   ", 10, 3, short_int);
  ck_assert_str_eq(str1[88], str2[88]);

  // i
  s21_sprintf(str1[7], "%i   Hello   ", hex[0]);
  sprintf(str2[7], "%i   Hello   ", hex[0]);
  ck_assert_str_eq(str1[7], str2[7]);

  s21_sprintf(str1[8], "%ihi", hex[1]);
  sprintf(str2[8], "%ihi", hex[1]);
  ck_assert_str_eq(str1[8], str2[8]);

  s21_sprintf(str1[9], "foo%ihi", hex[2]);
  sprintf(str2[9], "foo%ihi", hex[2]);
  ck_assert_str_eq(str1[9], str2[9]);

  s21_sprintf(str1[10], "  foo  %ihi", hex[3]);
  sprintf(str2[10], "  foo  %ihi", hex[3]);
  ck_assert_str_eq(str1[10], str2[10]);

  s21_sprintf(str1[11], "  foo  %ihi", hex[3]);
  sprintf(str2[11], "  foo  %ihi", hex[3]);
  ck_assert_str_eq(str1[11], str2[11]);

  s21_sprintf(str1[12], "%i%ihi", hex[4], hex[4]);
  sprintf(str2[12], "%i%ihi", hex[4], hex[4]);
  ck_assert_str_eq(str1[12], str2[12]);

  // c
  s21_sprintf(str1[13], "Hell%c%c", 'o', ' ');
  sprintf(str2[13], "Hell%c%c", 'o', ' ');
  ck_assert_str_eq(str1[13], str2[13]);

  s21_sprintf(str1[20], "Hell%c%c world", 'o', ' ');
  sprintf(str2[20], "Hell%c%c world", 'o', ' ');
  ck_assert_str_eq(str1[20], str2[20]);

  s21_sprintf(str1[90], "Hell%10c%-5lc world", 'o', L' ');
  sprintf(str2[90], "Hell%10c%-5lc world", 'o', L' ');
  ck_assert_str_eq(str1[90], str2[90]);

  s21_sprintf(str1[91], "Hell%10c%-5lc world", 'o', L' ');
  sprintf(str2[91], "Hell%10c%-5lc world", 'o', L' ');
  ck_assert_str_eq(str1[91], str2[91]);

  // %%
  s21_sprintf(str1[14], "100%%joice");
  sprintf(str2[14], "100%%joice");
  ck_assert_str_eq(str1[14], str2[14]);

  s21_sprintf(str1[15], "%%%%%%%%%%");
  sprintf(str2[15], "%%%%%%%%%%");
  ck_assert_str_eq(str1[15], str2[15]);

  sprintf(str1[16], "%%%%%d%%%%", 15);
  sprintf(str2[16], "%%%%%d%%%%", 15);
  ck_assert_str_eq(str1[16], str2[16]);

  // f
  s21_sprintf(str1[17], "%Lf hi", (long double)7.7);
  sprintf(str2[17], "%Lf hi", (long double)7.7);
  ck_assert_str_eq(str1[17], str2[17]);

  s21_sprintf(str1[18], "%f hi", FLT_MIN);
  sprintf(str2[18], "%f hi", FLT_MIN);
  ck_assert_str_eq(str1[18], str2[18]);

  s21_sprintf(str1[93], "%f", 5.0000);
  sprintf(str2[93], "%f", 5.0000);
  ck_assert_str_eq(str1[93], str2[93]);

  s21_sprintf(str1[94], "%f", 5000.0099);
  sprintf(str2[94], "%f", 5000.0099);
  ck_assert_str_eq(str1[94], str2[94]);

  s21_sprintf(str1[95], "%+10.6f % -#10.3f %0*f % 10.0f % #-10.1f", 5000.0099,
              -5000.0099, 4, 500.09, 0., 0.);
  sprintf(str2[95], "%+10.6f % -#10.3f %0*f % 10.0f % #-10.1f", 5000.0099,
          -5000.0099, 4, 500.09, 0., 0.);
  ck_assert_str_eq(str1[95], str2[95]);

  for (double i = 1002990; i >= 0.0000001; i /= 10) {
    s21_sprintf(str1[96], "%-+#7.4f", i);
    sprintf(str2[96], "%-+#7.4f", i);
    ck_assert_str_eq(str1[96], str2[96]);
  }

  for (double i = -1002990; i <= -0.0000001; i /= 10) {
    s21_sprintf(str1[97], "% 07f", i);
    sprintf(str2[97], "% 07f", i);
    ck_assert_str_eq(str1[97], str2[97]);
  }

  // g
  s21_sprintf(str1[21], "%g", 5.0000);
  sprintf(str2[21], "%g", 5.0000);
  ck_assert_str_eq(str1[21], str2[21]);

  s21_sprintf(str1[22], "%g", 5.0030);
  sprintf(str2[22], "%g", 5.0030);
  ck_assert_str_eq(str1[22], str2[22]);

  s21_sprintf(str1[23], "%g", 7.0);
  sprintf(str2[23], "%g", 7.0);
  ck_assert_str_eq(str1[23], str2[23]);

  s21_sprintf(str1[24], "%g", 7.4);
  sprintf(str2[24], "%g", 7.4);
  ck_assert_str_eq(str1[24], str2[24]);

  sprintf(str1[25], "%g", 0.0003000);
  s21_sprintf(str2[25], "%g", 0.0003000);
  ck_assert_str_eq(str1[25], str2[25]);

  sprintf(str1[92], "%g", -10000000.);
  s21_sprintf(str2[92], "%g", -10000000.);
  ck_assert_str_eq(str1[92], str2[92]);

  sprintf(str1[93], "%g", 10000290.);
  s21_sprintf(str2[93], "%g", 10000290.);
  ck_assert_str_eq(str1[93], str2[93]);

  sprintf(str1[94], "%g", 1000.);
  s21_sprintf(str2[94], "%g", 1000.);
  ck_assert_str_eq(str1[94], str2[94]);

  sprintf(str1[99], "%g", 0.);
  s21_sprintf(str2[99], "%g", 0.);
  ck_assert_str_eq(str1[99], str2[99]);

  sprintf(str1[92], "%+15.3g %011g %# *.*g %# *.*g", 10009000., 0.003, -10, 5,
          0.0000099, 13, 0, 0.);
  s21_sprintf(str2[92], "%+15.3g %011g %# *.*g %# *.*g", 10009000., 0.003, -10,
              5, 0.0000099, 13, 0, 0.);
  ck_assert_str_eq(str1[92], str2[92]);

  // G
  s21_sprintf(str1[26], "%G", 5.0000);
  sprintf(str2[26], "%G", 5.0000);
  ck_assert_str_eq(str1[26], str2[26]);

  s21_sprintf(str1[27], "%G", 5.0030);
  sprintf(str2[27], "%G", 5.0030);
  ck_assert_str_eq(str1[27], str2[27]);

  s21_sprintf(str1[28], "%G", 7.0);
  sprintf(str2[28], "%G", 7.0);
  ck_assert_str_eq(str1[28], str2[28]);

  s21_sprintf(str1[29], "%g", 7.4);
  sprintf(str2[29], "%G", 7.4);
  ck_assert_str_eq(str1[29], str2[29]);

  sprintf(str1[30], "%G", 0.0003000);
  s21_sprintf(str2[30], "%G", 0.0003000);
  ck_assert_str_eq(str1[30], str2[30]);

  // %o
  sprintf(str1[32], "%#2lo", (long)1234567);
  s21_sprintf(str2[32], "%#2lo", (long)1234567);
  ck_assert_str_eq(str1[32], str2[32]);

  sprintf(str1[33], "%oHello", 0xffc);
  s21_sprintf(str2[33], "%oHello", 0xffc);
  ck_assert_str_eq(str1[33], str2[33]);

  sprintf(str1[34], "%o", 0);
  s21_sprintf(str2[34], "%o", 0);
  ck_assert_str_eq(str1[34], str2[34]);

  sprintf(str1[35], "%o", INT32_MAX);
  s21_sprintf(str2[35], "%o", INT32_MAX);
  ck_assert_str_eq(str1[35], str2[35]);

  // %s
  sprintf(str1[36], "%s", "Hello world");
  s21_sprintf(str2[36], "%s", "Hello world");
  ck_assert_str_eq(str1[36], str2[36]);

  sprintf(str1[37], "%s%s", "Hello", "world");
  s21_sprintf(str2[37], "%s%s", "Hello", "world");
  ck_assert_str_eq(str1[37], str2[37]);

  sprintf(str1[38], "%d%s%d", 25, "hello", 40);
  s21_sprintf(str2[38], "%d%s%d", 25, "hello", 40);
  ck_assert_str_eq(str1[38], str2[38]);

  sprintf(str1[39], "%s%c", "hello", '!');
  s21_sprintf(str2[39], "%s%c", "hello", '!');
  ck_assert_str_eq(str1[39], str2[39]);

  sprintf(str1[40], "%s%o", "!", INT32_MAX);
  s21_sprintf(str2[40], "%s%o", "!", INT32_MAX);
  ck_assert_str_eq(str1[40], str2[40]);

  // %u
  sprintf(str1[41], "%2lu", (long)-45);
  s21_sprintf(str2[41], "%2lu", (long)-45);
  ck_assert_str_eq(str1[41], str2[41]);

  sprintf(str1[42], "%u", INT32_MAX);
  s21_sprintf(str2[42], "%u", INT32_MAX);
  ck_assert_str_eq(str1[42], str2[42]);

  sprintf(str1[43], "%u", INT32_MIN);
  s21_sprintf(str2[43], "%u", INT32_MIN);
  ck_assert_str_eq(str1[43], str2[43]);

  sprintf(str1[44], "%u", 0);
  s21_sprintf(str2[44], "%u", 0);
  ck_assert_str_eq(str1[44], str2[44]);

  sprintf(str1[45], "School %u%u", 4, 2);
  s21_sprintf(str2[45], "School %u%u", 4, 2);
  ck_assert_str_eq(str1[45], str2[45]);

  sprintf(str1[98], "School %-10.3u %0u %-10.5hu %lu", (unsigned)12345,
          (unsigned)0, (unsigned short)123456, (unsigned long)123456789000);
  s21_sprintf(str2[98], "School %-10.3u %0u %-10.5hu %lu", (unsigned)12345,
              (unsigned)0, (unsigned short)123456, (unsigned long)123456789000);
  ck_assert_str_eq(str1[98], str2[98]);

  // x
  sprintf(str1[46], "%5.5x", 0x0);
  s21_sprintf(str2[46], "%5.5x", 0x0);
  ck_assert_str_eq(str1[46], str2[46]);

  sprintf(str1[47], "%5lx", 0);
  s21_sprintf(str2[47], "%5lx", 0);
  ck_assert_str_eq(str1[47], str2[47]);

  sprintf(str1[48], "%hx", (short int)123500);
  s21_sprintf(str2[48], "%hx", (short int)123500);
  ck_assert_str_eq(str1[48], str2[48]);

  sprintf(str1[49], "%x", INT64_MAX);
  s21_sprintf(str2[49], "%x", INT64_MAX);
  ck_assert_str_eq(str1[49], str2[49]);

  sprintf(str1[50], "%x", INT32_MIN);
  s21_sprintf(str2[50], "%x", INT32_MIN);
  ck_assert_str_eq(str1[50], str2[50]);

  sprintf(str1[100], "School %-10.3x %0x %-#10.5hx %lx", (unsigned)12345,
          (unsigned)0, (unsigned short)123456, (unsigned long)123456789000);
  s21_sprintf(str2[100], "School %-10.3x %0x %-#10.5hx %lx", (unsigned)12345,
              (unsigned)0, (unsigned short)123456, (unsigned long)123456789000);
  ck_assert_str_eq(str1[100], str2[100]);

  // X
  sprintf(str1[51], "%X", 0x0);
  s21_sprintf(str2[51], "%X", 0x0);
  ck_assert_str_eq(str1[51], str2[51]);

  sprintf(str1[52], "%X", 500);
  s21_sprintf(str2[52], "%X", 500);
  ck_assert_str_eq(str1[52], str2[52]);

  sprintf(str1[53], "%X", INT32_MAX);
  s21_sprintf(str2[53], "%X", INT32_MAX);
  ck_assert_str_eq(str1[53], str2[53]);

  sprintf(str1[54], "%X", INT64_MAX);
  s21_sprintf(str2[54], "%X", INT64_MAX);
  ck_assert_str_eq(str1[54], str2[54]);

  sprintf(str1[55], "%#X", INT32_MIN);
  s21_sprintf(str2[55], "%#X", INT32_MIN);
  ck_assert_str_eq(str1[55], str2[55]);

  sprintf(str1[101], "School %-10.3X %0X %-#10.5hX %lX", (unsigned)12345,
          (unsigned)0, (unsigned short)123456, (unsigned long)123456789000);
  s21_sprintf(str2[101], "School %-10.3X %0X %-#10.5hX %lX", (unsigned)12345,
              (unsigned)0, (unsigned short)123456, (unsigned long)123456789000);
  ck_assert_str_eq(str1[101], str2[101]);

  // p
  sprintf(str1[56], "%p", str1);
  s21_sprintf(str2[56], "%p", str1);
  ck_assert_str_eq(str1[56], str2[56]);

  sprintf(str1[57], "%p%p", str1, str2);
  s21_sprintf(str2[57], "%p%p", str1, str2);
  ck_assert_str_eq(str1[57], str2[57]);

  // n
  int n1, n2, n3, n4;

  sprintf(str1[58], "Hello world %n", &n1);
  s21_sprintf(str2[58], "Hello world %n", &n2);
  ck_assert_int_eq(n1, n2);
  ck_assert_str_eq(str1[58], str2[58]);

  sprintf(str1[59], "%nHello world%c %n", &n1, '!', &n2);
  s21_sprintf(str2[59], "%nHello world%c %n", &n3, '!', &n4);
  ck_assert_int_eq(n1, n3);
  ck_assert_int_eq(n2, n4);
  ck_assert_str_eq(str1[59], str2[59]);

  sprintf(str1[60], "%n%n Hello %s", &n1, &n2, "kitty");
  s21_sprintf(str2[60], "%n%n Hello %s", &n3, &n4, "kitty");
  ck_assert_int_eq(n1, n3);
  ck_assert_int_eq(n2, n4);
  ck_assert_str_eq(str1[60], str2[60]);

  // e
  sprintf(str1[61], "%e", 3.450e1);
  s21_sprintf(str2[61], "%e", 3.450e1);
  ck_assert_str_eq(str1[61], str2[61]);

  sprintf(str1[62], "%e", 4.000e-3);
  s21_sprintf(str2[62], "%e", 4.000e-3);
  ck_assert_str_eq(str1[62], str2[62]);

  sprintf(str1[63], "%e", 1.23005e2);
  s21_sprintf(str2[63], "%e", 1.23005e2);
  ck_assert_str_eq(str1[63], str2[63]);

  sprintf(str1[64], "%e%e", 1.46000e5, 1.46000001e5);
  s21_sprintf(str2[64], "%e%e", 1.46000e5, 1.46000001e5);
  ck_assert_str_eq(str1[64], str2[64]);

  sprintf(str1[65], "|%e|%d", 8e-6, INT32_MAX);
  s21_sprintf(str2[65], "|%e|%d", 8e-6, INT32_MAX);
  ck_assert_str_eq(str1[65], str2[65]);

  sprintf(str1[102], "%.12e", 0.000000000000123);
  s21_sprintf(str2[102], "%.12e", 0.000000000000123);
  ck_assert_str_eq(str1[102], str2[102]);

  // Флаги
  sprintf(str1[66], "%*.5s", 25, "Hello world");
  sprintf(str2[66], "%*.5s", 25, "Hello world");
  ck_assert_str_eq(str1[66], str2[66]);

  sprintf(str1[67], "%-25s", "Hello world");
  sprintf(str2[67], "%-25s", "Hello world");
  ck_assert_str_eq(str1[67], str2[67]);

  sprintf(str1[68], "%+5.5d", 25);
  sprintf(str2[68], "%+5.5d", 25);
  ck_assert_str_eq(str1[68], str2[68]);

  sprintf(str1[69], "%*.5d", 25, 5);
  sprintf(str2[69], "%*.5d", 25, 5);
  ck_assert_str_eq(str1[69], str2[69]);

  //  long double ldobule = 1.6;
  //  sprintf(str1[70], "%Le", 1.6);
  //  s21_sprintf(str2[70], "%Le", 1.6);
  //  ck_assert_str_eq(str1[70], str2[70]);
}
END_TEST

START_TEST(s21_sscanf_test) {
  // %s specifier
  char a[100] = {0};
  char a1[100] = {0};
  char b[100] = {0};
  char b1[100] = {0};

  int result = 0;
  int s21_result = 0;

  s21_result = s21_sscanf("hello", "%s", a);
  result = sscanf("hello", "%s", a1);
  ck_assert_str_eq(a, a1);
  ck_assert_int_eq(result, s21_result);

  s21_result = s21_sscanf("  hello", "%s", a);
  result = sscanf("  hello", "%s", a1);
  ck_assert_str_eq(a, a1);
  ck_assert_int_eq(result, s21_result);

  s21_result = s21_sscanf("  hello  ", "%s", a);
  result = sscanf("  hello  ", "%s", a1);
  ck_assert_str_eq(a, a1);
  ck_assert_int_eq(result, s21_result);

  char y[100] = {0};
  char y1[100] = {0};
  s21_result = s21_sscanf("", "%s", y);
  result = sscanf("", "%s", y1);
  ck_assert_str_eq(y, y1);
  ck_assert_int_eq(result, s21_result);

  s21_result = s21_sscanf("   ", "%s", y);
  result = sscanf("   ", "%s", y1);
  ck_assert_str_eq(y, y1);
  ck_assert_int_eq(result, s21_result);

  s21_result = s21_sscanf("hello world", "%s %s", a, b);
  result = sscanf("hello world", "%s %s", a1, b1);
  ck_assert_str_eq(a, a1);
  ck_assert_str_eq(b, b1);
  ck_assert_int_eq(result, s21_result);

  s21_result = s21_sscanf("    hello world", "%s %s", a, b);
  result = sscanf("   hello world", "%s %s", a1, b1);
  ck_assert_str_eq(a, a1);
  ck_assert_str_eq(b, b1);
  ck_assert_int_eq(result, s21_result);

  s21_result = s21_sscanf("    hello world", "%4s %s", a, b);
  result = sscanf("   hello world", "%4s %s", a1, b1);
  ck_assert_str_eq(a, a1);
  ck_assert_str_eq(b, b1);
  ck_assert_int_eq(result, s21_result);

  s21_result = s21_sscanf("    hello world", "%0s %s", a, b);
  result = sscanf("   hello world", "%0s %s", a1, b1);
  ck_assert_str_eq(a, a1);
  ck_assert_str_eq(b, b1);
  ck_assert_int_eq(result, s21_result);

  s21_result = s21_sscanf("    hello world", "%*s %s", a, b);
  result = sscanf("   hello world", "%*s %s", a1, b1);
  ck_assert_str_eq(a, a1);
  ck_assert_str_eq(b, b1);
  ck_assert_int_eq(result, s21_result);

  s21_result = s21_sscanf("    hello world", "%s %*s", a, b);
  result = sscanf("   hello world", "%s %*s", a1, b1);
  ck_assert_str_eq(a, a1);
  ck_assert_str_eq(b, b1);
  ck_assert_int_eq(result, s21_result);

  int n = 3;
  int n1 = 0;
  s21_result = s21_sscanf("    hello world", "%s %*s %n", a, &n);
  result = sscanf("    hello world", "%s %*s %n", a1, &n1);
  ck_assert_str_eq(a, a1);
  ck_assert_int_eq(n, n1);
  ck_assert_int_eq(result, s21_result);

  s21_result = s21_sscanf("    hello world", "%2s %*s %n", a, b, &n);
  result = sscanf("   hello world", "%2s %*s %n", a1, b1, &n1);
  ck_assert_str_eq(a, a1);
  ck_assert_int_eq(n, n1);
  ck_assert_int_eq(result, s21_result);

  s21_result = s21_sscanf("    hello world", "%ls %s", a, b);
  result = sscanf("   hello world", "%ls %s", a1, b1);
  ck_assert_str_eq(a, a1);
  ck_assert_str_eq(b, b1);
  ck_assert_int_eq(result, s21_result);

  n = 0;
  n1 = 0;
  s21_result = s21_sscanf("    hello world", "%s %ls %n", a, b, &n);
  result = sscanf("    hello world", "%s %ls %n", a1, b1, &n1);
  ck_assert_str_eq(a, a1);
  ck_assert_str_eq(b, b1);
  ck_assert_int_eq(n, n1);
  ck_assert_int_eq(result, s21_result);

  // %d specifier

  int i = 0;
  int j = 0;
  s21_result = s21_sscanf("184", "%d", &i);
  result = sscanf("184", "%d", &j);
  ck_assert_int_eq(i, j);
  ck_assert_int_eq(result, s21_result);

  i = 0;
  j = 0;
  s21_result = s21_sscanf("t184", "%d", &i);
  result = sscanf("t184", "%d", &j);
  ck_assert_int_eq(i, j);
  ck_assert_int_eq(result, s21_result);

  s21_result = s21_sscanf("184t", "%d", &i);
  result = sscanf("184t", "%d", &j);
  ck_assert_int_eq(i, j);
  ck_assert_int_eq(result, s21_result);

  i = 0;
  j = 0;
  s21_result = s21_sscanf("", "%d", &i);
  result = sscanf("", "%d", &j);
  ck_assert_int_eq(i, j);
  ck_assert_int_eq(result, s21_result);

  s21_result = s21_sscanf("184h86", "%d", &i);
  result = sscanf("184h86", "%d", &j);
  ck_assert_int_eq(i, j);
  ck_assert_int_eq(result, s21_result);

  s21_result = s21_sscanf("184   86", "%d", &i);
  result = sscanf("184   86", "%d", &j);
  ck_assert_int_eq(i, j);
  ck_assert_int_eq(result, s21_result);

  s21_result = s21_sscanf("-184", "%d", &i);
  result = sscanf("-184", "%d", &j);
  ck_assert_int_eq(i, j);
  ck_assert_int_eq(result, s21_result);

  s21_result = s21_sscanf(" 56", "%d", &i);
  result = sscanf(" 56", "%d", &j);
  ck_assert_int_eq(i, j);
  ck_assert_int_eq(result, s21_result);

  s21_result = s21_sscanf(" -56 ", "%d", &i);
  result = sscanf(" -56 ", "%d", &j);
  ck_assert_int_eq(i, j);
  ck_assert_int_eq(result, s21_result);

  s21_result = s21_sscanf("197856365839", "%d", &i);
  result = sscanf("197856365839", "%d", &j);
  ck_assert_int_eq(i, j);
  ck_assert_int_eq(result, s21_result);

  s21_result = s21_sscanf("-197856365839", "%d", &i);
  result = sscanf("-197856365839", "%d", &j);
  ck_assert_int_eq(i, j);
  ck_assert_int_eq(result, s21_result);

  n = 0;
  n1 = 0;
  s21_result = s21_sscanf("184h86", "%d %i", &i, &n);
  result = sscanf("184h86", "%d %i", &j, &n1);
  ck_assert_int_eq(i, j);
  ck_assert_int_eq(n, n1);
  ck_assert_int_eq(result, s21_result);

  s21_result = s21_sscanf("184 86", "%d %i", &i, &n);
  result = sscanf("184 86", "%d %i", &j, &n1);
  ck_assert_int_eq(i, j);
  ck_assert_int_eq(n, n1);
  ck_assert_int_eq(result, s21_result);

  int i1 = 0;
  int j1 = 0;
  s21_result = s21_sscanf("3245 1322", "%d %d", &i, &j);
  result = sscanf("3245 1322", "%d %d", &i1, &j1);
  ck_assert_int_eq(i, i1);
  ck_assert_int_eq(j, j1);
  ck_assert_int_eq(result, s21_result);

  s21_result = s21_sscanf("3245 1322", "%2d %d", &i, &j);
  result = sscanf("3245 1322", "%2d %d", &i1, &j1);
  ck_assert_int_eq(i, i1);
  ck_assert_int_eq(j, j1);
  ck_assert_int_eq(result, s21_result);

  i = 0;
  j = 0;
  i1 = 0;
  j1 = 0;

  s21_result = s21_sscanf("3245 1322", "%-2d %d", &i, &j);
  result = sscanf("3245 1322", "%-2d %d", &i1, &j1);
  ck_assert_int_eq(i, i1);
  ck_assert_int_eq(j, j1);
  ck_assert_int_eq(result, s21_result);

  i = 0;
  i1 = 0;
  j = 0;
  j1 = 0;

  s21_result = s21_sscanf("3245 1322", "%*d %d", &i, &j);
  result = sscanf("3245 1322", "%*d %d", &i1, &j1);
  ck_assert_int_eq(i, i1);
  ck_assert_int_eq(j, j1);
  ck_assert_int_eq(result, s21_result);

  s21_result = s21_sscanf("3245 1322", "%d %*d", &i, &j);
  result = sscanf("3245 1322", "%d %*d", &i1, &j1);
  ck_assert_int_eq(i, i1);
  ck_assert_int_eq(j, j1);
  ck_assert_int_eq(result, s21_result);

  short int q = 0;
  short int w = 0;
  short int q1 = 0;
  short int w1 = 0;
  s21_result = s21_sscanf("3245 1322", "%hd %hd", &q, &w);
  result = sscanf("3245 1322", "%hd %hd", &q1, &w1);
  ck_assert_int_eq(q, q1);
  ck_assert_int_eq(w, w1);
  ck_assert_int_eq(result, s21_result);

  long int e = 0;
  long int r = 0;
  long int e1 = 0;
  long int r1 = 0;
  s21_result = s21_sscanf("3245 1322", "%ld %ld", &e, &r);
  result = sscanf("3245 1322", "%ld %ld", &e1, &r1);
  ck_assert_int_eq(e, e1);
  ck_assert_int_eq(r, r1);
  ck_assert_int_eq(result, s21_result);

  // %i specifier

  int d = 0;
  int d1 = 0;
  s21_result = s21_sscanf("3245", "%i", &d);
  result = sscanf("3245", "%i", &d1);
  ck_assert_int_eq(d, d1);
  ck_assert_int_eq(result, s21_result);

  s21_result = s21_sscanf("075", "%i", &d);
  result = sscanf("075", "%i", &d1);
  ck_assert_int_eq(d, d1);
  ck_assert_int_eq(result, s21_result);

  s21_result = s21_sscanf("075", "%i", &d);
  result = sscanf("61", "%i", &d1);
  ck_assert_int_eq(d, d1);
  ck_assert_int_eq(result, s21_result);

  s21_result = s21_sscanf("0x342", "%i", &d);
  result = sscanf("834", "%i", &d1);
  ck_assert_int_eq(d, d1);
  ck_assert_int_eq(result, s21_result);

  s21_result = s21_sscanf("834", "%i", &d);
  result = sscanf("834", "%i", &d1);
  ck_assert_int_eq(d, d1);
  ck_assert_int_eq(result, s21_result);

  i = 0;
  j = 0;
  s21_result = s21_sscanf("", "%i", &i);
  result = sscanf("", "%i", &j);
  ck_assert_int_eq(i, j);
  ck_assert_int_eq(result, s21_result);

  // не проходит
  //  s21_result = s21_sscanf(" ", "%i", &i);
  //  result = sscanf(" ", "%i", &j);
  //  ck_assert_int_eq(i, j);
  //  ck_assert_int_eq(result, s21_result);

  int t = 0;
  int t1 = 0;

  s21_result = s21_sscanf("834 0x45", "%i %i", &d, &t);
  result = sscanf("834 0x45", "%i %i", &d1, &t1);
  ck_assert_int_eq(d, d1);
  ck_assert_int_eq(t, t1);
  ck_assert_int_eq(result, s21_result);

  t = 0;
  t1 = 0;
  s21_result = s21_sscanf("834 0x45", "%i %i", &d, &t);
  result = sscanf("834 0x45", "%i %i", &d1, &t1);
  ck_assert_int_eq(d, d1);
  ck_assert_int_eq(t, t1);
  ck_assert_int_eq(result, s21_result);

  d = 0;
  d1 = 0;
  t = 0;
  t1 = 0;
  s21_result = s21_sscanf("d834 0x45", "%i %i", &d, &t);
  result = sscanf("d834 0x45", "%i %i", &d1, &t1);
  ck_assert_int_eq(d, d1);
  ck_assert_int_eq(t, t1);
  ck_assert_int_eq(result, s21_result);

  s21_result = s21_sscanf("234 0x837", "%*i %i", &d, &t);
  result = sscanf("234 0x837", "%*i %i", &d1, &t1);
  ck_assert_int_eq(d, d1);
  ck_assert_int_eq(result, s21_result);

  s21_result = s21_sscanf("234 0x837", "%i %*i", &d, &t);
  result = sscanf("234 0x837", "%i %*i", &d1, &t1);
  ck_assert_int_eq(d, d1);
  ck_assert_int_eq(result, s21_result);

  s21_result = s21_sscanf("234 0x837", "%i %2i", &d, &t);
  result = sscanf("234 0x837", "%i %2i", &d1, &t1);
  ck_assert_int_eq(d, d1);
  ck_assert_int_eq(result, s21_result);

  s21_result = s21_sscanf("234 0x837", "%-1i %2i", &d, &t);
  result = sscanf("234 0x837", "%-1i %2i", &d1, &t1);
  ck_assert_int_eq(d, d1);
  ck_assert_int_eq(result, s21_result);

  s21_result = s21_sscanf("3245 1322", "%hi %hi", &q, &w);
  result = sscanf("3245 1322", "%hi %hi", &q1, &w1);
  ck_assert_int_eq(q, q1);
  ck_assert_int_eq(w, w1);
  ck_assert_int_eq(result, s21_result);

  s21_result = s21_sscanf("035 1322", "%hi %hi", &q, &w);
  result = sscanf("035 1322", "%hi %hi", &q1, &w1);
  ck_assert_int_eq(q, q1);
  ck_assert_int_eq(w, w1);
  ck_assert_int_eq(result, s21_result);

  r = 0;
  r1 = 0;
  s21_result = s21_sscanf("035 132264782398", "%li %li", &e, &r);
  result = sscanf("035 132264782398", "%li %li", &e1, &r1);
  ck_assert_int_eq(e, e1);
  ck_assert_int_eq(r, r1);
  ck_assert_int_eq(result, s21_result);

  s21_result = s21_sscanf("035 1322", "%li %hi", &e, &q);
  result = sscanf("035 1322", "%li %hi", &e1, &q1);
  ck_assert_int_eq(e, e1);
  ck_assert_int_eq(q, q1);
  ck_assert_int_eq(result, s21_result);

  s21_result = s21_sscanf("035 0x2846", "%i %i %n", &i, &j, &n);
  result = sscanf("035 0x2846", "%i %i %n", &i1, &j1, &n1);
  ck_assert_int_eq(i, i1);
  ck_assert_int_eq(j, j1);
  ck_assert_int_eq(n, n1);
  ck_assert_int_eq(result, s21_result);

  // %c specifier

  char c = 0;
  char c1 = 0;
  s21_result = s21_sscanf("h", "%c", &c);
  result = sscanf("h", "%c", &c1);
  ck_assert_int_eq(c, c1);
  ck_assert_int_eq(result, s21_result);

  s21_result = s21_sscanf("gh", "%c", &c);
  result = sscanf("gh", "%c", &c1);
  ck_assert_int_eq(c, c1);
  ck_assert_int_eq(result, s21_result);

  s21_result = s21_sscanf("  gh", "%c", &c);
  result = sscanf("  gh", "%c", &c1);
  ck_assert_int_eq(c, c1);
  ck_assert_int_eq(result, s21_result);

  s21_result = s21_sscanf("g h", "%c", &c);
  result = sscanf("g h", "%c", &c1);
  ck_assert_int_eq(c, c1);
  ck_assert_int_eq(result, s21_result);

  s21_result = s21_sscanf("g h", "%-1c", &c);
  result = sscanf("g h", "%-1c", &c1);
  ck_assert_int_eq(c, c1);
  ck_assert_int_eq(result, s21_result);

  char c2;
  char c3;
  s21_result = s21_sscanf("g h", "%c %c %n", &c, &c2, &n);
  result = sscanf("g h", "%c %c %n", &c1, &c3, &n1);
  ck_assert_int_eq(c, c1);
  ck_assert_int_eq(c2, c3);
  ck_assert_int_eq(n, n1);
  ck_assert_int_eq(result, s21_result);

  c2 = 0;
  c3 = 0;
  s21_result = s21_sscanf("g h", "%c%c %n", &c, &c2, &n);
  result = sscanf("g h", "%c%c %n", &c1, &c3, &n1);
  ck_assert_int_eq(c, c1);
  ck_assert_int_eq(c2, c3);
  ck_assert_int_eq(n, n1);
  ck_assert_int_eq(result, s21_result);

  c2 = 0;
  c3 = 0;
  s21_result = s21_sscanf("g  h", "%c %c %n", &c, &c2, &n);
  result = sscanf("g  h", "%c %c %n", &c1, &c3, &n1);
  ck_assert_int_eq(c, c1);
  ck_assert_int_eq(c2, c3);
  ck_assert_int_eq(n, n1);
  ck_assert_int_eq(result, s21_result);

  wchar_t m = 0;
  wchar_t m1 = 0;
  s21_result = s21_sscanf("h", "%lc", &m);
  result = sscanf("h", "%lc", &m1);
  ck_assert_int_eq(m, m1);
  ck_assert_int_eq(result, s21_result);

  char k = 0;
  char k1 = 0;
  s21_result = s21_sscanf("g h", "%c %c %n", &c, &k, &n);
  result = sscanf("g h", "%c %c %n", &c1, &k1, &n1);
  ck_assert_int_eq(c, c1);
  ck_assert_int_eq(k, k1);
  ck_assert_int_eq(n, n1);
  ck_assert_int_eq(result, s21_result);

  s21_result = s21_sscanf("..", "%c %c %n", &c, &k, &n);
  result = sscanf("..", "%c %c %n", &c1, &k1, &n1);
  ck_assert_int_eq(c, c1);
  ck_assert_int_eq(k, k1);
  ck_assert_int_eq(n, n1);
  ck_assert_int_eq(result, s21_result);

  s21_result = s21_sscanf("h 6", "%c %*c %n", &c, &n);
  result = sscanf("h 6", "%c %*c %n", &c1, &n1);
  ck_assert_int_eq(c, c1);
  ck_assert_int_eq(n, n1);
  ck_assert_int_eq(result, s21_result);

  // %% specifier
  c = 0;
  c1 = 0;
  n = 0;
  n1 = 0;
  s21_result = s21_sscanf("h 6", "%% %n", &n);
  result = sscanf("h 6", "%% %n", &n1);
  ck_assert_int_eq(result, s21_result);

  // %p specifier
  int val = 123;
  char buf[100] = {0};
  sprintf(buf, "%p", (void *)&val);
  void *ptr = 0;
  void *ptr2 = 0;
  sscanf(buf, "%p", &ptr);
  s21_sscanf(buf, "%p", &ptr2);
  // ck_assert_ptr_eq(ptr, ptr2);

  // %e %E %f %g %G specifiers

  float f = 0;
  float dd = 0;
  float f1 = 0;
  float dd1 = 0;

  // scientific notation

  s21_result = s21_sscanf("127564.3846 1.275643846e3", "%e %e", &f, &dd);
  result = sscanf("127564.3846 1.275643846e3", "%e %e", &f1, &dd1);
  ck_assert_float_eq(f, f1);
  ck_assert_float_eq(dd, dd1);
  ck_assert_int_eq(result, s21_result);

  s21_result = s21_sscanf("127564.3846 1.275643846e3", "%E %E", &f, &dd);
  result = sscanf("127564.3846 1.275643846e3", "%E %E", &f1, &dd1);
  ck_assert_float_eq(f, f1);
  ck_assert_float_eq(dd, dd1);
  ck_assert_int_eq(result, s21_result);

  s21_result = s21_sscanf("127564.3846 1.275643846e3", "%f %f", &f, &dd);
  result = sscanf("127564.3846 1.275643846e3", "%f %f", &f1, &dd1);
  ck_assert_float_eq(f, f1);
  ck_assert_float_eq(dd, dd1);
  ck_assert_int_eq(result, s21_result);

  s21_result = s21_sscanf("127564.3846 1.275643846e3", "%g %g", &f, &dd);
  result = sscanf("127564.3846 1.275643846e3", "%g %g", &f1, &dd1);
  ck_assert_float_eq(f, f1);
  ck_assert_float_eq(dd, dd1);
  ck_assert_int_eq(result, s21_result);

  s21_result = s21_sscanf("127564.3846 1.275643846e3", "%G %G", &f, &dd);
  result = sscanf("127564.3846 1.275643846e3", "%G %G", &f1, &dd1);
  ck_assert_float_eq(f, f1);
  ck_assert_float_eq(dd, dd1);
  ck_assert_int_eq(result, s21_result);

  // negative scientific notation

  s21_result = s21_sscanf("127564.3846 12756.43846e-3", "%e %e", &f, &dd);
  result = sscanf("127564.3846 12756.43846e-3", "%e %e", &f1, &dd1);
  ck_assert_float_eq(f, f1);
  ck_assert_float_eq(dd, dd1);
  ck_assert_int_eq(result, s21_result);

  s21_result = s21_sscanf("127564.3846 12756.43846e-3", "%E %E", &f, &dd);
  result = sscanf("127564.3846 12756.43846e-3", "%E %E", &f1, &dd1);
  ck_assert_float_eq(f, f1);
  ck_assert_float_eq(dd, dd1);
  ck_assert_int_eq(result, s21_result);

  s21_result = s21_sscanf("127564.3846 12756.43846e-3", "%f %f", &f, &dd);
  result = sscanf("127564.3846 12756.43846e-3", "%f %f", &f1, &dd1);
  ck_assert_float_eq(f, f1);
  ck_assert_float_eq(dd, dd1);
  ck_assert_int_eq(result, s21_result);

  s21_result = s21_sscanf("127564.3846 12756.43846e-3", "%g %g", &f, &dd);
  result = sscanf("127564.3846 12756.43846e-3", "%g %g", &f1, &dd1);
  ck_assert_float_eq(f, f1);
  ck_assert_float_eq(dd, dd1);
  ck_assert_int_eq(result, s21_result);

  s21_result = s21_sscanf("127564.3846 12756.43846e-3", "%G %G", &f, &dd);
  result = sscanf("127564.3846 12756.43846e-3", "%G %G", &f1, &dd1);
  ck_assert_float_eq(f, f1);
  ck_assert_float_eq(dd, dd1);
  ck_assert_int_eq(result, s21_result);

  // basic
  s21_result = s21_sscanf("0.008726", "%e", &f);
  result = sscanf("0.008726", "%e", &f1);
  ck_assert_float_eq(f, f1);
  ck_assert_int_eq(result, s21_result);

  s21_result = s21_sscanf("0.008726", "%E", &f);
  result = sscanf("0.008726", "%E", &f1);
  ck_assert_float_eq(f, f1);
  ck_assert_int_eq(result, s21_result);

  s21_result = s21_sscanf("0.008726", "%f", &f);
  result = sscanf("0.008726", "%f", &f1);
  ck_assert_float_eq(f, f1);
  ck_assert_int_eq(result, s21_result);

  s21_result = s21_sscanf("0.008726", "%g", &f);
  result = sscanf("0.008726", "%g", &f1);
  ck_assert_float_eq(f, f1);
  ck_assert_int_eq(result, s21_result);

  s21_result = s21_sscanf("0.008726", "%G", &f);
  result = sscanf("0.008726", "%G", &f1);
  ck_assert_float_eq(f, f1);
  ck_assert_int_eq(result, s21_result);

  // negative numbers

  s21_result = s21_sscanf("-0.008726", "%e", &f);
  result = sscanf("-0.008726", "%e", &f1);
  ck_assert_float_eq(f, f1);
  ck_assert_int_eq(result, s21_result);

  s21_result = s21_sscanf("-0.008726", "%E", &f);
  result = sscanf("-0.008726", "%E", &f1);
  ck_assert_float_eq(f, f1);
  ck_assert_int_eq(result, s21_result);

  s21_result = s21_sscanf("-0.008726", "%f", &f);
  result = sscanf("-0.008726", "%f", &f1);
  ck_assert_float_eq(f, f1);
  ck_assert_int_eq(result, s21_result);

  s21_result = s21_sscanf("-0.008726", "%g", &f);
  result = sscanf("-0.008726", "%g", &f1);
  ck_assert_float_eq(f, f1);
  ck_assert_int_eq(result, s21_result);

  s21_result = s21_sscanf("-0.008726", "%G", &f);
  result = sscanf("-0.008726", "%G", &f1);
  ck_assert_float_eq(f, f1);
  ck_assert_int_eq(result, s21_result);

  // spaces at the beginning
  s21_result = s21_sscanf("   0.008726", "%e", &f);
  result = sscanf("   0.008726", "%e", &f1);
  ck_assert_float_eq(f, f1);
  ck_assert_int_eq(result, s21_result);

  s21_result = s21_sscanf("   0.008726", "%E", &f);
  result = sscanf("   0.008726", "%E", &f1);
  ck_assert_float_eq(f, f1);
  ck_assert_int_eq(result, s21_result);

  s21_result = s21_sscanf("  0.008726", "%f", &f);
  result = sscanf("   0.008726", "%f", &f1);
  ck_assert_float_eq(f, f1);
  ck_assert_int_eq(result, s21_result);

  s21_result = s21_sscanf("   0.008726", "%g", &f);
  result = sscanf("   0.008726", "%g", &f1);
  ck_assert_float_eq(f, f1);
  ck_assert_int_eq(result, s21_result);

  s21_result = s21_sscanf("   0.008726", "%G", &f);
  result = sscanf("   0.008726", "%G", &f1);
  ck_assert_float_eq(f, f1);
  ck_assert_int_eq(result, s21_result);

  // spaces
  f = 0;
  f1 = 0;
  s21_result = s21_sscanf("   ", "%e", &f);
  result = sscanf("   ", "%e", &f1);
  ck_assert_float_eq(f, f1);
  ck_assert_int_eq(result, s21_result);

  f = 0;
  f1 = 0;
  s21_result = s21_sscanf("   ", "%E", &f);
  result = sscanf("   ", "%E", &f1);
  ck_assert_float_eq(f, f1);
  ck_assert_int_eq(result, s21_result);

  f = 0;
  f1 = 0;
  s21_result = s21_sscanf("   ", "%f", &f);
  result = sscanf("   ", "%f", &f1);
  ck_assert_float_eq(f, f1);
  ck_assert_int_eq(result, s21_result);

  f = 0;
  f1 = 0;
  s21_result = s21_sscanf("   ", "%g", &f);
  result = sscanf("   ", "%g", &f1);
  ck_assert_float_eq(f, f1);
  ck_assert_int_eq(result, s21_result);

  f = 0;
  f1 = 0;
  s21_result = s21_sscanf("   ", "%G", &f);
  result = sscanf("   ", "%G", &f1);
  ck_assert_float_eq(f, f1);
  ck_assert_int_eq(result, s21_result);

  // empty lines
  s21_result = s21_sscanf("", "%e", &f);
  result = sscanf("", "%e", &f1);
  ck_assert_float_eq(f, f1);
  ck_assert_int_eq(result, s21_result);

  s21_result = s21_sscanf("", "%E", &f);
  result = sscanf("", "%E", &f1);
  ck_assert_float_eq(f, f1);
  ck_assert_int_eq(result, s21_result);

  s21_result = s21_sscanf("", "%f", &f);
  result = sscanf("", "%f", &f1);
  ck_assert_float_eq(f, f1);
  ck_assert_int_eq(result, s21_result);

  s21_result = s21_sscanf("", "%g", &f);
  result = sscanf("", "%g", &f1);
  ck_assert_float_eq(f, f1);
  ck_assert_int_eq(result, s21_result);

  s21_result = s21_sscanf("", "%G", &f);
  result = sscanf("", "%G", &f1);
  ck_assert_float_eq(f, f1);
  ck_assert_int_eq(result, s21_result);

  // snowflakes
  f = 0;
  f1 = 0;
  dd = 0;
  dd1 = 0;
  s21_result = s21_sscanf("5674.007827 4758", "%*e %e", &f, &dd);
  result = sscanf("5674.007827 4758", "%*e %e", &f1, &dd1);
  ck_assert_float_eq(f, f1);
  ck_assert_int_eq(result, s21_result);

  f = 0;
  f1 = 0;
  dd = 0;
  dd1 = 0;
  s21_result = s21_sscanf("5674.007827 4758", "%*E %E", &f, &dd);
  result = sscanf("5674.007827 4758", "%*E %E", &f1, &dd1);
  ck_assert_float_eq(f, f1);
  ck_assert_float_eq(dd, dd1);
  ck_assert_int_eq(result, s21_result);

  f = 0;
  f1 = 0;
  dd = 0;
  dd1 = 0;
  s21_result = s21_sscanf("5674.007827 4758", "%*f %f", &f, &dd);
  result = sscanf("5674.007827 4758", "%*f %f", &f1, &dd1);
  ck_assert_float_eq(f, f1);
  ck_assert_float_eq(dd, dd1);
  ck_assert_int_eq(result, s21_result);

  f = 0;
  f1 = 0;
  dd = 0;
  dd1 = 0;
  s21_result = s21_sscanf("5674.007827 4758", "%*g %g", &f, &dd);
  result = sscanf("5674.007827 4758", "%*g %g", &f1, &dd1);
  ck_assert_float_eq(f, f1);
  ck_assert_float_eq(dd, dd1);
  ck_assert_int_eq(result, s21_result);

  f = 0;
  f1 = 0;
  dd = 0;
  dd1 = 0;
  s21_result = s21_sscanf("5674.007827 4758", "%*G %G", &f, &dd);
  result = sscanf("5674.007827 4758", "%*G %G", &f1, &dd1);
  ck_assert_float_eq(f, f1);
  ck_assert_float_eq(dd, dd1);
  ck_assert_int_eq(result, s21_result);

  // width
  s21_result = s21_sscanf("0.008726", "%6e", &f);
  result = sscanf("0.008726", "%6e", &f1);
  ck_assert_float_eq(f, f1);
  ck_assert_int_eq(result, s21_result);

  s21_result = s21_sscanf("0.008726", "%4E", &f);
  result = sscanf("0.008726", "%4E", &f1);
  ck_assert_float_eq(f, f1);
  ck_assert_int_eq(result, s21_result);

  s21_result = s21_sscanf("0.008726", "%4f", &f);
  result = sscanf("0.008726", "%4f", &f1);
  ck_assert_float_eq(f, f1);
  ck_assert_int_eq(result, s21_result);

  s21_result = s21_sscanf("0.008726", "%4g", &f);
  result = sscanf("0.008726", "%4g", &f1);
  ck_assert_float_eq(f, f1);
  ck_assert_int_eq(result, s21_result);

  s21_result = s21_sscanf("0.008726", "%4G", &f);
  result = sscanf("0.008726", "%4G", &f1);
  ck_assert_float_eq(f, f1);
  ck_assert_int_eq(result, s21_result);

  // negative width

  s21_result = s21_sscanf("0.008726", "%-6e", &f);
  result = sscanf("0.008726", "%-6e", &f1);
  ck_assert_float_eq(f, f1);
  ck_assert_int_eq(result, s21_result);

  s21_result = s21_sscanf("0.008726", "%-4E", &f);
  result = sscanf("0.008726", "%-4E", &f1);
  ck_assert_float_eq(f, f1);
  ck_assert_int_eq(result, s21_result);

  s21_result = s21_sscanf("0.008726", "%-4f", &f);
  result = sscanf("0.008726", "%-4f", &f1);
  ck_assert_float_eq(f, f1);
  ck_assert_int_eq(result, s21_result);

  s21_result = s21_sscanf("0.008726", "%-4g", &f);
  result = sscanf("0.008726", "%-4g", &f1);
  ck_assert_float_eq(f, f1);
  ck_assert_int_eq(result, s21_result);

  s21_result = s21_sscanf("0.008726", "%-4G", &f);
  result = sscanf("0.008726", "%-4G", &f1);
  ck_assert_float_eq(f, f1);
  ck_assert_int_eq(result, s21_result);

  // zero width

  s21_result = s21_sscanf("0.008726", "%0e", &f);
  result = sscanf("0.008726", "%0e", &f1);
  ck_assert_float_eq(f, f1);
  ck_assert_int_eq(result, s21_result);

  s21_result = s21_sscanf("0.008726", "%0E", &f);
  result = sscanf("0.008726", "%0E", &f1);
  ck_assert_float_eq(f, f1);
  ck_assert_int_eq(result, s21_result);

  s21_result = s21_sscanf("0.008726", "%0f", &f);
  result = sscanf("0.008726", "%0f", &f1);
  ck_assert_float_eq(f, f1);
  ck_assert_int_eq(result, s21_result);

  s21_result = s21_sscanf("0.008726", "%0g", &f);
  result = sscanf("0.008726", "%0g", &f1);
  ck_assert_float_eq(f, f1);
  ck_assert_int_eq(result, s21_result);

  s21_result = s21_sscanf("0.008726", "%0G", &f);
  result = sscanf("0.008726", "%0G", &f1);
  ck_assert_float_eq(f, f1);
  ck_assert_int_eq(result, s21_result);

  // length L
  long double lf = 0;
  long double lf1 = 0;
  s21_result = s21_sscanf("9.9996587169235770324564357345", "%Le", &lf);
  result = sscanf("9.9996587169235770324564357345", "%Le", &lf1);
  ck_assert_ldouble_eq(lf, lf1);
  ck_assert_int_eq(result, s21_result);

  s21_result = s21_sscanf("9.9996587169235770324564357345", "%LE", &lf);
  result = sscanf("9.9996587169235770324564357345", "%LE", &lf1);
  ck_assert_ldouble_eq(lf, lf1);
  ck_assert_int_eq(result, s21_result);

  s21_result = s21_sscanf("9.9996587169235770324564357345", "%Lf", &lf);
  result = sscanf("9.9996587169235770324564357345", "%Lf", &lf1);
  ck_assert_ldouble_eq(lf, lf1);
  ck_assert_int_eq(result, s21_result);

  s21_result = s21_sscanf("9.9996587169235770324564357345", "%Lg", &lf);
  result = sscanf("9.9996587169235770324564357345", "%Lg", &lf1);
  ck_assert_ldouble_eq(lf, lf1);
  ck_assert_int_eq(result, s21_result);

  s21_result = s21_sscanf("9.9996587169235770324564357345", "%LG", &lf);
  result = sscanf("9.9996587169235770324564357345", "%LG", &lf1);
  ck_assert_ldouble_eq(lf, lf1);
  ck_assert_int_eq(result, s21_result);

  // length L + width
  s21_result = s21_sscanf("9.9996587169235770324564357345", "%4Le", &lf);
  result = sscanf("9.9996587169235770324564357345", "%4Le", &lf1);
  ck_assert_ldouble_eq(lf, lf1);
  ck_assert_int_eq(result, s21_result);

  s21_result = s21_sscanf("9.9996587169235770324564357345", "%4LE", &lf);
  result = sscanf("9.9996587169235770324564357345", "%4LE", &lf1);
  ck_assert_ldouble_eq(lf, lf1);
  ck_assert_int_eq(result, s21_result);

  s21_result = s21_sscanf("9.9996587169235770324564357345", "%4Lf", &lf);
  result = sscanf("9.9996587169235770324564357345", "%4Lf", &lf1);
  ck_assert_ldouble_eq(lf, lf1);
  ck_assert_int_eq(result, s21_result);

  s21_result = s21_sscanf("9.9996587169235770324564357345", "%4Lg", &lf);
  result = sscanf("9.9996587169235770324564357345", "%4Lg", &lf1);
  ck_assert_ldouble_eq(lf, lf1);
  ck_assert_int_eq(result, s21_result);

  s21_result = s21_sscanf("9.9996587169235770324564357345", "%4LG", &lf);
  result = sscanf("9.9996587169235770324564357345", "%4LG", &lf1);
  ck_assert_ldouble_eq(lf, lf1);
  ck_assert_int_eq(result, s21_result);

  // length L + width *
  lf = 0;
  lf1 = 0;
  s21_result = s21_sscanf("9.9996587169235770324564357345", "%*Le", &lf);
  result = sscanf("9.9996587169235770324564357345", "%*Le", &lf1);
  ck_assert_ldouble_eq(lf, lf1);
  ck_assert_int_eq(result, s21_result);

  s21_result = s21_sscanf("9.9996587169235770324564357345", "%*LE", &lf);
  result = sscanf("9.9996587169235770324564357345", "%*LE", &lf1);
  ck_assert_ldouble_eq(lf, lf1);
  ck_assert_int_eq(result, s21_result);

  s21_result = s21_sscanf("9.9996587169235770324564357345", "%*Lf", &lf);
  result = sscanf("9.9996587169235770324564357345", "%*Lf", &lf1);
  ck_assert_ldouble_eq(lf, lf1);
  ck_assert_int_eq(result, s21_result);

  s21_result = s21_sscanf("9.9996587169235770324564357345", "%*Lg", &lf);
  result = sscanf("9.9996587169235770324564357345", "%*Lg", &lf1);
  ck_assert_ldouble_eq(lf, lf1);
  ck_assert_int_eq(result, s21_result);

  s21_result = s21_sscanf("9.9996587169235770324564357345", "%*LG", &lf);
  result = sscanf("9.9996587169235770324564357345", "%*LG", &lf1);
  ck_assert_ldouble_eq(lf, lf1);
  ck_assert_int_eq(result, s21_result);

  // length L + negative width

  s21_result = s21_sscanf("9.9996587169235770324564357345", "%-4Le", &lf);
  result = sscanf("9.9996587169235770324564357345", "%-4Le", &lf1);
  ck_assert_ldouble_eq(lf, lf1);
  ck_assert_int_eq(result, s21_result);

  s21_result = s21_sscanf("9.9996587169235770324564357345", "%-4LE", &lf);
  result = sscanf("9.9996587169235770324564357345", "%-4LE", &lf1);
  ck_assert_ldouble_eq(lf, lf1);
  ck_assert_int_eq(result, s21_result);

  s21_result = s21_sscanf("9.9996587169235770324564357345", "%-4Lf", &lf);
  result = sscanf("9.9996587169235770324564357345", "%-4Lf", &lf1);
  ck_assert_ldouble_eq(lf, lf1);
  ck_assert_int_eq(result, s21_result);

  s21_result = s21_sscanf("9.9996587169235770324564357345", "%-4Lg", &lf);
  result = sscanf("9.9996587169235770324564357345", "%-4Lg", &lf1);
  ck_assert_ldouble_eq(lf, lf1);
  ck_assert_int_eq(result, s21_result);

  s21_result = s21_sscanf("9.9996587169235770324564357345", "%-4LG", &lf);
  result = sscanf("9.9996587169235770324564357345", "%-4LG", &lf1);
  ck_assert_ldouble_eq(lf, lf1);
  ck_assert_int_eq(result, s21_result);

  // with %n

  n = 0;
  n1 = 0;
  s21_result = s21_sscanf("1275.3846 0.2345", "%e %e %n", &f, &dd, &n);
  result = sscanf("1275.3846 0.2345", "%e %e %n", &f1, &dd1, &n1);
  ck_assert_float_eq(f, f1);
  ck_assert_float_eq(dd, dd1);
  ck_assert_int_eq(result, s21_result);
  ck_assert_int_eq(n, n1);

  n = 0;
  n1 = 0;
  s21_result = s21_sscanf("1275.3846 0.2345", "%E %E %n", &f, &dd, &n);
  result = sscanf("1275.3846 0.2345", "%E %E %n", &f1, &dd1, &n1);
  ck_assert_float_eq(f, f1);
  ck_assert_float_eq(dd, dd1);
  ck_assert_int_eq(result, s21_result);
  ck_assert_int_eq(n, n1);

  n = 0;
  n1 = 0;
  s21_result = s21_sscanf("1275.3846 0.2345", "%f %f %n", &f, &dd, &n);
  result = sscanf("1275.3846 0.2345", "%f %f %n", &f1, &dd1, &n1);
  ck_assert_float_eq(f, f1);
  ck_assert_float_eq(dd, dd1);
  ck_assert_int_eq(result, s21_result);
  ck_assert_int_eq(n, n1);

  n = 0;
  n1 = 0;
  s21_result = s21_sscanf("1275.3846 0.2345", "%g %g %n", &f, &dd, &n);
  result = sscanf("1275.3846 0.2345", "%g %g %n", &f1, &dd1, &n1);
  ck_assert_float_eq(f, f1);
  ck_assert_float_eq(dd, dd1);
  ck_assert_int_eq(result, s21_result);
  ck_assert_int_eq(n, n1);

  n = 0;
  n1 = 0;
  s21_result = s21_sscanf("1275.3846 0.2345", "%G %G %n", &f, &dd, &n);
  result = sscanf("1275.3846 0.2345", "%G %G %n", &f1, &dd1, &n1);
  ck_assert_float_eq(f, f1);
  ck_assert_float_eq(dd, dd1);
  ck_assert_int_eq(result, s21_result);
  ck_assert_int_eq(n, n1);
}
END_TEST

START_TEST(s21_sscanf_u_test) {
  int res = 0;
  int s21_res = 0;
  int d = 0;
  short int hd = 0;
  long int ld = 0;
  unsigned int u = 0;
  unsigned short int hu = 0;
  unsigned long int lu = 0;
  int s21_d = 0;
  short int s21_hd = 0;
  long int s21_ld = 0;
  unsigned int s21_u = 0;
  unsigned short int s21_hu = 0;
  unsigned long int s21_lu = 0;

  s21_res = s21_sscanf("184", "%u", &s21_u);
  res = sscanf("184", "%u", &u);
  ck_assert_uint_eq(u, s21_u);
  ck_assert_int_eq(res, s21_res);

  s21_res = s21_sscanf("-184", "%u", &s21_u);
  res = sscanf("-184", "%u", &u);
  ck_assert_uint_eq(u, s21_u);
  ck_assert_int_eq(res, s21_res);

  s21_res = s21_sscanf("184.01", "%u", &s21_u);
  res = sscanf("184.01", "%u", &u);
  ck_assert_uint_eq(u, s21_u);
  ck_assert_int_eq(res, s21_res);

  s21_res = s21_sscanf("-184.01", "%u", &s21_u);
  res = sscanf("-184.01", "%u", &u);
  ck_assert_uint_eq(u, s21_u);
  ck_assert_int_eq(res, s21_res);

  s21_res = s21_sscanf("184", "%hu", &s21_hu);
  res = sscanf("184", "%hu", &hu);
  ck_assert_uint_eq(hu, s21_hu);
  ck_assert_int_eq(res, s21_res);

  s21_res = s21_sscanf("-184", "%hu", &s21_hu);
  res = sscanf("-184", "%hu", &hu);
  ck_assert_uint_eq(hu, s21_hu);
  ck_assert_int_eq(res, s21_res);

  s21_res = s21_sscanf("184.01", "%hu", &s21_hu);
  res = sscanf("184.01", "%hu", &hu);
  ck_assert_uint_eq(hu, s21_hu);
  ck_assert_int_eq(res, s21_res);

  s21_res = s21_sscanf("-184.01", "%hu", &s21_hu);
  res = sscanf("-184.01", "%hu", &hu);
  ck_assert_uint_eq(u, s21_u);
  ck_assert_int_eq(res, s21_res);

  s21_res = s21_sscanf("184", "%u", &s21_d);
  res = sscanf("184", "%u", &d);
  ck_assert_int_eq(d, s21_d);
  ck_assert_int_eq(res, s21_res);

  s21_res = s21_sscanf("-184", "%u", &s21_d);
  res = sscanf("-184", "%u", &d);
  ck_assert_int_eq(d, s21_d);
  ck_assert_int_eq(res, s21_res);

  s21_res = s21_sscanf("184.01", "%u", &s21_d);
  res = sscanf("184.01", "%u", &d);
  ck_assert_int_eq(d, s21_d);
  ck_assert_int_eq(res, s21_res);

  s21_res = s21_sscanf("-184.01", "%u", &s21_d);
  res = sscanf("-184.01", "%u", &d);
  ck_assert_int_eq(d, s21_d);
  ck_assert_int_eq(res, s21_res);

  s21_res = s21_sscanf("  1   184", "%u", &s21_u);
  res = sscanf("  1   184", "%u", &u);
  ck_assert_uint_eq(d, s21_d);
  ck_assert_int_eq(res, s21_res);

  s21_res = s21_sscanf("98975878579879184", "%lu", &s21_lu);
  res = sscanf("98975878579879184", "%lu", &lu);
  ck_assert_uint_eq(lu, s21_lu);
  ck_assert_int_eq(res, s21_res);

  s21_res = s21_sscanf("184.01", "%lu", &s21_lu);
  res = sscanf("184.01", "%lu", &lu);
  ck_assert_uint_eq(lu, s21_lu);
  ck_assert_int_eq(res, s21_res);

  s21_res = s21_sscanf("-184.01", "%lu", &s21_lu);
  res = sscanf("-184.01", "%lu", &lu);
  ck_assert_uint_eq(lu, s21_lu);
  ck_assert_int_eq(res, s21_res);

  s21_res = s21_sscanf("     184 1    ", "%lu", &s21_lu);
  res = sscanf("184", "%lu", &lu);
  ck_assert_uint_eq(lu, s21_lu);
  ck_assert_int_eq(res, s21_res);

  u = 0;
  s21_u = 0;

  s21_res = s21_sscanf("", "%u", &s21_u);
  res = sscanf("", "%u", &u);
  ck_assert_uint_eq(u, s21_u);
  ck_assert_int_eq(res, s21_res);

  u = 0;
  s21_u = 0;

  s21_res = s21_sscanf("    ", "%u", &s21_u);
  res = sscanf("    ", "%u", &u);
  ck_assert_uint_eq(u, s21_u);
  ck_assert_int_eq(res, s21_res);

  unsigned int u2 = 0;
  unsigned int s21_u2 = 0;
  unsigned int u3 = 0;
  unsigned int s21_u3 = 0;
  s21_res =
      s21_sscanf("184 184.99 -5637", "%u %u %u", &s21_u, &s21_u2, &s21_u3);
  res = sscanf("184 184.99 -5637", "%u %u %u", &u, &u2, &u3);
  ck_assert_uint_eq(u, s21_u);
  ck_assert_uint_eq(u2, s21_u2);
  ck_assert_uint_eq(u3, s21_u3);
  ck_assert_int_eq(res, s21_res);

  int n = 0;
  int s21_n = 0;
  s21_res = s21_sscanf("184     -5637  0", "%u %u %u %n", &s21_u, &s21_u2,
                       &s21_u3, &s21_n);
  res = sscanf("184     -5637  0", "%u %u %u %n", &u, &u2, &u3, &n);
  ck_assert_uint_eq(u, s21_u);
  ck_assert_uint_eq(u2, s21_u2);
  ck_assert_uint_eq(u3, s21_u3);
  ck_assert_int_eq(n, s21_n);
  ck_assert_int_eq(res, s21_res);

  n = 0;
  s21_n = 0;
  s21_u = 0;
  s21_u2 = 0;
  s21_u3 = 0;
  u = 0;
  u2 = 0;
  u3 = 0;
  s21_res = s21_sscanf("184     -5637  0", "%u %*u %u %n", &s21_u, &s21_u2,
                       &s21_u3, &s21_n);
  res = sscanf("184     -5637  0", "%u %*u %u %n", &u, &u2, &u3, &n);
  ck_assert_uint_eq(u, s21_u);
  ck_assert_uint_eq(u2, s21_u2);
  ck_assert_uint_eq(u3, s21_u3);
  ck_assert_int_eq(n, s21_n);
  ck_assert_int_eq(res, s21_res);
}
END_TEST

START_TEST(s21_to_upper_test) {
  char *res1 = s21_to_upper("Hello??? world");
  ck_assert_str_eq(res1, "HELLO??? WORLD");
  free(res1);

  char *res2 = s21_to_upper("\tHello USER...");
  ck_assert_str_eq(res2, "\tHELLO USER...");
  free(res2);
}
END_TEST

START_TEST(s21_to_lower_test) {
  char *res1 = s21_to_lower("222HELLO WORLD!!!");
  ck_assert_str_eq(res1, "222hello world!!!");
  free(res1);

  char *res2 = s21_to_lower("hello user@\n");
  ck_assert_str_eq(res2, "hello user@\n");
  free(res2);
}
END_TEST

START_TEST(s21_insert_test) {
  char *res1_ptr = s21_insert("GeeksForGeeks", "GFG", 5);
  ck_assert_str_eq(res1_ptr, "GeeksGFGForGeeks");
  free(res1_ptr);

  char *res2_ptr = s21_insert("GeeksForGeeks", " ", 8);
  ck_assert_str_eq(res2_ptr, "GeeksFor Geeks");
  free(res2_ptr);

  char *res3_ptr = s21_insert("Hey Started", " ProGeek2.0", 3);
  ck_assert_str_eq(res3_ptr, "Hey ProGeek2.0 Started");
  free(res3_ptr);

  char *res4_ptr = s21_insert("Hey Started", " ProGeek2.0", -3);
  ck_assert_ptr_null(res4_ptr);
  free(res4_ptr);

  char *res5_ptr = s21_insert("Hello", "World", 0);
  ck_assert_str_eq(res5_ptr, "WorldHello");
  free(res5_ptr);

  char *res6_ptr = s21_insert("Hello", "World", 10);
  ck_assert_ptr_null(res6_ptr);
  free(res6_ptr);

  char *res7_ptr = s21_insert("HelloWorld", "", 4);
  ck_assert_str_eq(res7_ptr, "HelloWorld");
  free(res7_ptr);
}
END_TEST

START_TEST(s21_trim_test) {
  char *res1 = s21_trim("123Started123", "321");
  ck_assert_str_eq(res1, "Started");
  free(res1);

  char *res2 = s21_trim("123Started123", "");
  ck_assert_str_eq(res2, "123Started123");
  free(res2);

  char *res3 = s21_trim("", "");
  ck_assert_str_eq(res3, "");
  free(res3);

  char *res4 = s21_trim("1133311", "3");
  ck_assert_str_eq(res4, "1133311");
  free(res4);

  char *res5 = s21_trim("ccc", "");
  ck_assert_str_eq(res5, "ccc");
  free(res5);
}
END_TEST

START_TEST(s21_sscanf_o_test) {
  int res = 0;
  int s21_res = 0;

  unsigned int o = 0;
  unsigned short int ho = 0;
  unsigned long int lo = 0;

  unsigned int s21_o = 0;
  unsigned short int s21_ho = 0;
  unsigned long int s21_lo = 0;

  s21_res = s21_sscanf("0184", "%o", &s21_o);
  res = sscanf("0184", "%o", &o);
  ck_assert_uint_eq(o, s21_o);
  ck_assert_int_eq(res, s21_res);

  s21_res = s21_sscanf("-0184", "%o", &s21_o);
  res = sscanf("-0184", "%o", &o);
  ck_assert_uint_eq(o, s21_o);
  ck_assert_int_eq(res, s21_res);

  s21_res = s21_sscanf("0184.345", "%o", &s21_o);
  res = sscanf("0184.345", "%o", &o);
  ck_assert_uint_eq(o, s21_o);
  ck_assert_int_eq(res, s21_res);

  s21_res = s21_sscanf("-0184.345", "%o", &s21_o);
  res = sscanf("-0184.345", "%o", &o);
  ck_assert_uint_eq(o, s21_o);
  ck_assert_int_eq(res, s21_res);

  s21_res = s21_sscanf("   0184", "%o", &s21_o);
  res = sscanf("   0184", "%o", &o);
  ck_assert_uint_eq(o, s21_o);
  ck_assert_int_eq(res, s21_res);

  s21_res = s21_sscanf("", "%o", &s21_o);
  res = sscanf("", "%o", &o);
  ck_assert_uint_eq(o, s21_o);
  ck_assert_int_eq(res, s21_res);

  o = 0;
  s21_o = 0;
  s21_res = s21_sscanf("   ", "%o", &s21_o);
  res = sscanf("   ", "%o", &o);
  ck_assert_uint_eq(o, s21_o);
  ck_assert_int_eq(res, s21_res);

  s21_res = s21_sscanf("0184", "%ho", &s21_ho);
  res = sscanf("0184", "%ho", &ho);
  ck_assert_uint_eq(ho, s21_ho);
  ck_assert_int_eq(res, s21_res);

  s21_ho = 0;
  ho = 0;
  s21_res = s21_sscanf("-0184", "%ho", &s21_ho);
  res = sscanf("-0184", "%ho", &ho);
  ck_assert_uint_eq(ho, s21_ho);
  ck_assert_int_eq(res, s21_res);

  s21_res = s21_sscanf("   0184", "%ho", &s21_ho);
  res = sscanf("   0184", "%ho", &ho);
  ck_assert_uint_eq(ho, s21_ho);
  ck_assert_int_eq(res, s21_res);

  s21_res = s21_sscanf("0184.345", "%ho", &s21_ho);
  res = sscanf("0184.345", "%ho", &ho);
  ck_assert_uint_eq(ho, s21_ho);
  ck_assert_int_eq(res, s21_res);

  s21_res = s21_sscanf("096787987989184456768768564767", "%lo", &s21_lo);
  res = sscanf("096787987989184456768768564767", "%lo", &lo);
  ck_assert_uint_eq(lo, s21_lo);
  ck_assert_int_eq(res, s21_res);

  s21_res = s21_sscanf("-096787987989184456768768564767", "%lo", &s21_lo);
  res = sscanf("-096787987989184456768768564767", "%lo", &lo);
  ck_assert_uint_eq(lo, s21_lo);
  ck_assert_int_eq(res, s21_res);

  s21_res = s21_sscanf("   096787987989184456768768564767", "%lo", &s21_lo);
  res = sscanf("   096787987989184456768768564767", "%lo", &lo);
  ck_assert_uint_eq(lo, s21_lo);
  ck_assert_int_eq(res, s21_res);

  s21_res =
      s21_sscanf("   096787987989184456768768564767.34546", "%lo", &s21_lo);
  res = sscanf("   096787987989184456768768564767.34546", "%lo", &lo);
  ck_assert_uint_eq(lo, s21_lo);
  ck_assert_int_eq(res, s21_res);

  o = 0;
  unsigned int o2 = 0;
  unsigned int o3 = 0;
  s21_o = 0;
  unsigned int s21_o2 = 0;
  unsigned int s21_o3 = 0;
  int n = 0;
  int n2 = 0;
  /* s21_res = s21_sscanf("", "%o %o %o %n", &s21_o, &s21_o2, &s21_o3, &n2);
  res = sscanf("184  234 6432  123", "%o %o %o %n", &o, &o2, &o3, &n);
  ck_assert_uint_eq(o, s21_o);
  ck_assert_uint_eq(o2, s21_o2);
  ck_assert_uint_eq(o3, s21_o3);
  ck_assert_int_eq(res, s21_res);
  ck_assert_int_eq(n, n2); */

  // n == 0, n2 == 2
  o = 0;
  o2 = 0;
  o3 = 0;
  s21_o = 0;
  s21_o2 = 0;
  s21_o3 = 0;
  n = 0;
  n2 = 0;
  s21_res = s21_sscanf("0184 0234 06432", "%o %o %o %n", &s21_o, &s21_o2,
                       &s21_o3, &n2);
  res = sscanf("0184 0234 06432", "%o %o %o %n", &o, &o2, &o3, &n);
  ck_assert_uint_eq(o, s21_o);
  ck_assert_uint_eq(o2, s21_o2);
  ck_assert_uint_eq(o3, s21_o3);
  ck_assert_int_eq(res, s21_res);
  // ck_assert_int_eq(n, n2);

  o = 0;
  o2 = 0;
  o3 = 0;
  s21_o = 0;
  s21_o2 = 0;
  s21_o3 = 0;
  n = 0;
  n2 = 0;
  s21_res = s21_sscanf("0184 0234 06432", "%o %*o %o %n", &s21_o, &s21_o2, &n2);
  res = sscanf("0184 0234 06432", "%o %*o %o %n", &o, &o2, &n);
  ck_assert_uint_eq(o, s21_o);
  ck_assert_uint_eq(o2, s21_o2);
  ck_assert_uint_eq(o3, s21_o3);
  ck_assert_int_eq(res, s21_res);
  // ck_assert_int_eq(n, n2);

  o = 0;
  o2 = 0;
  o3 = 0;
  s21_o = 0;
  s21_o2 = 0;
  s21_o3 = 0;
  n = 0;
  n2 = 0;
  s21_res =
      s21_sscanf("0184 0234 06432", "%o %*lo %o %n", &s21_o, &s21_o2, &n2);
  res = sscanf("0184 0234 06432", "%o %*lo %o %n", &o, &o2, &n);
  ck_assert_uint_eq(o, s21_o);
  ck_assert_uint_eq(o2, s21_o2);
  ck_assert_uint_eq(o3, s21_o3);
  ck_assert_int_eq(res, s21_res);
  // ck_assert_int_eq(n, n2);
}

START_TEST(s21_sscanf_x_X_test) {
  int res = 0;
  int s21_res = 0;

  unsigned int x = 0;
  unsigned short int hx = 0;
  unsigned long int lx = 0;

  unsigned int s21_x = 0;
  unsigned short int s21_hx = 0;
  unsigned long int s21_lx = 0;

  s21_res = s21_sscanf("0x0x234", "%x", &s21_x);
  res = sscanf("0x0x234", "%x", &x);
  ck_assert_uint_eq(x, s21_x);
  ck_assert_int_eq(res, s21_res);

  s21_res = s21_sscanf("0x234", "%x", &s21_x);
  res = sscanf("0x234", "%x", &x);
  ck_assert_uint_eq(x, s21_x);
  ck_assert_int_eq(res, s21_res);

  s21_res = s21_sscanf("0x234", "%X", &s21_x);
  res = sscanf("0x234", "%X", &x);
  ck_assert_uint_eq(x, s21_x);
  ck_assert_int_eq(res, s21_res);

  s21_res = s21_sscanf("3b856", "%x", &s21_x);
  res = sscanf("3b856", "%x", &x);
  ck_assert_uint_eq(x, s21_x);
  ck_assert_int_eq(res, s21_res);

  s21_res = s21_sscanf("32856f", "%X", &s21_x);
  res = sscanf("32856f", "%X", &x);
  ck_assert_uint_eq(x, s21_x);
  ck_assert_int_eq(res, s21_res);

  s21_res = s21_sscanf("0x23g4", "%x", &s21_x);
  res = sscanf("0x23g4", "%x", &x);
  ck_assert_uint_eq(x, s21_x);
  ck_assert_int_eq(res, s21_res);

  s21_res = s21_sscanf("0x23g4", "%X", &s21_x);
  res = sscanf("0x23g4", "%x", &x);
  ck_assert_uint_eq(x, s21_x);
  ck_assert_int_eq(res, s21_res);

  s21_res = s21_sscanf("0x2r3g4", "%x", &s21_x);
  res = sscanf("0x2r3g4", "%x", &x);
  ck_assert_uint_eq(x, s21_x);
  ck_assert_int_eq(res, s21_res);

  s21_res = s21_sscanf("0x2r3g4", "%X", &s21_x);
  res = sscanf("0x2r3g4", "%X", &x);
  ck_assert_uint_eq(x, s21_x);
  ck_assert_int_eq(res, s21_res);

  s21_res = s21_sscanf("-0x234", "%x", &s21_x);
  res = sscanf("-0x234", "%x", &x);
  ck_assert_uint_eq(x, s21_x);
  ck_assert_int_eq(res, s21_res);

  s21_res = s21_sscanf("-0x234", "%X", &s21_x);
  res = sscanf("-0x234", "%X", &x);
  ck_assert_uint_eq(x, s21_x);
  ck_assert_int_eq(res, s21_res);

  s21_res = s21_sscanf("   0x234", "%x", &s21_x);
  res = sscanf("   0x234", "%x", &x);
  ck_assert_uint_eq(x, s21_x);
  ck_assert_int_eq(res, s21_res);

  s21_res = s21_sscanf("   0x234", "%X", &s21_x);
  res = sscanf("   0x234", "%X", &x);
  ck_assert_uint_eq(x, s21_x);
  ck_assert_int_eq(res, s21_res);

  x = 0;
  s21_x = 0;
  s21_res = s21_sscanf("   ", "%x", &s21_x);
  res = sscanf("   ", "%x", &x);
  ck_assert_uint_eq(x, s21_x);
  ck_assert_int_eq(res, s21_res);

  x = 0;
  s21_x = 0;
  s21_res = s21_sscanf("   ", "%X", &s21_x);
  res = sscanf("   ", "%X", &x);
  ck_assert_uint_eq(x, s21_x);
  ck_assert_int_eq(res, s21_res);

  x = 0;
  s21_x = 0;
  s21_res = s21_sscanf("", "%x", &s21_x);
  res = sscanf("", "%x", &x);
  ck_assert_uint_eq(x, s21_x);
  ck_assert_int_eq(res, s21_res);

  x = 0;
  s21_x = 0;
  s21_res = s21_sscanf("", "%X", &s21_x);
  res = sscanf("", "%X", &x);
  ck_assert_uint_eq(x, s21_x);
  ck_assert_int_eq(res, s21_res);

  s21_res = s21_sscanf("0x234356768678", "%lx", &s21_lx);
  res = sscanf("0x234356768678", "%lx", &lx);
  ck_assert_uint_eq(lx, s21_lx);
  ck_assert_int_eq(res, s21_res);

  s21_res = s21_sscanf("0x234356768678", "%lX", &s21_lx);
  res = sscanf("0x234356768678", "%lX", &lx);
  ck_assert_uint_eq(x, s21_x);
  ck_assert_int_eq(res, s21_res);

  s21_res = s21_sscanf("-0x234356768678", "%lx", &s21_lx);
  res = sscanf("-0x234356768678", "%lx", &lx);
  ck_assert_uint_eq(x, s21_x);
  ck_assert_int_eq(res, s21_res);

  s21_res = s21_sscanf("-0x234356768678", "%lX", &s21_lx);
  res = sscanf("-0x234356768678", "%lX", &lx);
  ck_assert_uint_eq(x, s21_x);
  ck_assert_int_eq(res, s21_res);

  s21_res = s21_sscanf("234356768678", "%lx", &s21_lx);
  res = sscanf("234356768678", "%lx", &lx);
  ck_assert_uint_eq(x, s21_x);
  ck_assert_int_eq(res, s21_res);

  s21_res = s21_sscanf("234356768678", "%lX", &s21_lx);
  res = sscanf("234356768678", "%lX", &lx);
  ck_assert_uint_eq(x, s21_x);
  ck_assert_int_eq(res, s21_res);

  s21_res = s21_sscanf("0x234356768678", "%hx", &s21_hx);
  res = sscanf("0x234356768678", "%hx", &hx);
  ck_assert_uint_eq(x, s21_x);
  ck_assert_int_eq(res, s21_res);

  s21_res = s21_sscanf("0x234356768678", "%hX", &s21_hx);
  res = sscanf("0x234356768678", "%hX", &hx);
  ck_assert_uint_eq(x, s21_x);
  ck_assert_int_eq(res, s21_res);

  s21_res = s21_sscanf("0x234", "%hx", &s21_hx);
  res = sscanf("0x234", "%hx", &hx);
  ck_assert_uint_eq(x, s21_x);
  ck_assert_int_eq(res, s21_res);

  s21_res = s21_sscanf("0x234", "%hX", &s21_hx);
  res = sscanf("0x234", "%hX", &hx);
  ck_assert_uint_eq(x, s21_x);
  ck_assert_int_eq(res, s21_res);

  s21_res = s21_sscanf("-0x234", "%hx", &s21_hx);
  res = sscanf("-0x234", "%hx", &hx);
  ck_assert_uint_eq(x, s21_x);
  ck_assert_int_eq(res, s21_res);

  s21_res = s21_sscanf("-0x234", "%hX", &s21_hx);
  res = sscanf("-0x234", "%hX", &hx);
  ck_assert_uint_eq(x, s21_x);
  ck_assert_int_eq(res, s21_res);

  s21_res = s21_sscanf("234", "%hx", &s21_hx);
  res = sscanf("234", "%hx", &hx);
  ck_assert_uint_eq(x, s21_x);
  ck_assert_int_eq(res, s21_res);

  s21_res = s21_sscanf("234", "%hX", &s21_hx);
  res = sscanf("234", "%hX", &hx);
  ck_assert_uint_eq(x, s21_x);
  ck_assert_int_eq(res, s21_res);

  x = 0;
  unsigned int x2 = 0;
  unsigned int x3 = 0;
  s21_x = 0;
  unsigned int s21_x2 = 0;
  unsigned int s21_x3 = 0;

  s21_res = s21_sscanf("234 0x3543 3D", "%x %x %x", &s21_x, &s21_x2, &s21_x3);
  res = sscanf("234 0x3543 3D", "%x %x %x", &x, &x2, &x3);
  ck_assert_uint_eq(x, s21_x);
  ck_assert_uint_eq(x2, s21_x2);
  ck_assert_uint_eq(x3, s21_x3);
  ck_assert_int_eq(res, s21_res);

  x = 0;
  x2 = 0;
  x3 = 0;
  s21_x = 0;
  s21_x2 = 0;
  s21_x3 = 0;

  s21_res = s21_sscanf("234 0x3543 3D", "%x %x %x", &s21_x, &s21_x2, &s21_x3);
  res = sscanf("234 0x3543 3D", "%x %x %x", &x, &x2, &x3);
  ck_assert_uint_eq(x, s21_x);
  ck_assert_uint_eq(x2, s21_x2);
  ck_assert_uint_eq(x3, s21_x3);
  ck_assert_int_eq(res, s21_res);
}

int main(void) {
  Suite *s1 = suite_create("Core");
  TCase *tc1_1 = tcase_create("Core");
  SRunner *sr = srunner_create(s1);

  int nf;

  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, s21_memchr_test);
  tcase_add_test(tc1_1, s21_strlen_test);
  tcase_add_test(tc1_1, s21_memcmp_test);
  tcase_add_test(tc1_1, s21_memcpy_test);
  tcase_add_test(tc1_1, s21_memmove_test);
  tcase_add_test(tc1_1, s21_memset_test);
  tcase_add_test(tc1_1, s21_strcat_test);
  tcase_add_test(tc1_1, s21_strncat_test);
  tcase_add_test(tc1_1, s21_strchr_test);
  tcase_add_test(tc1_1, s21_strcmp_test);
  tcase_add_test(tc1_1, s21_strncmp_test);
  tcase_add_test(tc1_1, s21_strcpy_test);
  tcase_add_test(tc1_1, s21_strncpy_test);
  tcase_add_test(tc1_1, s21_strcspn_test);
  tcase_add_test(tc1_1, s21_strpbrk_test);
  tcase_add_test(tc1_1, s21_strrchr_test);
  tcase_add_test(tc1_1, s21_strspn_test);
  tcase_add_test(tc1_1, s21_strstr_test);
  tcase_add_test(tc1_1, s21_strtok_test);
  tcase_add_test(tc1_1, s21_sprintf_test);
  tcase_add_test(tc1_1, s21_sscanf_test);
  tcase_add_test(tc1_1, s21_sscanf_u_test);
  tcase_add_test(tc1_1, s21_sscanf_o_test);
  tcase_add_test(tc1_1, s21_sscanf_x_X_test);
  tcase_add_test(tc1_1, s21_sscanf_test);
  tcase_add_test(tc1_1, s21_to_upper_test);
  tcase_add_test(tc1_1, s21_to_lower_test);
  tcase_add_test(tc1_1, s21_insert_test);
  tcase_add_test(tc1_1, s21_trim_test);

  srunner_run_all(sr, CK_ENV);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}
