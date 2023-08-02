#include <math.h>
#include <stdio.h>

#include "s21_string.h"

typedef struct flag_params_flag {
  int minus_flag;
  int plus_flag;
  int space_flag;
  int ceil_flag;
  int null_flag;
  int general;
} flag;

struct flag_params {
  flag flag;
  int width;
  int precision;
  char length;
  char specifier;
};

int get_params_for_struct(struct flag_params *format_params, char *format);
int get_flag_from_format(struct flag_params *format_params, char format);
int sp_get_width_from_format(struct flag_params *format_params, char *format);
int get_precision_from_format(struct flag_params *format_params, char *format);
int sp_get_specifier_from_format(struct flag_params *format_params,
                                 char format);
int sp_get_length_from_format(struct flag_params *format_params, char format);

int check_correct_syntax(struct flag_params format_params);
void check_char_specificator(struct flag_params format_params, int *error);
void check_int_specificators(struct flag_params format_params, int *error);
void check_float_pointer_specificator(struct flag_params format_params,
                                      int *error);
void check_u_int_specificators(struct flag_params format_params, int *error);
void check_string_specificator(struct flag_params format_params, int *error);
void check_other_specificators(struct flag_params format_params, int *error);
void check_flags(struct flag_params format_params, int *error);

void c_specifier(char *str, wchar_t sym, struct flag_params format_params);
void sp_d_specifier(char *str, long long int num,
                    struct flag_params format_params);
void e_specifier(char *str, long double num, struct flag_params format_params);

void sp_f_specifier(char *str, long double num,
                    struct flag_params format_params);
void g_specifier(char *str, long double num, struct flag_params format_params);
void sp_s_specifier(char *str, char *new_str, struct flag_params format_params);
void sp_o_specifier(char *str, unsigned long long int num,
                    struct flag_params format_params);
void sp_u_specifier(char *str, unsigned long long int num,
                    struct flag_params format_params);
void sp_x_specifier(char *str, unsigned long long int num,
                    struct flag_params format_params);
void sp_p_specifier(char *str, unsigned long long int num,
                    struct flag_params format_params);

void precision_adder(char *result_str, char *added_str,
                     struct flag_params format_params);
void flag_adder(char *str, struct flag_params format_params);
void width_adder(char *result_str, struct flag_params format_params);
long long int int_length_adder(long long int num,
                               struct flag_params format_params);
unsigned long long u_int_length_adder(long long unsigned num,
                                      struct flag_params format_params);

int make_int_from_str(char *str, int *index);
void make_str_from_num(char *str, long long int num);
void make_str_from_unsigned_num(char *str, unsigned long long int num);
void make_round(long double *num, int precision);
int make_normal_exp_num(long double *num);

void remove_null_from_str(char *str, struct flag_params format_params);

void add_exp_to_string(char *str, int exp_deg,
                       struct flag_params format_params);
void add_char_to_string(char *str, wchar_t sym);
void add_sym_to_begin_of_str(char *str, char sym);

