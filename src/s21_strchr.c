#include "s21_string.h"

// Ищет символ С в строке str и начиная с первого совпадающего печатает строку

char *s21_strchr(const char *str, int c) {
  int status = 0;
  char *answer = S21_NULL;
  s21_size_t i = 0;
  for (; i < s21_strlen(str) + 1; i++) {
    if ((str[i] == (char)c)) {
      status = 1;
      break;
    }
  }
  if (status == 1) answer = (char *)&str[i];
  return answer;
}