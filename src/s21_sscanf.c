#include <stdarg.h>

#include "s21_string.h"

struct params {
  int width;
  int snowflake;
  char length;
  char specifier;
  int success;
};

struct variables {
  int i;
  unsigned int u;
  char c;
  double d;
  long double ld;
  float f;
  void *p;
  int n;
};

void omit_space(char **str_ptr, struct variables *var);
int i_specifier(int *num, char **str_ptr, struct params *flag,
                struct variables *var);
int hi_specifier(short int *num, char **str_ptr, struct params *flag,
                 struct variables *var);
int li_specifier(long int *num, char **str_ptr, struct params *flag,
                 struct variables *var);
int o_specifier(unsigned int *num, char **str_ptr, struct params *flag,
                struct variables *var);
int ho_specifier(unsigned short int *num, char **str_ptr, struct params *flag,
                 struct variables *var);
int lo_specifier(unsigned long int *num, char **str_ptr, struct params *flag,
                 struct variables *var);
int x_specifier(unsigned int *num, char **str_ptr, struct params *flag,
                struct variables *var);
int hx_specifier(unsigned short int *num, char **str_ptr, struct params *flag,
                 struct variables *var);
int lx_specifier(unsigned long int *num, char **str_ptr, struct params *flag,
                 struct variables *var);
long int make_int_width(char **str);
long int make_int(char **str, struct params *flag, struct variables *var);
long long int make_int_8(char **str, struct params *flag,
                         struct variables *var);
long long int make_int_16(char **str, struct params *flag,
                          struct variables *var);
int d_specifier(int *num, char **str_ptr, struct params *flag,
                struct variables *var);
int hd_specifier(short int *num, char **str_ptr, struct params *flag,
                 struct variables *var);
int ld_specifier(long int *num, char **str_ptr, struct params *flag,
                 struct variables *var);
int u_specifier(unsigned int *num, char **str_ptr, struct params *flag,
                struct variables *var);
int hu_specifier(unsigned short int *num, char **str_ptr, struct params *flag,
                 struct variables *var);
int lu_specifier(unsigned long int *num, char **str_ptr, struct params *flag,
                 struct variables *var);
int s_specifier(char *str, char **str_ptr, struct params *flag,
                struct variables *var);
int w_s_specifier(wchar_t *str, char **str_ptr, struct params *flag,
                  struct variables *var);
long double make_long_double(char **str, struct params *flag,
                             struct variables *var);
int f_specifier(float *num, char **str_ptr, struct params *flag,
                struct variables *var);
int lf_specifier(double *num, char **str_ptr, struct params *flag,
                 struct variables *var);
int Lf_specifier(long double *num, char **str_ptr, struct params *flag,
                 struct variables *var);
int get_params(struct params *flag, char **format);
int get_width_from_format(struct params *flag, char **format);
int get_specifier_from_format(struct params *flag, char **format);
int get_length_from_format(struct params *flag, char **format);

