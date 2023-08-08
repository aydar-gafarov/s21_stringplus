#include "s21_string.h"

s21_size_t s21_strspn(const char *str1, const char *str2) {
  s21_size_t answer = 0;
  s21_size_t length_str1 = s21_strlen(str1);
  s21_size_t length_str2 = s21_strlen(str2);
  int check = 0;
  int status = 0;
  int flag = 0;
  for (s21_size_t i = 0; i < length_str2 && check == 0; i++) {
    if (str2[i] == str1[0]) {
      answer++;
      check = 1;
    }
  }
  if (answer == 0) flag = 1;
  for (s21_size_t j = 1; j < length_str1 && status == 0 && flag == 0; j++) {
    status = 1;
    for (s21_size_t m = 0; m < length_str2; m++) {
      if (str1[j] == str2[m]) {
        answer++;
        status = 0;
      }
    }
  }
  return answer;
}