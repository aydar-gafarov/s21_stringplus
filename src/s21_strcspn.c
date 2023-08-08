#include "s21_string.h"

// Считает длину до первого совпадения символа из строки sym в строке str
s21_size_t s21_strcspn(const char *str, const char *sym) {
  s21_size_t length;
  int answer = 0;
  int check = 1;
  for (length = 0; length < s21_strlen(str); length++) {
    for (s21_size_t i = 0; i < s21_strlen(sym); i++) {
      if (str[length] == sym[i] && check == 1) {
        answer = length;
        check = 0;
      }
    }
  }
  if (check == 1) {
    answer = s21_strlen(str);
  }
  return answer;
}
