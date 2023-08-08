#ifndef S21_STRING_H
#define S21_STRING_H
#include <math.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#define SIZEBUFF 102400

#include "error.h"

#define S21_NULL (void *)0
typedef long unsigned s21_size_t;
// Вычисление
s21_size_t s21_strlen(const char *str);
s21_size_t s21_strcspn(const char *str, const char *sym);
s21_size_t s21_strspn(const char *str1, const char *str2);

// Сравнение
int s21_memcmp(const void *str1, const void *str2, s21_size_t n);
int s21_strncmp(const char *str1, const char *str2, s21_size_t n);

// Копирование
void *s21_memcpy(void *dest, const void *src, size_t n);
void *s21_memset(void *str, int c, s21_size_t n);
char *s21_strncpy(char *dest, const char *src, s21_size_t n);
char *s21_strcpy(char *dest, const char *src);  //<<<<<<<
// Поиск
void *s21_memchr(const void *arr, int c, s21_size_t n);
char *s21_strchr(const char *str, int c);
char *s21_strpbrk(const char *str1, const char *str2);
char *s21_strrchr(const char *str, int c);
char *s21_strstr(const char *haystack, const char *needle);
char *s21_strerror(int errnum);
// Вспомогательные
char *s21_strncat(char *dest, const char *src, s21_size_t n);
char *s21_strcat(char *dest, const char *src);
char *s21_strtok(char *str, const char *delim);
char *same_sym(const char *str, int c);
// С# functions
void *s21_to_upper(const char *str);
void *s21_to_lower(const char *str);
void *s21_insert(const char *src, const char *str, s21_size_t start_index);
void *s21_trim(const char *src, const char *trim_chars);

struct fl_token {
  int error, c, d, f, s, u, prc, g, G, e, E, x, X, o, p, flPrec, valPrec, h, l,
      L, flMinus, flPlus, flSpace, flSharp, flZero;
  int widht;  // положительное число
  int flArgW, flArgPrec, flSpaceOrSign;
  int SpecInt, SpecFloat;  //общий флаг целых чисел
  char SpaceOrSign[3];
};

int s21_sprintf(char *dest, const char *fmt, ...);
int fooParsing(const char *str, va_list args, struct fl_token *s21_token);
void whatType(char typeSprintf, struct fl_token *s21_token);
int whatFlag(char *flagSprintf, struct fl_token *s21_token);
void whatSize(char flagSize, struct fl_token *s21_token);
void whatWidhtPrec(const char *str, va_list args, struct fl_token *s21_token,
                   int len);
void fooConvertArg(char *argToStr, va_list args, struct fl_token s21_token);
char *fooArgToS(char *ResultStr, va_list args, struct fl_token s21_token,
                double Num);
void fooConvertWithFlPrec(char *buffer, struct fl_token s21_token);
void fooPastBufInResStrWithFL(char *ResultStr, const char *buffer,
                              struct fl_token s21_token);
char *fooArgToDU(char *ResultStr, va_list args, struct fl_token s21_token);
void ReadArgToWidPrec(va_list args, struct fl_token *s21_token);
void fooSpecDWithLenToStr(char *ResultStr, va_list args,
                          struct fl_token *s21_token);
int fooConvertDecToStr(char *ResultStr, long Num);
void fooSpecUWithLenToStr(char *ResultStr, va_list args,
                          struct fl_token *s21_token);
int fooConvertUDecOctHexToStr(char *ResultStr, unsigned long Num, int base);
char *fooArgToC(char *ResultStr, va_list args, struct fl_token s21_token);
char *fooArgToFlow(char *ResultStr, va_list args, struct fl_token s21_token);
void fooSpecFWithLenToStr(char *ResultStr, long double NumFromArgs,
                          struct fl_token *s21_token);
void fooDefaultVal(struct fl_token *s21_token);
void fooPasteSpaceOrZero(char *ResultStr, struct fl_token s21_token);
void fooSpecEeWithLenToStr(char *ResultStr, long double NumFromArgs,
                           struct fl_token *s21_token);
void fooSpecGgWithLenToStr(char *ResultStr, long double NumFromArgs,
                           struct fl_token *s21_token);
void fooSpaceOrSign(long double *Num, struct fl_token *s21_token);
char *fooArgToPoint(char *ResultStr, va_list args, struct fl_token s21_token);

#endif