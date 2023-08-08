#include "s21_string.h"

// Ищет разнцицу в первых различающихся символах в двух строках
int s21_strncmp(const char* str1, const char* str2, s21_size_t n) {
  s21_size_t i = 0;
  int answer = 0;
  if ((int)n <= 0) {
    return answer;
  }
  for (i = 0; (str1[i] == str2[i]) && i < n - 1; i++)
    ;
  if (n == 0) {
    answer = 0;
  } else
    answer = str1[i] - str2[i];
  return answer;
}