int s21_sprintf(char *str, const char *format, ...) {
  str[0] = '\0';
  int str_len = s21_strlen(str);
  str[str_len] = s21_NULL;
  char *non_const_format = (char *)format;
  char buffer[2042] = {'\0'};

  va_list params_list;
  va_start(params_list, format);

  int error = 0;
  while (*non_const_format && !error) {
    struct flag_params format_params = {{0}, 0, 0, 0, 0};

    if (*non_const_format == '%') {
      non_const_format++;
      int shift = get_params_for_struct(&format_params, non_const_format);
      non_const_format += shift;

      if (format_params.width == '*') {
        int width = va_arg(params_list, int);
        format_params.width = abs(width);
        if (width < 0) {
          format_params.flag.minus_flag = 1;
        }
      }
      if (format_params.precision == '*') {
        int precision = va_arg(params_list, int);
        precision = (precision < 0) ? -1 : precision;
        format_params.precision = precision;
      }

      error = check_correct_syntax(format_params);
      // printf("%c %d %d %d %d\n", format_params.specifier,
      // format_params.width, format_params.precision, format_params.length,
      // format_params.flag.general);
      if (!error) {
        switch (format_params.specifier) {
          case 'c':
            if (format_params.length == 'l')
              c_specifier(buffer, va_arg(params_list, wchar_t), format_params);
            else
              c_specifier(buffer, va_arg(params_list, int), format_params);
            break;
          case 'd':
          case 'i':
            if (format_params.length == 'l')
              sp_d_specifier(buffer, va_arg(params_list, long long int),
                             format_params);
            else
              sp_d_specifier(buffer, va_arg(params_list, int), format_params);
            break;
          case 'e':
          case 'E':
            if (format_params.length == 'L')
              e_specifier(buffer, va_arg(params_list, long double),
                          format_params);
            else
              e_specifier(buffer, va_arg(params_list, double), format_params);
            break;
          case 'f':
            if (format_params.length == 'L')
              sp_f_specifier(buffer, va_arg(params_list, long double),
                             format_params);
            else
              sp_f_specifier(buffer, va_arg(params_list, double),
                             format_params);
            break;
          case 'g':
          case 'G':
            if (format_params.length == 'L')
              g_specifier(buffer, va_arg(params_list, long double),
                          format_params);
            else
              g_specifier(buffer, va_arg(params_list, double), format_params);
            break;
          case 's':
            sp_s_specifier(buffer, va_arg(params_list, char *), format_params);
            break;
          case 'o':
            if (format_params.length == 'l')
              sp_o_specifier(buffer,
                             va_arg(params_list, unsigned long long int),
                             format_params);
            else
              sp_o_specifier(buffer, va_arg(params_list, unsigned int),
                             format_params);
            break;
          case 'u':
            if (format_params.length == 'l')
              sp_u_specifier(buffer,
                             va_arg(params_list, unsigned long long int),
                             format_params);
            else
              sp_u_specifier(buffer, va_arg(params_list, unsigned int),
                             format_params);
            break;
          case 'x':
          case 'X':
            if (format_params.length == 'l')
              sp_x_specifier(buffer,
                             va_arg(params_list, unsigned long long int),
                             format_params);
            else
              sp_x_specifier(buffer, va_arg(params_list, unsigned int),
                             format_params);
            break;
          case 'p':
            sp_p_specifier(buffer, va_arg(params_list, unsigned long long int),
                           format_params);
            break;
          case 'n':
            *va_arg(params_list, int *) = s21_strlen(buffer);
            break;
          case '%':
            s21_strcat(buffer, "%");
          default:
            break;
        }
      }
    } else {
      add_char_to_string(buffer, *non_const_format);
      non_const_format++;
    }
  }
  va_end(params_list);

  int result = -1;
  if (!error) {
    str = s21_strcat(str, buffer);
    result = s21_strlen(buffer);
  }

  return result;
}

int check_correct_syntax(struct flag_params format_params) {
  int error = 0;
  if (format_params.specifier == -1) {
    error = 1;
  }
  check_char_specificator(format_params, &error);
  check_int_specificators(format_params, &error);
  check_float_pointer_specificator(format_params, &error);
  check_u_int_specificators(format_params, &error);
  check_string_specificator(format_params, &error);
  check_other_specificators(format_params, &error);
  check_flags(format_params, &error);
  return error;
}

void check_char_specificator(struct flag_params format_params, int *error) {
  if (format_params.specifier == 'c') {
    if (format_params.flag.ceil_flag || format_params.flag.null_flag ||
        format_params.flag.plus_flag || format_params.flag.space_flag) {
      *error = 1;
    }
    if (format_params.precision != -1) {
      *error = 1;
    }
    if (format_params.length == 'h' || format_params.length == 'L') {
      *error = 1;
    }
  }
}

void check_int_specificators(struct flag_params format_params, int *error) {
  if (format_params.specifier == 'd' || format_params.specifier == 'i') {
    if (format_params.flag.ceil_flag) {
      *error = 1;
    }
    if (format_params.length == 'L') {
      *error = 1;
    }
  }
}