int s21_sscanf(const char *str, const char *format, ...) {
  int error = 0;
  int suc_var = 0;
  char *format_ptr = (char *)format;
  char *str_ptr = (char *)str;
  va_list params_list;
  va_start(params_list, format);
  struct variables var = {0};
  if (*(str_ptr) == '\0') {
    suc_var = -1;
  } else if (!error) {
    while (*format_ptr) {
      struct params flag = {0};
      if (*format_ptr == '%') {
        format_ptr++;
        if (!error) {
          error = get_params(&flag, &format_ptr);
        }
        if (!error) {
          switch (flag.specifier) {
            case 'c':
              if (flag.snowflake) {
                var.c = *str_ptr++;
              } else {
                if (flag.length == 'l') {
                  *va_arg(params_list, wchar_t *) = *str_ptr++;
                  suc_var++;
                } else {
                  *va_arg(params_list, char *) = *str_ptr++;
                  suc_var++;
                }
              }
              var.n++;
              if (*format_ptr == ' ') {
                omit_space(&str_ptr, &var);
              }
              break;
            case 'd':
              omit_space(&str_ptr, &var);
              if (flag.snowflake) {
                suc_var += d_specifier(&(var.i), &str_ptr, &flag, &var);
              } else {
                if (flag.length == 'h') {
                  suc_var += hd_specifier(va_arg(params_list, short int *),
                                          &str_ptr, &flag, &var);
                } else if (flag.length == 'l') {
                  suc_var += ld_specifier(va_arg(params_list, long int *),
                                          &str_ptr, &flag, &var);
                } else {
                  suc_var += d_specifier(va_arg(params_list, int *), &str_ptr,
                                         &flag, &var);
                }
              }
              break;
            case 'u':
              omit_space(&str_ptr, &var);
              if (flag.snowflake) {
                suc_var += u_specifier(&(var.u), &str_ptr, &flag, &var);
              } else {
                if (flag.length == 'h') {
                  suc_var +=
                      hu_specifier(va_arg(params_list, unsigned short int *),
                                   &str_ptr, &flag, &var);
                } else if (flag.length == 'l') {
                  suc_var +=
                      lu_specifier(va_arg(params_list, unsigned long int *),
                                   &str_ptr, &flag, &var);
                } else {
                  suc_var += u_specifier(va_arg(params_list, unsigned int *),
                                         &str_ptr, &flag, &var);
                }
              }
              break;
            case 'i':
              omit_space(&str_ptr, &var);
              if (flag.snowflake) {
                suc_var += i_specifier(&(var.i), &str_ptr, &flag, &var);
              } else {
                if (flag.length == 'h') {
                  suc_var += hi_specifier(va_arg(params_list, short int *),
                                          &str_ptr, &flag, &var);
                } else if (flag.length == 'l') {
                  suc_var += li_specifier(va_arg(params_list, long int *),
                                          &str_ptr, &flag, &var);
                } else {
                  suc_var += i_specifier(va_arg(params_list, int *), &str_ptr,
                                         &flag, &var);
                }
              }
              break;
            case 'o':
              omit_space(&str_ptr, &var);
              if (flag.snowflake) {
                suc_var += o_specifier(&(var.u), &str_ptr, &flag, &var);
              } else {
                if (flag.length == 'h') {
                  suc_var +=
                      ho_specifier(va_arg(params_list, unsigned short int *),
                                   &str_ptr, &flag, &var);
                } else if (flag.length == 'l') {
                  suc_var +=
                      lo_specifier(va_arg(params_list, unsigned long int *),
                                   &str_ptr, &flag, &var);
                } else {
                  suc_var += o_specifier(va_arg(params_list, unsigned int *),
                                         &str_ptr, &flag, &var);
                }
              }
              break;
            case 'x':
            case 'X':
              omit_space(&str_ptr, &var);
              if (flag.snowflake) {
                suc_var += x_specifier(&(var.u), &str_ptr, &flag, &var);
              } else {
                if (flag.length == 'h') {
                  suc_var +=
                      hx_specifier(va_arg(params_list, unsigned short int *),
                                   &str_ptr, &flag, &var);
                } else if (flag.length == 'l') {
                  suc_var +=
                      lx_specifier(va_arg(params_list, unsigned long int *),
                                   &str_ptr, &flag, &var);
                } else {
                  suc_var += x_specifier(va_arg(params_list, unsigned int *),
                                         &str_ptr, &flag, &var);
                }
              }
              break;
            case 's':
              omit_space(&str_ptr, &var);
              if (flag.snowflake) {
                suc_var += s_specifier(&(var.c), &str_ptr, &flag, &var);
              } else {
                if (flag.length == 'l') {
                  suc_var += w_s_specifier(va_arg(params_list, wchar_t *),
                                           &str_ptr, &flag, &var);
                } else {
                  suc_var += s_specifier(va_arg(params_list, char *), &str_ptr,
                                         &flag, &var);
                }
              }
              break;
            case 'f':
            case 'e':
            case 'E':
            case 'g':
            case 'G':
              omit_space(&str_ptr, &var);
              if (flag.length == 'l') {
                if (flag.snowflake) {
                  suc_var += lf_specifier(&(var.d), &str_ptr, &flag, &var);
                } else {
                  suc_var += lf_specifier(va_arg(params_list, double *),
                                          &str_ptr, &flag, &var);
                }
              } else if (flag.length == 'L') {
                if (flag.snowflake) {
                  suc_var += Lf_specifier(&(var.ld), &str_ptr, &flag, &var);
                } else {
                  suc_var += Lf_specifier(va_arg(params_list, long double *),
                                          &str_ptr, &flag, &var);
                }
              } else {
                if (flag.snowflake) {
                  suc_var += f_specifier(&(var.f), &str_ptr, &flag, &var);
                } else {
                  suc_var += f_specifier(va_arg(params_list, float *), &str_ptr,
                                         &flag, &var);
                }
              }
              break;
            case '%':
              break;
            case 'n':
              *va_arg(params_list, int *) = var.n;
              break;
            default:
              break;
          }
          suc_var += flag.success;
        }
      } else {
        ++format_ptr;
      }
    }
  } else {
    perror("some error");
  }
  va_end(params_list);
  return suc_var;
}

