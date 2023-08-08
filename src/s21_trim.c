#include "s21_string.h"

void *s21_trim(const char *src, const char *trim_chars) {
  char *answer = S21_NULL;
  if (trim_chars == S21_NULL || src == S21_NULL)
    ;
  else {
    s21_size_t length = s21_strlen(src) + 1;
    answer = calloc(length, sizeof(char *));
    int check = 0;
    s21_size_t cnt = 0;
    if (answer != S21_NULL) {
      s21_size_t i = 0;
      s21_size_t m = 0;
      for (; i < length - 1 && s21_strchr(trim_chars, src[i]) != S21_NULL;
           i++) {
        if (src[i] == trim_chars[i]) {
          cnt++;
        }
      }
      if (cnt == length) check = 1;
      if (check == 0) {
        for (; m < length; m++, i++) {
          answer[m] = src[i];
        }
        m = length;
        for (; m != 0 && s21_strchr(trim_chars, answer[m]) != S21_NULL; m--) {
          answer[m] = '\0';
        }
      }
    }
  }
  return answer;
}