void check_float_pointer_specificator(struct flag_params format_params,
                                      int *error) {
  if (format_params.specifier == 'e' || format_params.specifier == 'E' ||
      format_params.specifier == 'f' || format_params.specifier == 'g' ||
      format_params.specifier == 'G') {
    if (format_params.length == 'h') {
      *error = 1;
    }
  }
}

void check_u_int_specificators(struct flag_params format_params, int *error) {
  if (format_params.specifier == 'u' || format_params.specifier == 'o' ||
      format_params.specifier == 'X' || format_params.specifier == 'x') {
    if (format_params.flag.space_flag || format_params.flag.plus_flag) {
      *error = 1;
    }
    if (format_params.length == 'L') {
      *error = 1;
    }
  }
  if (format_params.specifier == 'u') {
    if (format_params.flag.ceil_flag) {
      *error = 1;
    }
  }
}

void check_string_specificator(struct flag_params format_params, int *error) {
  if (format_params.specifier == 's') {
    if (format_params.flag.ceil_flag || format_params.flag.null_flag ||
        format_params.flag.plus_flag || format_params.flag.space_flag) {
      *error = 1;
    }
    if (format_params.length == 'h' || format_params.length == 'L') {
      *error = 1;
    }
  }
}

void check_other_specificators(struct flag_params format_params, int *error) {
  if (format_params.specifier == 'n' || format_params.specifier == '%') {
    if (format_params.flag.general != 0 || format_params.length != -1 ||
        format_params.precision != -1 || format_params.width != -1) {
      *error = 1;
    }
  }
}
void check_flags(struct flag_params format_params, int *error) {
  if (format_params.flag.general == -1) {
    *error = 1;
  }
  if (format_params.flag.plus_flag && format_params.flag.space_flag) {
    *error = 1;
  }
  if ((format_params.flag.null_flag) && (format_params.precision != -1)) {
    *error = 1;
  }
}

void c_specifier(char *str, wchar_t sym, struct flag_params format_params) {
  if (format_params.length != 'l') sym = (char)sym;
  char buffer[100] = {s21_NULL};
  add_char_to_string(buffer, sym);
  width_adder(buffer, format_params);

  s21_strcat(str, buffer);
}

void sp_d_specifier(char *str, long long int num,
                    struct flag_params format_params) {
  char buffer[100] = {s21_NULL};
  num = int_length_adder(num, format_params);
  char string_num[100] = {s21_NULL};
  if (num < 0) {
    s21_strcat(buffer, "-");
  }
  num = (num < 0) ? -num : num;
  flag_adder(buffer, format_params);
  make_str_from_num(string_num, num);
  if (!(num == 0 && format_params.precision == 0)) {
    precision_adder(buffer, string_num, format_params);
  }
  width_adder(buffer, format_params);
  s21_strcat(str, buffer);
}

void e_specifier(char *str, long double num, struct flag_params format_params) {
  char buffer[100] = {0};

  int exp_deg = make_normal_exp_num(&num);
  sp_f_specifier(buffer, num, format_params);
  add_exp_to_string(buffer, exp_deg, format_params);
  width_adder(buffer, format_params);
  s21_strcat(str, buffer);
}

void sp_f_specifier(char *str, long double num,
                    struct flag_params format_params) {
  char buffer[100] = {0};

  buffer[0] = (num < 0) ? '-' : '\0';
  flag_adder(buffer, format_params);

  if (format_params.length == 'L')
    num = (long double)num;
  else
    num = (double)num;

  num = (num < 0) ? -num : num;

  long long int int_num = (long long int)num;
  make_str_from_num(buffer, int_num);

  if (format_params.precision != 0 || format_params.flag.ceil_flag)
    s21_strcat(buffer, ".");

  long double temp_num = num - (long long int)num;
  format_params.precision =
      (format_params.precision == -1) ? 6 : format_params.precision;
  make_round(&temp_num, format_params.precision);

  for (int i = 0; i < format_params.precision; i++) {
    if (temp_num == 0.) {
      s21_strcat(buffer, "0");
    } else {
      temp_num *= 10;
      char c = (int)temp_num + '0';
      add_char_to_string(buffer, c);
    }
    temp_num -= (int)temp_num;
  }
  if (format_params.specifier == 'f') width_adder(buffer, format_params);

  s21_strcat(str, buffer);
}