void omit_space(char **str_ptr, struct variables *var) {
  while ((*((*str_ptr)) == ' ') || (*((*str_ptr)) == '\n') ||
         (*((*str_ptr)) == '\t')) {
    ++(*str_ptr);
    var->n++;
  }
}

int i_specifier(int *num, char **str_ptr, struct params *flag,
                struct variables *var) {
  if (*(*str_ptr) == '0') {
    ++(*str_ptr);
    var->n++;
    if ((*(*str_ptr) == 'X') || (*(*str_ptr) == 'x')) {
      ++(*str_ptr);
      var->n++;
      *num = (int)make_int_16(str_ptr, flag, var);
    } else {
      *num = (int)make_int_8(str_ptr, flag, var);
    }
  } else {
    *num = (int)make_int(str_ptr, flag, var);
  }
  return 0;
}

int hi_specifier(short int *num, char **str_ptr, struct params *flag,
                 struct variables *var) {
  if (*(*str_ptr) == '0') {
    ++(*str_ptr);
    var->n++;
    if ((*(*str_ptr) == 'X') || (*(*str_ptr) == 'x')) {
      ++(*str_ptr);
      var->n++;
      *num = (short int)make_int_16(str_ptr, flag, var);
    } else {
      *num = (short int)make_int_8(str_ptr, flag, var);
    }
  } else {
    *num = (short int)make_int(str_ptr, flag, var);
  }
  return 0;
}

int li_specifier(long int *num, char **str_ptr, struct params *flag,
                 struct variables *var) {
  if (*(*str_ptr) == '0') {
    ++(*str_ptr);
    var->n++;
    if ((*(*str_ptr) == 'X') || (*(*str_ptr) == 'x')) {
      ++(*str_ptr);
      var->n++;
      *num = (long int)make_int_16(str_ptr, flag, var);
    } else {
      *num = (long int)make_int_8(str_ptr, flag, var);
    }
  } else {
    *num = (long int)make_int(str_ptr, flag, var);
  }
  return 0;
}

int o_specifier(unsigned int *num, char **str_ptr, struct params *flag,
                struct variables *var) {
  *num = (unsigned int)make_int_8(str_ptr, flag, var);
  return 0;
}

int ho_specifier(unsigned short int *num, char **str_ptr, struct params *flag,
                 struct variables *var) {
  *num = (unsigned short int)make_int_8(str_ptr, flag, var);
  return 0;
}

int lo_specifier(unsigned long int *num, char **str_ptr, struct params *flag,
                 struct variables *var) {
  *num = (unsigned long int)make_int_8(str_ptr, flag, var);
  return 0;
}

int x_specifier(unsigned int *num, char **str_ptr, struct params *flag,
                struct variables *var) {
  if (*(*str_ptr) == '0') {
    ++(*str_ptr);
    flag->success = 1;
    if ((*(*str_ptr) == 'X') || (*(*str_ptr) == 'x')) {
      --(*str_ptr);
      *num = (unsigned int)make_int_16(str_ptr, flag, var);
    }
  } else {
    *num = (unsigned int)make_int_16(str_ptr, flag, var);
  }
  return 0;
}

int hx_specifier(unsigned short int *num, char **str_ptr, struct params *flag,
                 struct variables *var) {
  if (*(*str_ptr) == '0') {
    ++(*str_ptr);
    var->n++;
    flag->success = 1;
    if ((*(*str_ptr) == 'X') || (*(*str_ptr) == 'x')) {
      ++(*str_ptr);
      var->n++;
      *num = (unsigned short int)make_int_16(str_ptr, flag, var);
    }
  } else {
    *num = (unsigned short int)make_int_16(str_ptr, flag, var);
  }
  return 0;
}

