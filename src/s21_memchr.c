// #include <string.h>

#include "s21_string.h"

// int main() {
// char *str = "f3vdyvvsvdsyyyyyvdsdsfewyw3vm";
// char *answ = s21_memchr(str, 'y', 100);
// printf("not my - %p\n", memchr(str, 'y', 100));
// printf("my - %s\n", answ);
// }
// Ищет символ С в строке arr до n байт
void *s21_memchr(const void *arr, int c, s21_size_t n) {
  const unsigned char *str = (unsigned char *)arr;
  void *answer = S21_NULL;
  int check = 0;
  for (s21_size_t i = 0; i < n; i++) {
    if ((str[i] == c) && check == 0) {
      answer = (void *)&str[i];
      check = 1;
    }
  }
  return answer;
}