void g_specifier(char *str, long double num, struct flag_params format_params) {
  char buffer[100] = {s21_NULL};
  if (format_params.precision == -1) {
    format_params.precision = 6;
  }
  if (format_params.precision == 0) {
    format_params.precision = 1;
  }

  if (format_params.length == 'L')
    num = (long double)num;
  else
    num = (double)num;

  double max_num = pow(10, format_params.precision);
  double min_num = 0.0001;
  long double temp_num = (num < 0) ? -num : num;

  if (num < 0) s21_strcat(buffer, "-");

  if (num != 0) flag_adder(buffer, format_params);

  /* е */
  if (((temp_num >= max_num) || (temp_num <= min_num)) && temp_num != 0) {
    // Доведение числа до нормального типа x.xxxxx
    int exp_deg = make_normal_exp_num(&temp_num);

    // Занесение всех цифр числа в буффер
    make_round(&temp_num, format_params.precision);
    for (int i = 0; i < format_params.precision; i++) {
      make_str_from_num(buffer, (int)temp_num);
      if (i == 0) s21_strcat(buffer, ".");
      temp_num = (temp_num - (int)temp_num) * 10;
    }
    // Убираем лишние нули и точку с конца в буфере
    if (!format_params.flag.ceil_flag) {
      remove_null_from_str(buffer, format_params);
    }
    // Добавляем е
    add_exp_to_string(buffer, exp_deg, format_params);
  }

  /* 123 */
  else {
    int ten = 0;
    if (temp_num >= 1) {
      ten -= (int)s21_strlen(buffer);
      make_round(&temp_num, format_params.precision);
      make_str_from_num(buffer, (int)temp_num);
      ten += (int)s21_strlen(buffer);
      if (ten < format_params.precision) {
        add_char_to_string(buffer, '.');
        while (ten < format_params.precision) {
          temp_num = (temp_num - (int)temp_num) * 10;
          add_char_to_string(buffer, (int)temp_num + '0');
          ten++;
        }
      }
    }

    else if (temp_num < 1 && temp_num > 0) {
      int flag = 0;
      s21_strcat(buffer, "0.");
      while (ten < format_params.precision) {
        temp_num *= 10;
        if ((int)(temp_num) != 0) {
          flag = 1;
          make_round(&temp_num, format_params.precision);
        }
        if (flag) {
          ten++;
        }
        add_char_to_string(buffer, (int)temp_num + '0');
        temp_num -= (int)temp_num;
      }
    } else if (temp_num == 0.) {
      if (format_params.flag.ceil_flag) {
        format_params.precision -= 1;
        sp_f_specifier(buffer, temp_num, format_params);
      } else {
        sp_f_specifier(buffer, temp_num, format_params);
        remove_null_from_str(buffer, format_params);
      }
    }

    if (!format_params.flag.ceil_flag) {
      remove_null_from_str(buffer, format_params);
    } else {
      if (ten == format_params.precision &&
          s21_strchr(buffer, '.') == s21_NULL) {
        s21_strcat(buffer, ".");
      }
    }
  }
  width_adder(buffer, format_params);
  s21_strcat(str, buffer);
}

void sp_s_specifier(char *str, char *new_str,
                    struct flag_params format_params) {
  char buffer[500] = {s21_NULL};
  s21_strcat(buffer, new_str);
  precision_adder(buffer, "\0", format_params);
  width_adder(buffer, format_params);

  s21_strcat(str, buffer);
}

void sp_o_specifier(char *str, unsigned long long int num,
                    struct flag_params format_params) {
  char buffer[100] = {s21_NULL};
  num = u_int_length_adder(num, format_params);

  unsigned long long int result = 0;
  unsigned long int d = 1;
  for (; num != 0; num /= 8) {
    result += (num % 8) * d;
    d *= 10;
  }
  sp_u_specifier(buffer, result, format_params);
  s21_strcat(str, buffer);
}