int lx_specifier(unsigned long int *num, char **str_ptr, struct params *flag,
                 struct variables *var) {
  if (*(*str_ptr) == '0') {
    ++(*str_ptr);
    var->n++;
    flag->success = 1;
    if ((*(*str_ptr) == 'X') || (*(*str_ptr) == 'x')) {
      ++(*str_ptr);
      var->n++;
      *num = (unsigned long int)make_int_16(str_ptr, flag, var);
    }
  } else {
    *num = (unsigned long int)make_int_16(str_ptr, flag, var);
  }
  return 0;
}

int d_specifier(int *num, char **str_ptr, struct params *flag,
                struct variables *var) {
  *num = (int)make_int(str_ptr, flag, var);
  return 0;
}

int hd_specifier(short int *num, char **str_ptr, struct params *flag,
                 struct variables *var) {
  *num = (short int)make_int(str_ptr, flag, var);
  return 0;
}

int ld_specifier(long int *num, char **str_ptr, struct params *flag,
                 struct variables *var) {
  *num = make_int(str_ptr, flag, var);
  return 0;
}

int u_specifier(unsigned int *num, char **str_ptr, struct params *flag,
                struct variables *var) {
  *num = (unsigned int)make_int(str_ptr, flag, var);
  return 0;
}

int hu_specifier(unsigned short int *num, char **str_ptr, struct params *flag,
                 struct variables *var) {
  *num = (unsigned short int)make_int(str_ptr, flag, var);
  return 0;
}

int lu_specifier(unsigned long int *num, char **str_ptr, struct params *flag,
                 struct variables *var) {
  *num = (unsigned long int)make_int(str_ptr, flag, var);
  return 0;
}

long int make_int_width(char **str) {
  long int res = 0;
  while (*(*str) <= '9' && *(*str) >= '0') {
    res *= 10;
    res += *(*str) - '0';
    ++(*str);
  }
  return res;
}

long int make_int(char **str, struct params *flag, struct variables *var) {
  long int res = 0;
  int sign = 0;
  if (*(*str) == '-') {
    ++(*str);
    var->n++;
    sign = -1;
  } else {
    sign = 1;
  }
  if (*(*str) == '\0') {
    flag->success = -1;
  }
  while (*(*str) <= '9' && *(*str) >= '0' && flag->width--) {
    if (!flag->success && !flag->snowflake) {
      flag->success = 1;
    }
    res *= 10;
    res += *(*str) - '0';
    ++(*str);
    var->n++;
  }
  return res * sign;
}

long long int make_int_8(char **str, struct params *flag,
                         struct variables *var) {
  long long int res = 0;
  int sign = 0;
  if (*(*str) == '-') {
    ++(*str);
    var->n++;
    sign = -1;
  } else {
    sign = 1;
  }
  if (*(*str) == '\0') {
    flag->success = -1;
  }
  while (*(*str) <= '7' && *(*str) >= '0' && flag->width--) {
    if (!flag->success && !flag->snowflake) {
      flag->success = 1;
    }
    res *= 8;
    res += *(*str) - '0';
    ++(*str);
    var->n++;
  }
  return res * sign;
}
long long int make_int_16(char **str, struct params *flag,
                          struct variables *var) {
  long long int res = 0;
  int tmp = 0;
  int sign = 0;
  if (*(*str) == '-') {
    ++(*str);
    var->n++;
    sign = -1;
  } else {
    sign = 1;
  }
  if (*(*str) == '\0') {
    flag->success = -1;
  } else {
    if (*(*str) == '0') {
      ++(*str);
      var->n++;
      if (!flag->success && !flag->snowflake) {
        flag->success = 1;
      }
      if (*(*str) == 'x' || *(*str) == 'X') {
        ++(*str);
        var->n++;
      }
    }
  }
  while (flag->width--) {
    if ((*(*str) <= '9' && *(*str) >= '0')) {
      tmp = *(*str) - '0';
    } else if ((*(*str) <= 'F' && *(*str) >= 'A')) {
      tmp = *(*str) - 'A' + 10;
    } else if ((*(*str) <= 'f' && *(*str) >= 'a')) {
      tmp = *(*str) - 'a' + 10;
    } else {
      break;
    }
    res *= 16;
    res += tmp;
    ++(*str);
    var->n++;
    if (!flag->success && !flag->snowflake) {
      flag->success = 1;
    }
  }
  return res * sign;
}

