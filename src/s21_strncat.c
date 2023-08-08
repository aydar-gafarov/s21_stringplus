#include "s21_string.h"

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  char *answer = dest;  // Сохраняем указатель на начало строки
  s21_size_t i = 0;
  dest = dest + s21_strlen(dest);  // Двигаем указатель на конец строки
  for (; src[i] != '\0' && i < n; i++) {
    dest[i] = src[i];
  }
  dest[i] = '\0';
  return answer;
}