void sp_u_specifier(char *str, unsigned long long int num,
                    struct flag_params format_params) {
  char buffer[100] = {s21_NULL};
  num = u_int_length_adder(num, format_params);

  char string_num[100] = {s21_NULL};
  make_str_from_unsigned_num(string_num, num);
  precision_adder(buffer, string_num, format_params);
  if (format_params.specifier == 'o') {
    flag_adder(buffer, format_params);
  }
  width_adder(buffer, format_params);

  s21_strcat(str, buffer);
}

void sp_x_specifier(char *str, unsigned long long int num,
                    struct flag_params format_params) {
  char buffer[100] = {0};
  char string_num[100] = {0};
  int count = 0;
  char sym = 0;
  if (format_params.specifier == 'x' || format_params.specifier == 'X') {
    sym = format_params.specifier - 23;
  }
  if (format_params.specifier == 'p') {
    sym = 97;
  }

  num = u_int_length_adder(num, format_params);
  do {
    unsigned long long int x = num % 16;
    string_num[count++] = (x < 10) ? x + '0' : x - 10 + sym;
    num /= 16;
  } while (num > 0);

  for (int i = 0, j = s21_strlen(string_num) - 1; i < j; i++, j--) {
    int temp = string_num[i];
    string_num[i] = string_num[j];
    string_num[j] = temp;
  }

  if (format_params.specifier == 'x' || format_params.specifier == 'X') {
    precision_adder(buffer, string_num, format_params);
    flag_adder(buffer, format_params);
    width_adder(buffer, format_params);
  } else {
    s21_strcat(buffer, string_num);
  }

  s21_strcat(str, buffer);
}

void sp_p_specifier(char *str, unsigned long long int num,
                    struct flag_params format_params) {
  char buffer[100] = {0};
  s21_strcat(buffer, "0x");
  sp_x_specifier(buffer, num, format_params);

  width_adder(buffer, format_params);

  s21_strcat(str, buffer);
}

void flag_adder(char *str, struct flag_params format_params) {
  if (str[0] != '-' &&
      (format_params.specifier != 'o' && format_params.specifier != 'x' &&
       format_params.specifier != 'X')) {
    if (format_params.flag.plus_flag) {
      s21_strcat(str, "+");
    } else if (format_params.flag.space_flag) {
      s21_strcat(str, " ");
    }
  }
  if (format_params.flag.ceil_flag) {
    if (format_params.specifier == 'o' &&
        ((int)s21_strlen(str) > format_params.precision)) {
      add_sym_to_begin_of_str(str, '0');
    }
    if (format_params.specifier == 'x') {
      add_sym_to_begin_of_str(str, 'x');
      add_sym_to_begin_of_str(str, '0');
    }
    if (format_params.specifier == 'X') {
      add_sym_to_begin_of_str(str, 'X');
      add_sym_to_begin_of_str(str, '0');
    }
  }
}

void width_adder(char *result_str, struct flag_params format_params) {
  char sym = (format_params.flag.null_flag) ? '0' : ' ';

  if (format_params.width != -1) {
    if (!format_params.flag.minus_flag) {
      while ((int)s21_strlen(result_str) < format_params.width) {
        add_sym_to_begin_of_str(result_str, sym);
      }
    } else {
      while ((int)s21_strlen(result_str) < format_params.width) {
        add_char_to_string(result_str, sym);
      }
    }
  }
}

void precision_adder(char *result_str, char *added_str,
                     struct flag_params format_params) {
  if (format_params.specifier == 'd' || format_params.specifier == 'i' ||
      format_params.specifier == 'u' || format_params.specifier == 'o' ||
      format_params.specifier == 'x' || format_params.specifier == 'X' ||
      format_params.specifier == 'p') {
    if (format_params.precision != -1) {
      int added_str_length = s21_strlen(added_str);
      for (int i = format_params.precision - added_str_length; i > 0; i--) {
        s21_strcat(result_str, "0");
      }
    }
    s21_strcat(result_str, added_str);
  }
  if (format_params.specifier == 's' && format_params.precision != -1) {
    result_str[format_params.precision] = '\0';
  }
}

