#include "s21_string.h"

// Копирует содержимое массива src в массив dest весом n байтов
void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  char *invite_d = (char *)dest;
  const char *invite_s = (const char *)src;
  for (s21_size_t i = 0; i < n; i++) {
    invite_d[i] = invite_s[i];
  }
  return dest;
}
