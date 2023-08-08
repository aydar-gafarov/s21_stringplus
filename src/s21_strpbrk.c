#include "s21_string.h"

// Ищет первый совпадающийся символ в двух строках, затем печатает всю
char *s21_strpbrk(const char *str1, const char *str2) {
  char *answer = S21_NULL;
  int check = 0;
  for (const char *r = str1; *r != '\0'; r++) {
    for (const char *p = str2; *p != '\0' && check == 0; p++) {
      if (*p == *r) {
        check = 1;
        answer = (char *)r;
      }
    }
  }
  return answer;
}