int f_specifier(float *num, char **str_ptr, struct params *flag,
                struct variables *var) {
  *num = (float)make_long_double(str_ptr, flag, var);
  return 0;
}
int lf_specifier(double *num, char **str_ptr, struct params *flag,
                 struct variables *var) {
  *num = (double)make_long_double(str_ptr, flag, var);
  return 0;
}
int Lf_specifier(long double *num, char **str_ptr, struct params *flag,
                 struct variables *var) {
  *num = make_long_double(str_ptr, flag, var);
  return 0;
}

long double make_long_double(char **str, struct params *flag,
                             struct variables *var) {
  long double res = 0;
  int cnt = 0;
  long int power = 0;
  int sign = 0;
  if (*(*str) == '\0') {
    flag->success = -1;
  }
  if (*(*str) == '-') {
    sign = -1;
    ++(*str);
  } else {
    sign = 1;
  }
  while ((*(*str) <= '9' && *(*str) >= '0') && flag->width--) {
    if (!flag->success) {
      if (!flag->snowflake) {
        flag->success = 1;
      }
    }
    res *= 10;
    res += *(*str) - '0';
    ++(*str);
    var->n++;
  }
  if (*(*str) == '.' && flag->width--) {
    ++(*str);
    var->n++;
    while ((*(*str) <= '9' && *(*str) >= '0') && flag->width--) {
      res *= 10;
      res += *(*str) - '0';
      ++cnt;
      ++(*str);
      var->n++;
    }
  }
  while (cnt--) {
    res /= 10;
  }

  if ((*(*str) == 'e' || *(*str) == 'E') && flag->width--) {
    ++(*str);
    var->n++;
    power = make_int(str, flag, var);
    if (power >= 0) {
      while (power > 0 && res != 1.0 / 0.0) {
        --power;
        res *= 10;
      }
    } else {
      while (power < 0 && res != 1.0 / 0.0) {
        res /= 10;
        power++;
      }
    }
  }
  return res * sign;
}

int s_specifier(char *str, char **str_ptr, struct params *flag,
                struct variables *var) {
  if (*(*str_ptr) == '\0') {
    flag->success = -1;
  }
  while ((*(*str_ptr) != ' ') && (*(*str_ptr) != '\0') &&
         (*(*str_ptr) != '\n') && (*(*str_ptr) != '\t') && flag->width) {
    if (!flag->success && !flag->snowflake) {
      flag->success = 1;
    }
    *str = *(*str_ptr);
    ++str;
    ++(*str_ptr);
    var->n++;
    --flag->width;
  }
  *str = '\0';
  return 0;
}

int w_s_specifier(wchar_t *str, char **str_ptr, struct params *flag,
                  struct variables *var) {
  while ((*(*str_ptr) != ' ') && (*(*str_ptr) != '\0') &&
         (*(*str_ptr) != '\n') && (*(*str_ptr) != '\t') && flag->width) {
    if (!flag->success && !flag->snowflake) {
      flag->success = 1;
    }
    *str = *(*str_ptr);
    ++str;
    ++(*str_ptr);
    var->n++;
    --flag->width;
  }
  *str = '\0';
  return 0;
}

int get_width_from_format(struct params *flag, char **format) {
  int error = 0;
  if (*(*format) == '-') {
    ++(*format);
    error = 1;
  }
  if (*(*format) == '*') {
    flag->snowflake = 1;
    ++(*format);
  } else if (*(*format) >= '0' && *(*format) <= '9') {
    flag->width = make_int_width(format);
  } else {
    flag->width = 2147483647;
  }
  if (flag->width == 0) {
    flag->width = 2147483647;
  }
  return error;
}

int get_length_from_format(struct params *flag, char **format) {
  int error = 0;
  switch (*(*format)) {
    case 'h':
    case 'l':
    case 'L':
      flag->length = *(*format);
      ++(*format);
      break;
    default:
      flag->length = -1;
      break;
  }
  return error;
}

int get_specifier_from_format(struct params *flag, char **format) {
  int error = 0;
  switch (*(*format)) {
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
      flag->specifier = *(*format);
      ++(*format);
      break;
    default:
      error = 1;
      break;
  }
  return error;
}

int get_params(struct params *flag, char **format) {
  int error = 0;
  if (!get_width_from_format(flag, format)) {
    if (!get_length_from_format(flag, format)) {
      if (!get_specifier_from_format(flag, format)) {
        error = 0;
      } else {
        error = 1;
      }
    } else {
      error = 1;
    }
  } else {
    error = 1;
  }
  return error;
}