long long int int_length_adder(long long int num,
                               struct flag_params format_params) {
  long long result = num;
  if (format_params.length != -1) {
    if (format_params.length == 'h') {
      if (format_params.specifier == 'd' || format_params.specifier == 'i')
        result = (int short)num;
      if (format_params.specifier == 'u') result = (unsigned short)num;
    }
    if (format_params.length == 'l') {
      if (format_params.specifier == 'd' || format_params.specifier == 'i')
        result = (long long int)num;
    }
  }
  return result;
}

unsigned long long u_int_length_adder(long long unsigned num,
                                      struct flag_params format_params) {
  unsigned long long result = num;
  if (format_params.length != -1) {
    if (format_params.length == 'h') {
      result = (unsigned short)num;
    }
    if (format_params.length == 'l') {
      result = (unsigned long long int)num;
    }
  }
  return result;
}

int get_params_for_struct(struct flag_params *format_params, char *format) {
  int res = 0;
  int flag_res = 0;
  while (*format == '+' || *format == '-' || *format == ' ' || *format == '#' ||
         *format == '0') {
    flag_res += get_flag_from_format(format_params, *format++);
  }
  res += flag_res;
  if (format_params->flag.general != -1) {
    int width_res = sp_get_width_from_format(format_params, format);
    format += width_res;
    int precision_res = get_precision_from_format(format_params, format);
    format += precision_res;
    int length_res = sp_get_length_from_format(format_params, *format);
    format += length_res;
    int specifier_res = sp_get_specifier_from_format(format_params, *format);
    format += specifier_res;
    res += width_res + precision_res + length_res + specifier_res;
  }
  return res;
}

int get_flag_from_format(struct flag_params *format_params, char format) {
  int res = 0;
  if (format == '-') {
    if (format_params->flag.minus_flag != 1) {
      format_params->flag.minus_flag = 1;
      format_params->flag.general = 1;
      res++;
    } else
      format_params->flag.general = -1;
  } else if (format == '+') {
    if (format_params->flag.plus_flag != 1) {
      format_params->flag.plus_flag = 1;
      format_params->flag.general = 1;
      res++;
    } else
      format_params->flag.general = -1;
  } else if (format == ' ') {
    if (format_params->flag.space_flag != 1) {
      format_params->flag.space_flag = 1;
      format_params->flag.general = 1;
      res++;
    } else
      format_params->flag.general = -1;
  } else if (format == '#') {
    if (format_params->flag.ceil_flag != 1) {
      format_params->flag.ceil_flag = 1;
      format_params->flag.general = 1;
      res++;
    } else
      format_params->flag.general = -1;
  } else if (format == '0') {
    if (format_params->flag.null_flag != 1) {
      format_params->flag.null_flag = 1;
      format_params->flag.general = 1;
      res++;
    } else
      format_params->flag.general = -1;
  } else
    format_params->flag.general = 0;
  return res;
}

int sp_get_width_from_format(struct flag_params *format_params, char *format) {
  int res = 0;
  if (*format == '*') {
    format_params->width = '*';
    res = 1;
  } else if (*format > '0' && *format <= '9') {
    format_params->width = make_int_from_str(format, &res);
  } else {
    format_params->width = -1;
  }
  return res;
}

int get_precision_from_format(struct flag_params *format_params, char *format) {
  int res = 0;
  if (*format == '.') {
    format++;
    res++;
    if (*format == '*') {
      format_params->precision = '*';
      res += 1;
    } else if (*format >= '0' && *format <= '9') {
      format_params->precision = make_int_from_str(format, &res);
      res++;
    } else {
      format_params->precision = 0;
    }
  } else {
    format_params->precision = -1;
  }
  return res;
}

int sp_get_length_from_format(struct flag_params *format_params, char format) {
  int res = 0;
  switch (format) {
    case 'h':
    case 'l':
    case 'L':
      format_params->length = format;
      res = 1;
      break;
    default:
      format_params->length = -1;
      break;
  }
  return res;
}

