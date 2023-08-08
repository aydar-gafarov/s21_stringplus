// #include <string.h>

#include "s21_string.h"

// int main() {
//   const char *str_test = "12334567788999";
//   int c = '\0';
//   printf("not my - %s\n", strrchr(str_test, c));
//   printf("my - %s\n", s21_strrchr(str_test, c));
// }
// Ищет символ С в строке str и начиная с последнего совпадающего печатает
// строку
char *s21_strrchr(const char *str, int c) {
  char *answer = S21_NULL;
  for (; *str != '\0'; str++) {
    if ((*str == c)) {
      answer = (char *)str;
    }
  }
  if (c == '\0') {
    answer = "";
  }
  return answer;
}
