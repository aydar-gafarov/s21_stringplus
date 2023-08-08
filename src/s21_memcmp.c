#include "s21_string.h"

int s21_memcmp(const void *pt1, const void *pt2, s21_size_t n) {
  const unsigned char *str1 = pt1;
  const unsigned char *str2 = pt2;
  s21_size_t i = 0;
  int answer = 0;
  for (; (str1[i] == str2[i]) && i < n - 1; i++)
    ;
  if (n == 0) {
    answer = 0;
  } else
    answer = str1[i] - str2[i];
  return answer;
}
