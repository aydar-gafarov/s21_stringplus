
#include "s21_string.h"
// Считает количество символов в строке
s21_size_t s21_strlen(const char *str) {
  s21_size_t length = 0;  // Обнуляем счётчик
  for (; str[length]; length++)
    ;  // Бежим по массиву символов и прибавляем по одному
  return length;
}
