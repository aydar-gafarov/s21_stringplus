#include "s21_string.h"

// Заполняет или заменяет первые n байт символов массив str символами с
void *s21_memset(void *str, int c, s21_size_t n) {
  char *string = (char *)str;
  s21_size_t i = 0;
  for (; i < n; i++) {
    string[i] = c;
  }
  return (void *)string;
}