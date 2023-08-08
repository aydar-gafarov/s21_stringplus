#include "s21_string.h"

// Разделение str по delim(разделителям)
char *s21_strtok(char *str, const char *delim) {
  static char *string_return;  // "хранилище" указателя
  int check = 0;
  int flag = 0;
  if (str == S21_NULL) str = string_return;
  for (; same_sym(delim, *str) != S21_NULL; str++)
    ;  // Находим первый отличающий символ
  if (*str == '\0') check = 1;  // если не нашлось, то ставим флажочек
  char *answer = str;  // сохраняем указатель на начало оставшейся строчки
  if (check == 1) answer = S21_NULL;
  for (; flag == 0; str++) {
    if (*str == '\0') {
      string_return = str;
      flag = 1;
    }
    if (same_sym(delim, *str)) {
      *str = '\0';
      string_return = str + 1;
      flag = 1;
    }
  }
  return answer;
}
char *same_sym(const char *str, int c) {
  int status = 0;
  char *answer = S21_NULL;
  for (; *str != '\0'; str++) {
    if ((*str == c)) {
      status = 1;
      break;
    }
  }
  if (status == 1) answer = (char *)str;
  return answer;
}
