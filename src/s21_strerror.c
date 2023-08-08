#include "error.h"
#include "s21_string.h"
char *s21_strerror(int errnum) {
  static char error[100];

  ERRORS;
  if (errnum >= 0 && errnum < ERRNUM_MAX)
    s21_memcpy(error, error_list[errnum], 100);
  return error;
}