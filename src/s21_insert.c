#include "s21_string.h"

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  if ((int)start_index < 0) return S21_NULL;
  char *answer = S21_NULL;
  answer = calloc(s21_strlen(str) + s21_strlen(src) + 1, sizeof(char *));
  if (start_index > s21_strlen(src)) answer = S21_NULL;
  s21_size_t i = 0;
  s21_size_t j = 0;
  if (answer != S21_NULL) {
    for (; i < s21_strlen(src) + 1; i++, j++) {
      if (i == start_index) {
        for (; *str != '\0'; str++) {
          answer[j] = *str;
          j++;
        }
      }
      answer[j] = src[i];
    }
  }
  return answer;
}
