#include "s21_string.h"

void *s21_to_lower(const char *str) {
  if (str == S21_NULL) return S21_NULL;
  s21_size_t length = s21_strlen(str) + 1;
  char *string = calloc(length, sizeof(char *));
  int status = 0;
  if (string == S21_NULL) status = 1;
  for (s21_size_t i = 0, j = 0; i < length && status == 0; i++, j++) {
    if (str[i] >= 65 && str[i] <= 90) {
      string[j] += str[i] + 32;
    } else
      string[j] = str[i];
  }
  string[length] = '\0';
  if (status == 1) string = S21_NULL;
  return string;
}