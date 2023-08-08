#include "s21_string.h"

// Ищет первое совпадение всей строки needle в haystack
char *s21_strstr(const char *haystack, const char *needle) {
  s21_size_t length_needle = s21_strlen(needle);
  char *answer = S21_NULL;
  if (length_needle == 0) return answer = (char *)haystack;
  s21_size_t i = 0;
  int cnt_needle = 0;
  int check = 0;
  int only_one = 0;
  if (length_needle == 1) only_one = 1;
  for (; haystack[i] != '\0' && check == 0; i++) {
    if (needle[0] == haystack[i]) {
      cnt_needle++;
      if (only_one == 1) check = 1;
      for (s21_size_t j = 1; j < length_needle && check == 0; j++) {
        if (needle[j] == haystack[i + j]) {
          ++cnt_needle;
        }
        if (cnt_needle == (int)length_needle) {
          check = 1;
        }
      }
    }
  }
  if (check == 1) answer = (char *)&haystack[i - 1];
  return answer;
}