int sp_get_specifier_from_format(struct flag_params *format_params,
                                 char format) {
  switch (format) {
    case 'c':
    case 'd':
    case 'i':
    case 'e':
    case 'E':
    case 'f':
    case 'g':
    case 'G':
    case 'o':
    case 's':
    case 'u':
    case 'x':
    case 'X':
    case 'p':
    case 'n':
    case '%':
      format_params->specifier = format;
      break;

    default:
      format_params->specifier = -1;
      break;
  }
  return 1;
}

int make_int_from_str(char *str, int *index) {
  int res = 0;
  int ten = 0;
  while (*str >= '0' && *str <= '9') {
    ten++;
    str++;
  }
  str -= ten;
  for (int i = ten - 1; i >= 0; i--) {
    res += (int)(*str - '0') * pow(10, i);
    str++;
  }

  *index = ten;
  return res;
}

void make_str_from_num(char *str, long long int num) {
  int ten = 0;
  char buffer[100] = {s21_NULL};

  long long int temp_num = (num < 0) ? -num : num;
  while (temp_num >= 10) {
    ten++;
    temp_num /= 10;
  }
  temp_num = (num < 0) ? -num : num;
  for (int i = ten; i > -1; i--) {
    char c = (temp_num / (long long int)pow(10, i)) + '0';
    add_char_to_string(buffer, c);
    temp_num %= (long long int)pow(10, i);
  }
  s21_strcat(str, buffer);
}

void make_str_from_unsigned_num(char *str, unsigned long long int num) {
  int ten = 0;

  char buffer[100] = {s21_NULL};

  unsigned long long int temp_num = num;
  while (temp_num >= 10) {
    ten++;
    temp_num /= 10;
  }
  temp_num = num;
  for (int i = ten; i > -1; i--) {
    char c = (temp_num / (unsigned long long int)pow(10, i)) + '0';
    add_char_to_string(buffer, c);
    temp_num %= (unsigned long long int)pow(10, i);
  }
  s21_strcat(str, buffer);
}

int make_normal_exp_num(long double *num) {
  int exp_deg = 0;
  long double temp = (*num < 0) ? -(*num) : (*num);
  if (*num != 0.) {
    while (temp >= 10 || temp < 1) {
      if (temp >= 10) {
        *num /= 10;
        exp_deg++;
      } else {
        *num *= 10;
        exp_deg--;
      }
      temp = (*num < 0) ? -(*num) : (*num);
    }
  }
  return exp_deg;
}

void remove_null_from_str(char *str, struct flag_params format_params) {
  if (s21_strchr(str, '.') != s21_NULL) {
    for (int i = s21_strlen(str) - 1; i >= 0; i--) {
      if (str[i] == '0') {
        str[i] = '\0';
      } else
        break;
    }
    if (str[s21_strlen(str) - 1] == '.' && !format_params.flag.ceil_flag) {
      str[s21_strlen(str) - 1] = '\0';
    }
  }
}

void add_exp_to_string(char *str, int exp_deg,
                       struct flag_params format_params) {
  char e_sym =
      (format_params.specifier == 'e' || format_params.specifier == 'g') ? 'e'
                                                                         : 'E';
  char znak_of_e = (exp_deg < 0) ? '-' : '+';
  add_char_to_string(str, e_sym);
  add_char_to_string(str, znak_of_e);
  if (abs(exp_deg) < 10) {
    add_char_to_string(str, '0');
    add_char_to_string(str, abs(exp_deg) + '0');
  } else {
    make_str_from_num(str, abs(exp_deg));
  }
}

void add_sym_to_begin_of_str(char *str, char sym) {
  for (int i = s21_strlen(str) - 1; i >= 0; i--) {
    str[i + 1] = str[i];
  }
  str[0] = sym;
}

void add_char_to_string(char *str, wchar_t sym) {
  char lil_buffer[2] = {'\0'};
  lil_buffer[0] = sym;
  s21_strcat(str, lil_buffer);
}

void make_round(long double *num, int precision) {
  int ten = 0;
  while (*num > 1) {
    *num /= 10;
    ten++;
  }
  double temp = *num;
  temp *= pow(10, precision);
  temp = (temp + 0.5);
  temp /= pow(10, precision);
  *num = temp;

  for (int i = 0; i < ten; i++) *num *= 10;
}