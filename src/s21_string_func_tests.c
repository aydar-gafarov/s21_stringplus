#include "s21_string_test.h"

int main() {
  Suite* example_suite;
  int failed = 0;
  SRunner* SRunner_suite;

  example_suite = lib_suite();
  SRunner_suite = srunner_create(example_suite);
  srunner_run_all(SRunner_suite, CK_NORMAL);
  failed = srunner_ntests_failed(SRunner_suite);
  srunner_free(SRunner_suite);
  // return (failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
  return 0;
}

START_TEST(memchr_1) {
  int v1 = 5;
  const int* str_test = &v1;
  char c = ' ';
  s21_size_t n = 5;
  ck_assert_pstr_eq(s21_memchr(str_test, c, n), memchr(str_test, c, n));
}
END_TEST

START_TEST(memchr_2) {
  int v1 = 5;
  const int* str_test = &v1;
  char c = ' ';
  s21_size_t n = 3;
  ck_assert_pstr_eq(s21_memchr(str_test, c, n), memchr(str_test, c, n));
}
END_TEST

START_TEST(memchr_3) {
  const char* str_test = "KARL!!! WORLD";
  int c = 'u';
  s21_size_t n = 10;
  ck_assert_pstr_eq(s21_memchr(str_test, c, n), memchr(str_test, c, n));
}
END_TEST

START_TEST(memchr_4) {
  const char* str_test = "Good Times,.!";
  int c = 'o';
  s21_size_t n = 10;
  ck_assert_pstr_eq(s21_memchr(str_test, c, n), memchr(str_test, c, n));
}
END_TEST

START_TEST(memchr_5) {
  const char* str_test = "I dont speak English,.!";
  int c = 'e';
  s21_size_t n = 5;
  ck_assert_pstr_eq(s21_memchr(str_test, c, n), memchr(str_test, c, n));
}
END_TEST

START_TEST(memchr_6) {
  const char* str_test = "012345678e";
  int c = '3';
  s21_size_t n = 3;
  ck_assert_pstr_eq(s21_memchr(str_test, c, n), memchr(str_test, c, n));
}
END_TEST

START_TEST(memchr_7) {
  const char* str_test = "012345678e";
  int c = '3';
  s21_size_t n = 10;
  ck_assert_pstr_eq(s21_memchr(str_test, c, n), memchr(str_test, c, n));
}
END_TEST

START_TEST(memchr_8) {
  const char* str_test = "Suka ne mat";
  int c = 'u';
  s21_size_t n = 1;
  ck_assert_pstr_eq(s21_memchr(str_test, c, n), memchr(str_test, c, n));
}
END_TEST

START_TEST(memchr_9) {
  const char* str_test = "Slovo ne vorobey";
  int c = 'o';
  s21_size_t n = 10;
  ck_assert_pstr_eq(s21_memchr(str_test, c, n), memchr(str_test, c, n));
}
END_TEST

START_TEST(memchr_10) {
  const char* str_test = "Nichto ne vorobey";
  int c = 'o';
  s21_size_t n = 10;
  ck_assert_pstr_eq(s21_memchr(str_test, c, n), memchr(str_test, c, n));
}
END_TEST

START_TEST(memchr_11) {
  const char* str_test = "Tolko vorobey vorobey";
  int c = 'o';
  s21_size_t n = 1;
  ck_assert_pstr_eq(s21_memchr(str_test, c, n), memchr(str_test, c, n));
}
END_TEST

START_TEST(memchr_12) {
  const char* str_test = "qwertyuiop[asdfghjkl;zxcvbnm,.]";
  int c = 'o';
  s21_size_t n = 25;
  ck_assert_pstr_eq(s21_memchr(str_test, c, n), memchr(str_test, c, n));
}
END_TEST

START_TEST(memcmp_1) {
  const char* str1 = "1";
  const char* str2 = "-1";
  s21_size_t n = 1;
  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_2) {
  const char* str1 = "adaadadadad";
  const char* str2 = "";
  s21_size_t n = 10;
  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_3) {
  const char* str1 = "adaaWQWQWQWWdadadad";
  const char* str2 = "";
  s21_size_t n = 10;
  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_4) {
  const char* str1 = "Hello";
  const char* str2 = "Hello";
  s21_size_t n = 4;
  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));

  /*#test memcmp_5
    const char *str1 = "H";
    const char *str2 = "";
    s21_size_t n = 0;
  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
  */
}
END_TEST

START_TEST(memcmp_6) {
  const char* str1 = "123456";
  const char* str2 = "";
  s21_size_t n = 5;
  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_7) {
  const char* str1 = "123456";
  const char* str2 = "123456";
  s21_size_t n = 6;
  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_8) {
  const char* str1 = "123456";
  const char* str2 = "123456";
  s21_size_t n = 6;
  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_9) {
  const char* str1 = "Char\0Nechar";
  const char* str2 = "Char\0Nechar";
  s21_size_t n = 8;
  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_10) {
  const char* str1 = "Char\0Nechar";
  const char* str2 = "";
  s21_size_t n = 8;
  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcpy_1) {
  char str_dest[1024] = "Hello";
  const char str_src[] = "olleH";
  s21_size_t n = 0;
  ck_assert_str_eq(s21_memcpy(str_dest, str_src, n),
                   memcpy(str_dest, str_src, n));
}
END_TEST

START_TEST(memcpy_2) {
  char str_dest[1024] = "";
  const char str_src[] = "olleH";
  s21_size_t n = 1;
  ck_assert_str_eq(s21_memcpy(str_dest, str_src, n),
                   memcpy(str_dest, str_src, n));
}
END_TEST

START_TEST(memcpy_3) {
  char str_dest[1024] = "\n\n\n";
  const char str_src[] = "olleH";
  s21_size_t n = 3;
  ck_assert_str_eq(s21_memcpy(str_dest, str_src, n),
                   memcpy(str_dest, str_src, n));
}
END_TEST

START_TEST(memcpy_4) {
  char str_dest[1024] = "\n\n\n Hello\0World";
  const char str_src[] = "ol\0leH";
  s21_size_t n = 3;
  ck_assert_str_eq(s21_memcpy(str_dest, str_src, n),
                   memcpy(str_dest, str_src, n));
}
END_TEST

START_TEST(memcpy_5) {
  char str_dest[1024] = "Akuna\0Matata";
  const char str_src[] = "Kent\0";
  s21_size_t n = 3;
  ck_assert_str_eq(s21_memcpy(str_dest, str_src, n),
                   memcpy(str_dest, str_src, n));
}
END_TEST

START_TEST(memcpy_6) {
  char str_dest[1024] = "\0Akuna\0Matata";
  const char str_src[] = "Kent\0";
  s21_size_t n = 3;
  ck_assert_str_eq(s21_memcpy(str_dest, str_src, n),
                   memcpy(str_dest, str_src, n));
}
END_TEST

START_TEST(memcpy_7) {
  char str_dest[1024] = "\0Akuna\0Matata";
  const char str_src[] = "Kent\0";
  s21_size_t n = 3;
  ck_assert_str_eq(s21_memcpy(str_dest, str_src, n),
                   memcpy(str_dest, str_src, n));
}
END_TEST

START_TEST(memcpy_8) {
  char str_dest[1024] = ":A:A:Akuna\0Matata";
  const char str_src[] = "KentKent\0";
  s21_size_t n = 3;
  ck_assert_str_eq(s21_memcpy(str_dest, str_src, n),
                   memcpy(str_dest, str_src, n));
}
END_TEST

START_TEST(memcpy_9) {
  char str_dest[1024] = "Ak\0un\0a\0Matata";
  const char str_src[] = "Ke\0nt\0";
  s21_size_t n = 3;
  ck_assert_str_eq(s21_memcpy(str_dest, str_src, n),
                   memcpy(str_dest, str_src, n));
}
END_TEST

START_TEST(memset_1) {
  char str_test[1024] = "Hello_word";
  int c = ' ';
  s21_size_t n = 5;
  ck_assert_str_eq(s21_memset(str_test, c, n), memset(str_test, c, n));
}
END_TEST

START_TEST(memset_2) {
  char str_test[1024] = "Hello_word";
  int c = ' ';
  s21_size_t n = 1;
  ck_assert_str_eq(s21_memset(str_test, c, n), memset(str_test, c, n));
}
END_TEST

START_TEST(memset_3) {
  char str_test[1024] = "Hello_word";
  int c = ' ';
  s21_size_t n = 11;
  ck_assert_str_eq(s21_memset(str_test, c, n), memset(str_test, c, n));
}
END_TEST

START_TEST(memset_4) {
  char str_test[1024] = "Hello_word";
  int c = ' ';
  s21_size_t n = 6;
  ck_assert_str_eq(s21_memset(str_test, c, n), memset(str_test, c, n));
}
END_TEST

START_TEST(memset_5) {
  char str_test[1024] = "Hello_word";
  int c = '"';
  s21_size_t n = 2;
  ck_assert_str_eq(s21_memset(str_test, c, n), memset(str_test, c, n));
}
END_TEST

START_TEST(memset_6) {
  char str_test[1024] = "Hello_word";
  int c = '/';
  s21_size_t n = 10;
  ck_assert_str_eq(s21_memset(str_test, c, n), memset(str_test, c, n));
}
END_TEST

START_TEST(memset_7) {
  char str_test[1024] = "Hello_word123456789";
  int c = ' ';
  s21_size_t n = 18;
  ck_assert_str_eq(s21_memset(str_test, c, n), memset(str_test, c, n));
}
END_TEST

START_TEST(memset_8) {
  char str_test[1024] = "Hello_word123456789";
  int c = '1';
  s21_size_t n = 19;
  ck_assert_str_eq(s21_memset(str_test, c, n), memset(str_test, c, n));
}
END_TEST

START_TEST(memset_9) {
  char str_test[1024] = "Hello_word123456789";
  int c = '7';
  s21_size_t n = 19;
  ck_assert_str_eq(s21_memset(str_test, c, n), memset(str_test, c, n));
}
END_TEST

START_TEST(memset_10) {
  char str_test[1024] = "Hello_word123456789";
  int c = 't';
  s21_size_t n = 10;
  ck_assert_str_eq(s21_memset(str_test, c, n), memset(str_test, c, n));
}
END_TEST

START_TEST(strncat_1) {
  char str_dest1[1024] = "Hello_word123456789";
  char str_dest2[1024] = "Hello_word123456789";
  const char src[] = "";
  s21_size_t n = 0;
  ck_assert_str_eq(s21_strncat(str_dest1, src, n), strncat(str_dest2, src, n));
}
END_TEST

START_TEST(strncat_2) {
  char str_dest1[1024] = "Hello_word123456789";
  char str_dest2[1024] = "Hello_word123456789";
  const char src[] = "";
  s21_size_t n = 2;
  ck_assert_str_eq(s21_strncat(str_dest1, src, n), strncat(str_dest2, src, n));
}
END_TEST

START_TEST(strncat_3) {
  char str_dest1[1024] = "Hello_";
  char str_dest2[1024] = "Hello_";
  const char src[] = "HelloWorld!";
  s21_size_t n = 10;
  ck_assert_str_eq(s21_strncat(str_dest1, src, n), strncat(str_dest2, src, n));
}
END_TEST

START_TEST(strncat_4) {
  char str_dest1[1024] = "";
  char str_dest2[1024] = "";
  const char src[] = "LoL";
  s21_size_t n = 3;
  ck_assert_str_eq(s21_strncat(str_dest1, src, n), strncat(str_dest2, src, n));
}
END_TEST

START_TEST(strncat_5) {
  char str_dest1[1024] = "Hello";
  char str_dest2[1024] = "Hello";
  const char src[] = "\0!";
  s21_size_t n = 3;
  ck_assert_str_eq(s21_strncat(str_dest1, src, n), strncat(str_dest2, src, n));
}
END_TEST

START_TEST(strncat_6) {
  char str_dest1[1024] = "Hello";
  char str_dest2[1024] = "Hello";
  const char src[] = "\n!";
  s21_size_t n = 3;
  ck_assert_str_eq(s21_strncat(str_dest1, src, n), strncat(str_dest2, src, n));
}
END_TEST

START_TEST(strncat_7) {
  char str_dest1[1024] = "Hello";
  char str_dest2[1024] = "Hello";
  const char src[] = "ass";
  s21_size_t n = -3;
  ck_assert_str_eq(s21_strncat(str_dest1, src, n), strncat(str_dest2, src, n));
}
END_TEST

START_TEST(strncat_8) {
  char str_dest1[1024] = "Hello";
  char str_dest2[1024] = "Hello";
  const char src[] = "Hello";
  s21_size_t n = 3;
  ck_assert_str_eq(s21_strncat(str_dest1, src, n), strncat(str_dest2, src, n));
}
END_TEST

START_TEST(strncat_9) {
  char str_dest1[1024] = "Hello123";
  char str_dest2[1024] = "Hello123";
  const char src[] = "Hello";
  s21_size_t n = 3;
  ck_assert_str_eq(s21_strncat(str_dest1, src, n), strncat(str_dest2, src, n));
}
END_TEST

START_TEST(strncat_10) {
  char str_dest1[1024] = "Hello999";
  char str_dest2[1024] = "Hello999";
  const char src[] = "Hello";
  s21_size_t n = 5;
  ck_assert_str_eq(s21_strncat(str_dest1, src, n), strncat(str_dest2, src, n));
}
END_TEST

START_TEST(strchr_1) {
  char* str_test = "HelloWorld!";
  int c = ' ';
  ck_assert_pstr_eq(s21_strchr(str_test, c), strchr(str_test, c));
}
END_TEST

START_TEST(strchr_2) {
  char* str_test = "w!";
  int c = 'w';
  ck_assert_pstr_eq(s21_strchr(str_test, c), strchr(str_test, c));
}
END_TEST

START_TEST(strchr_3) {
  char* str_test = "WWW!";
  int c = '\n';
  ck_assert_pstr_eq(s21_strchr(str_test, c), strchr(str_test, c));
}
END_TEST

START_TEST(strchr_4) {
  char* str_test = "WWW!";
  int c = '\0';
  ck_assert_pstr_eq(s21_strchr(str_test, c), strchr(str_test, c));
}
END_TEST

START_TEST(strchr_5) {
  char* str_test = "WWW!";
  int c = ' ';
  ck_assert_pstr_eq(s21_strchr(str_test, c), strchr(str_test, c));
}
END_TEST

START_TEST(strchr_6) {
  char* str_test = "WWW!\0ttttochkaru";
  int c = '\n';
  ck_assert_pstr_eq(s21_strchr(str_test, c), strchr(str_test, c));
}
END_TEST

START_TEST(strchr_7) {
  char* str_test = "WWW!ttttochkaru";
  int c = '\\';
  ck_assert_pstr_eq(s21_strchr(str_test, c), strchr(str_test, c));
}
END_TEST

START_TEST(strchr_8) {
  char str_test[7] = {'p', 'r', 'i', 'v', 'e', 't', '\0'};
  int c = 'n';
  ck_assert_pstr_eq(s21_strchr(str_test, c), strchr(str_test, c));
}
END_TEST

START_TEST(strchr_9) {
  char str_test[7] = {'p', 'r', 'i', 'v', 'e', 't', '\0'};
  int c = '\0';
  ck_assert_pstr_eq(s21_strchr(str_test, c), strchr(str_test, c));
}
END_TEST

START_TEST(strchr_10) {
  char str_test[7] = {'\0', 'r', 'i', 'v', 'e', 't', '\0'};
  int c = '0';
  ck_assert_pstr_eq(s21_strchr(str_test, c), strchr(str_test, c));
}
END_TEST

START_TEST(strncmp_1) {
  const char* str1 = "Hello";
  const char* str2 = "Hello";
  s21_size_t n = 3;
  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp_2) {
  const char* str1 = "Hello";
  const char* str2 = "Hello";
  s21_size_t n = 0;
  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp_3) {
  const char* str1 = "Hello";
  const char* str2 = "i\\Hello";
  s21_size_t n = 3;
  int a, b;
  a = s21_strncmp(str1, str2, n);
  if (a < 0) a = -1;
  b = strncmp(str1, str2, n);
  if (b < 0) b = -1;
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(strncmp_4) {
  const char* str1 = "Hello121232324";
  const char* str2 = "Hello";
  s21_size_t n = 5;
  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp_5) {
  const char* str1 = "Hello";
  const char* str2 = "Hello";
  s21_size_t n = -3;
  int a, b;
  a = s21_strncmp(str1, str2, n);
  if (a < 0) a = -1;
  b = strncmp(str1, str2, n);
  if (b < 0) b = -1;
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(strncpy_1) {
  char dest_1[1024] = "Hello_word !";
  char dest_2[1024] = "Hello_word !";
  const char* src = "Hi! My name";
  s21_size_t n = 3;
  ck_assert_str_eq(s21_strncpy(dest_1, src, n), strncpy(dest_2, src, n));
}
END_TEST

START_TEST(strncpy_2) {
  char dest_1[1024] = "Hello_\0word !";
  char dest_2[1024] = "Hello_\0word !";
  const char* src = "\nHi! My name";
  s21_size_t n = 5;
  ck_assert_str_eq(s21_strncpy(dest_1, src, n), strncpy(dest_2, src, n));
}
END_TEST

START_TEST(strncpy_3) {
  char dest_1[1024] = "Hello_\0word !";
  char dest_2[1024] = "Hello_\0word !";
  const char* src = "=/\\/\\/\\/\\/\\=";
  s21_size_t n = 5;
  ck_assert_str_eq(s21_strncpy(dest_1, src, n), strncpy(dest_2, src, n));
}
END_TEST

START_TEST(strncpy_4) {
  char dest_1[1024] = "Hello_word !";
  char dest_2[1024] = "Hello_word !";
  const char* src = "name";
  s21_size_t n = 5;
  ck_assert_str_eq(s21_strncpy(dest_1, src, n), strncpy(dest_2, src, n));
}
END_TEST

START_TEST(strncpy_5) {
  char dest_1[1024] = "Hello_\0word !";
  char dest_2[1024] = "Hello_\0word !";
  const char* src = "name123456789";
  s21_size_t n = 11;
  ck_assert_str_eq(s21_strncpy(dest_1, src, n), strncpy(dest_2, src, n));
}
END_TEST

START_TEST(strcspn_1) {
  const char* str1 = "";
  const char* str2 = "";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn_2) {
  const char* str1 = "Hello";
  const char* str2 = "";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn_3) {
  const char* str1 = "Hello";
  const char* str2 = "l";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn_4) {
  const char* str1 = "l";
  const char* str2 = "Hello";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn_5) {
  const char* str1 = "12345ABCD";
  const char* str2 = "5AB";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn_6) {
  const char* str1 = "123";
  const char* str2 = "12345ABCD";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn_7) {
  const char* str1 = "123456789, .'\0";
  const char* str2 = " .";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn_8) {
  const char* str1 = "123456789, .'\0ABC";
  const char* str2 = "ABC";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn_9) {
  const char* str1 = "123456789, .'\0ABC";
  const char* str2 = "\0ABC";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn_10) {
  const char* str1 = "123456789, .'\0ABC";
  const char* str2 = "\0";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(strlen_1) {
  char* str_test = "";
  ck_assert_int_eq(strlen(str_test), s21_strlen(str_test));
}
END_TEST

START_TEST(strlen_2) {
  char* str_test = "Hello World";
  ck_assert_int_eq(strlen(str_test), s21_strlen(str_test));
}
END_TEST

START_TEST(strlen_3) {
  char* str_test = "01234554321";
  ck_assert_int_eq(strlen(str_test), s21_strlen(str_test));
}
END_TEST

START_TEST(strlen_4) {
  char* str_test = "zxcvbnm,.asdfghjkl123456\0";
  ck_assert_int_eq(strlen(str_test), s21_strlen(str_test));
}
END_TEST

START_TEST(strlen_5) {
  char* str_test = "AaBbCcDd\0GgEeFf";
  ck_assert_int_eq(strlen(str_test), s21_strlen(str_test));
}
END_TEST

START_TEST(strlen_6) {
  char* str_test = "GFGFGFGFgfjsjdsa(da==333)..//,\n";
  ck_assert_int_eq(strlen(str_test), s21_strlen(str_test));
}
END_TEST

START_TEST(strlen_7) {
  char* str_test = "QWERTY\nASDFG";
  ck_assert_int_eq(strlen(str_test), s21_strlen(str_test));
}
END_TEST

START_TEST(strlen_8) {
  char* str_test = "\n";
  ck_assert_int_eq(strlen(str_test), s21_strlen(str_test));
}
END_TEST

START_TEST(strlen_9) {
  char* str_test = " ";
  ck_assert_int_eq(strlen(str_test), s21_strlen(str_test));
}
END_TEST

START_TEST(strlen_10) {
  char* str_test = " ";
  for (int i = 0; i < (int)strlen(str_test); i++) {
    if (str_test[i] == '\0') str_test[i] = '\n';
  }
  ck_assert_int_eq(strlen(str_test), s21_strlen(str_test));
}
END_TEST

START_TEST(strpbrk_1) {
  const char* str_1 = "AB4fa5";
  const char* str_2 = "123456";
  ck_assert_str_eq(s21_strpbrk(str_1, str_2), strpbrk(str_1, str_2));
}
END_TEST

START_TEST(strpbrk_2) {
  const char* str_1 = "AB4fa5 AB4fa5";
  const char* str_2 = "zxc xzc";
  ck_assert_str_eq(s21_strpbrk(str_1, str_2), strpbrk(str_1, str_2));
}
END_TEST

START_TEST(strpbrk_3) {
  const char* str_1 = "AB4fa5 AB4fa5";
  const char* str_2 = " ";
  ck_assert_str_eq(s21_strpbrk(str_1, str_2), strpbrk(str_1, str_2));
}
END_TEST

START_TEST(strpbrk_4) {
  const char* str_1 = "AB4fa5 AB4fa5";
  const char* str_2 = "\0";
  ck_assert_pstr_eq(s21_strpbrk(str_1, str_2), strpbrk(str_1, str_2));
}
END_TEST

START_TEST(strpbrk_5) {
  const char* str_1 = "AB4fa5 AB4fa5";
  const char* str_2 = "";
  ck_assert_pstr_eq(s21_strpbrk(str_1, str_2), strpbrk(str_1, str_2));
}
END_TEST

START_TEST(strpbrk_6) {
  const char* str_1 = "AB4fa5 AB4fa5";
  const char* str_2 = "\n";
  ck_assert_pstr_eq(s21_strpbrk(str_1, str_2), strpbrk(str_1, str_2));
}
END_TEST

START_TEST(strrchr_1) {
  const char* str_test = "jAB4fa5 jAB4fa5";
  int c = ' ';
  ck_assert_str_eq(s21_strrchr(str_test, c), strrchr(str_test, c));
}
END_TEST

START_TEST(strrchr_2) {
  const char* str_test = "jAB4fa5 jAB4fa5";
  int c = 'j';
  ck_assert_str_eq(s21_strrchr(str_test, c), strrchr(str_test, c));
}
END_TEST

START_TEST(strrchr_3) {
  const char* str_test = "";
  int c = 'j';
  ck_assert_pstr_eq(s21_strrchr(str_test, c), strrchr(str_test, c));
}
END_TEST

START_TEST(strrchr_4) {
  const char* str_test = "12334567788999";
  int c = '7';
  ck_assert_str_eq(s21_strrchr(str_test, c), strrchr(str_test, c));
}
END_TEST

START_TEST(strrchr_5) {
  const char* str_test = "127733456\07788999";
  int c = '7';
  ck_assert_str_eq(s21_strrchr(str_test, c), strrchr(str_test, c));
}
END_TEST

START_TEST(strrchr_6) {
  const char* str_test = "12334567788999";
  int c = '\0';
  ck_assert_str_eq(s21_strrchr(str_test, c), strrchr(str_test, c));
}
END_TEST

START_TEST(strstr_1) {
  const char* str1 = "opjbqaj8knp'qbjk";
  const char* str2 = "8op";
  ck_assert_pstr_eq(s21_strstr(str1, str2), strstr(str1, str2));
}
END_TEST

START_TEST(strstr_2) {
  const char* str1 = "opjbqaj8knp'qbjk";
  const char* str2 = "\0";
  ck_assert_pstr_eq(s21_strstr(str1, str2), strstr(str1, str2));
}
END_TEST

START_TEST(strstr_3) {
  const char* str1 = "adfgrgrhnvad";
  const char* str2 = "rhn";
  ck_assert_pstr_eq(s21_strstr(str1, str2), strstr(str1, str2));
}
END_TEST

START_TEST(strstr_4) {
  const char* str1 = "arhn";
  const char* str2 = "adfgrgrhnvad";
  ck_assert_pstr_eq(s21_strstr(str1, str2), strstr(str1, str2));
}
END_TEST

START_TEST(strstr_5) {
  const char* str1 = "adfgr/. /  /sa /grhnvad";
  const char* str2 = "";
  ck_assert_pstr_eq(s21_strstr(str1, str2), strstr(str1, str2));
}
END_TEST

START_TEST(strtok_1) {
  char str[1024] = "Hello world";
  const char* delim = "world";
  ck_assert_str_eq(s21_strtok(str, delim), strtok(str, delim));
}
END_TEST

START_TEST(strtok_2) {
  char str[1024] = "Hello world";
  const char* delim = " world";
  ck_assert_str_eq(s21_strtok(str, delim), strtok(str, delim));
}
END_TEST

START_TEST(strtok_3) {
  char str[1024] = "Hello world";
  const char* delim = "";
  ck_assert_str_eq(s21_strtok(str, delim), strtok(str, delim));
}
END_TEST

START_TEST(strtok_4) {
  char str[1024] = "Hello world";
  const char* delim = " ld";
  ck_assert_str_eq(s21_strtok(str, delim), strtok(str, delim));
}
END_TEST

START_TEST(strtok_5) {
  char str[1024] = "Hello world";
  const char* delim = "\0";
  ck_assert_str_eq(s21_strtok(str, delim), strtok(str, delim));
}
END_TEST

START_TEST(strtok_6) {
  char str[1024] = "\0Hello world";
  const char* delim = " world3223424";
  ck_assert_pstr_eq(s21_strtok(str, delim), strtok(str, delim));
}
END_TEST

START_TEST(strtok_7) {
  char str[1024] = "2";
  const char* delim = "2";
  ck_assert_pstr_eq(s21_strtok(str, delim), strtok(str, delim));
}
END_TEST

START_TEST(strtok_8) {
  char str[1024] = "Hello world";
  const char* delim = "1";
  ck_assert_str_eq(s21_strtok(str, delim), strtok(str, delim));
}
END_TEST

START_TEST(strtok_9) {
  char str[1024] = "1123";
  const char* delim = "12";
  ck_assert_str_eq(s21_strtok(str, delim), strtok(str, delim));
}
END_TEST

START_TEST(strtok_10) {
  char str[1024] = "\0";
  const char* delim = "\0";
  ck_assert_pstr_eq(s21_strtok(str, delim), strtok(str, delim));
}
END_TEST

START_TEST(to_lower_1) {
  char str[50] = "heLLo_WORLD 12345";
  char* answer = s21_to_lower(str);
  char* wait_answer = "hello_world 12345";
  ck_assert_str_eq(answer, wait_answer);
  if (answer) free(answer);
}
END_TEST

START_TEST(to_lower_2) {
  char str[50] = "Yea, HELlO";
  char* answer = s21_to_lower(str);
  char* wait_answer = "yea, hello";
  ck_assert_pstr_eq(answer, wait_answer);
  if (answer) free(answer);
}
END_TEST

START_TEST(to_lower_3) {
  char str[50] = " \0";
  char* answer = s21_to_lower(str);
  char* wait_answer = " ";
  ck_assert_pstr_eq(answer, wait_answer);
  if (answer) free(answer);
}
END_TEST

START_TEST(to_lower_4) {
  char str[50] = " \n\0";
  char* answer = s21_to_lower(str);
  char* wait_answer = " \n";
  ck_assert_pstr_eq(answer, wait_answer);
  if (answer) free(answer);
}
END_TEST

START_TEST(to_upper_1) {
  char str[50] = "heLLo_WorLD 12345";
  char* answer = s21_to_upper(str);
  char* wait_answer = "HELLO_WORLD 12345";
  ck_assert_pstr_eq(answer, wait_answer);
  if (answer) free(answer);
}
END_TEST

START_TEST(to_upper_2) {
  char str[50] = "Yea, HELlO";
  char* answer = s21_to_upper(str);
  char* wait_answer = "YEA, HELLO";
  ck_assert_pstr_eq(answer, wait_answer);
  if (answer) free(answer);
}
END_TEST

START_TEST(to_upper_3) {
  char str[50] = " \0";
  char* answer = s21_to_upper(str);
  char* wait_answer = " ";
  ck_assert_pstr_eq(answer, wait_answer);
  if (answer) free(answer);
}
END_TEST

START_TEST(to_upper_4) {
  char str[50] = " \n\0";
  char* answer = s21_to_upper(str);
  char* wait_answer = " \n";
  ck_assert_pstr_eq(answer, wait_answer);
  if (answer) free(answer);
}
END_TEST

START_TEST(insert_1) {
  const char str1[] = "Hello";
  const char str2[] = "World";
  s21_size_t start_index = 1;
  char* answer = s21_insert(str1, str2, start_index);
  char* wait_answer = "HWorldello";
  ck_assert_pstr_eq(answer, wait_answer);
  if (answer) free(answer);
}
END_TEST

START_TEST(insert_2) {
  const char str1[] = "Hello";
  const char str2[] = "World";
  s21_size_t start_index = 8;
  char* answer = s21_insert(str1, str2, start_index);
  char* wait_answer = S21_NULL;
  ck_assert_pstr_eq(answer, wait_answer);
  if (answer) free(answer);
}
END_TEST

START_TEST(insert_3) {
  const char str1[] = "Hello";
  const char str2[] = " World";
  s21_size_t start_index = 5;
  char* answer = s21_insert(str1, str2, start_index);
  char* wait_answer = "Hello World";
  ck_assert_pstr_eq(answer, wait_answer);
  if (answer) free(answer);
}
END_TEST

START_TEST(insert_4) {
  const char str1[] = "He\n";
  const char str2[] = "World";
  s21_size_t start_index = 3;
  char* answer = s21_insert(str1, str2, start_index);
  char* wait_answer = "He\nWorld";
  ck_assert_pstr_eq(answer, wait_answer);
  if (answer) free(answer);
}
END_TEST

START_TEST(insert_5) {
  const char str1[] = "He\n";
  const char str2[] = "World";
  s21_size_t start_index = 3;
  char* answer = s21_insert(str1, str2, start_index);
  char* wait_answer = "He\nWorld";
  ck_assert_pstr_eq(answer, wait_answer);
  if (answer) free(answer);
}
END_TEST

START_TEST(insert_6) {
  const char str1[] = "Hello\n\0";
  const char str2[] = "WOR\0";
  s21_size_t start_index = 5;
  char* answer = s21_insert(str1, str2, start_index);
  char* wait_answer = "HelloWOR\n";
  ck_assert_pstr_eq(answer, wait_answer);
  if (answer) free(answer);
}
END_TEST

START_TEST(insert_7) {
  const char str1[] = "\n\0";
  const char str2[] = "\n\0";
  s21_size_t start_index = 1;
  char* answer = s21_insert(str1, str2, start_index);
  char* wait_answer = "\n\n";
  ck_assert_pstr_eq(answer, wait_answer);
  if (answer) free(answer);
}
END_TEST

START_TEST(trim_1) {
  const char* src = "Hello";
  const char* trim_chars = "Hello";
  char* answer = s21_trim(src, trim_chars);
  ck_assert_pstr_eq(answer, "");
  if (answer) free(answer);
}
END_TEST

START_TEST(trim_2) {
  const char* src = "Hello";
  const char* trim_chars = "He";
  char* answer = s21_trim(src, trim_chars);
  ck_assert_pstr_eq(answer, "llo");
  if (answer) free(answer);
}
END_TEST

START_TEST(trim_3) {
  const char* src = "Cucumber";
  const char* trim_chars = "Cuer";
  char* answer = s21_trim(src, trim_chars);
  ck_assert_pstr_eq(answer, "cumb");
  if (answer) free(answer);
}
END_TEST

START_TEST(trim_4) {
  const char* src = "   x\n";
  const char* trim_chars = " ";
  char* answer = s21_trim(src, trim_chars);
  ck_assert_pstr_eq(answer, "x\n");
  if (answer) free(answer);
}
END_TEST

START_TEST(trim_5) {
  const char* src = "   x\n";
  const char* trim_chars = " ";
  char* answer = s21_trim(src, trim_chars);
  ck_assert_pstr_eq(answer, "x\n");
  if (answer) free(answer);
}
END_TEST

START_TEST(trim_6) {
  const char* src = "lowBubblelow";
  const char* trim_chars = "lowB";
  char* answer = s21_trim(src, trim_chars);
  ck_assert_pstr_eq(answer, "ubble");
  if (answer) free(answer);
}
END_TEST
// #tcase strerror

START_TEST(strerror_1) { ck_assert_str_eq(s21_strerror(7), strerror(7)); }
END_TEST
START_TEST(strerror_2) { ck_assert_str_eq(s21_strerror(1), strerror(1)); }
END_TEST
START_TEST(strerror_3) { ck_assert_str_eq(s21_strerror(44), strerror(44)); }
END_TEST
START_TEST(strerror_4) { ck_assert_str_eq(s21_strerror(100), strerror(100)); }
END_TEST

START_TEST(strerror_5) { ck_assert_str_eq(s21_strerror(0), strerror(0)); }
END_TEST

START_TEST(strerror_6) {
  for (int i = -1; i < ERRNUM_MAX; i++) {
    ck_assert_str_eq(s21_strerror(i), strerror(i));
  }
}
END_TEST

Suite* lib_suite() {
  Suite* curr_s;
  curr_s = suite_create("CHECK");

  TCase* tc1_1 = tcase_create("memchr");
  TCase* tc1_2 = tcase_create("memcmp");
  TCase* tc1_3 = tcase_create("memcpy");
  TCase* tc1_4 = tcase_create("memset");
  TCase* tc1_5 = tcase_create("strncat");
  TCase* tc1_6 = tcase_create("strchr");
  TCase* tc1_7 = tcase_create("strncmp");
  TCase* tc1_8 = tcase_create("strncpy");
  TCase* tc1_9 = tcase_create("strcspn");
  TCase* tc1_10 = tcase_create("strlen");
  TCase* tc1_11 = tcase_create("strpbrk");
  TCase* tc1_12 = tcase_create("strrchr");
  TCase* tc1_13 = tcase_create("strstr");
  TCase* tc1_14 = tcase_create("strtok");
  TCase* tc1_15 = tcase_create("to_lower");
  TCase* tc1_16 = tcase_create("to_upper");
  TCase* tc1_17 = tcase_create("insert");
  TCase* tc1_18 = tcase_create("trim");
  TCase* tc1_19 = tcase_create("strerror");

  suite_add_tcase(curr_s, tc1_1);
  tcase_add_test(tc1_1, memchr_1);
  tcase_add_test(tc1_1, memchr_2);
  tcase_add_test(tc1_1, memchr_3);
  tcase_add_test(tc1_1, memchr_4);
  tcase_add_test(tc1_1, memchr_5);
  tcase_add_test(tc1_1, memchr_6);
  tcase_add_test(tc1_1, memchr_7);
  tcase_add_test(tc1_1, memchr_8);
  tcase_add_test(tc1_1, memchr_9);
  tcase_add_test(tc1_1, memchr_10);
  tcase_add_test(tc1_1, memchr_11);
  tcase_add_test(tc1_1, memchr_12);
  suite_add_tcase(curr_s, tc1_2);
  tcase_add_test(tc1_2, memcmp_1);
  tcase_add_test(tc1_2, memcmp_2);
  tcase_add_test(tc1_2, memcmp_3);
  tcase_add_test(tc1_2, memcmp_4);
  tcase_add_test(tc1_2, memcmp_6);
  tcase_add_test(tc1_2, memcmp_7);
  tcase_add_test(tc1_2, memcmp_8);
  tcase_add_test(tc1_2, memcmp_9);
  tcase_add_test(tc1_2, memcmp_10);
  suite_add_tcase(curr_s, tc1_3);
  tcase_add_test(tc1_3, memcpy_1);
  tcase_add_test(tc1_3, memcpy_2);
  tcase_add_test(tc1_3, memcpy_3);
  tcase_add_test(tc1_3, memcpy_4);
  tcase_add_test(tc1_3, memcpy_5);
  tcase_add_test(tc1_3, memcpy_6);
  tcase_add_test(tc1_3, memcpy_7);
  tcase_add_test(tc1_3, memcpy_8);
  tcase_add_test(tc1_3, memcpy_9);
  suite_add_tcase(curr_s, tc1_4);
  tcase_add_test(tc1_4, memset_1);
  tcase_add_test(tc1_4, memset_2);
  tcase_add_test(tc1_4, memset_3);
  tcase_add_test(tc1_4, memset_4);
  tcase_add_test(tc1_4, memset_5);
  tcase_add_test(tc1_4, memset_6);
  tcase_add_test(tc1_4, memset_7);
  tcase_add_test(tc1_4, memset_8);
  tcase_add_test(tc1_4, memset_9);
  tcase_add_test(tc1_4, memset_10);
  suite_add_tcase(curr_s, tc1_5);
  tcase_add_test(tc1_5, strncat_1);
  tcase_add_test(tc1_5, strncat_2);
  tcase_add_test(tc1_5, strncat_3);
  tcase_add_test(tc1_5, strncat_4);
  tcase_add_test(tc1_5, strncat_5);
  tcase_add_test(tc1_5, strncat_6);
  tcase_add_test(tc1_5, strncat_7);
  tcase_add_test(tc1_5, strncat_8);
  tcase_add_test(tc1_5, strncat_9);
  tcase_add_test(tc1_5, strncat_10);
  suite_add_tcase(curr_s, tc1_6);
  tcase_add_test(tc1_6, strchr_1);
  tcase_add_test(tc1_6, strchr_2);
  tcase_add_test(tc1_6, strchr_3);
  tcase_add_test(tc1_6, strchr_4);
  tcase_add_test(tc1_6, strchr_5);
  tcase_add_test(tc1_6, strchr_6);
  tcase_add_test(tc1_6, strchr_7);
  tcase_add_test(tc1_6, strchr_8);
  tcase_add_test(tc1_6, strchr_9);
  tcase_add_test(tc1_6, strchr_10);
  suite_add_tcase(curr_s, tc1_7);
  tcase_add_test(tc1_7, strncmp_1);
  tcase_add_test(tc1_7, strncmp_2);
  tcase_add_test(tc1_7, strncmp_3);
  tcase_add_test(tc1_7, strncmp_4);
  tcase_add_test(tc1_7, strncmp_5);
  suite_add_tcase(curr_s, tc1_8);
  tcase_add_test(tc1_8, strncpy_1);
  tcase_add_test(tc1_8, strncpy_2);
  tcase_add_test(tc1_8, strncpy_3);
  tcase_add_test(tc1_8, strncpy_4);
  tcase_add_test(tc1_8, strncpy_5);
  suite_add_tcase(curr_s, tc1_9);
  tcase_add_test(tc1_9, strcspn_1);
  tcase_add_test(tc1_9, strcspn_2);
  tcase_add_test(tc1_9, strcspn_3);
  tcase_add_test(tc1_9, strcspn_4);
  tcase_add_test(tc1_9, strcspn_5);
  tcase_add_test(tc1_9, strcspn_6);
  tcase_add_test(tc1_9, strcspn_7);
  tcase_add_test(tc1_9, strcspn_8);
  tcase_add_test(tc1_9, strcspn_9);
  tcase_add_test(tc1_9, strcspn_10);
  suite_add_tcase(curr_s, tc1_10);
  tcase_add_test(tc1_10, strlen_1);
  tcase_add_test(tc1_10, strlen_2);
  tcase_add_test(tc1_10, strlen_3);
  tcase_add_test(tc1_10, strlen_4);
  tcase_add_test(tc1_10, strlen_5);
  tcase_add_test(tc1_10, strlen_6);
  tcase_add_test(tc1_10, strlen_7);
  tcase_add_test(tc1_10, strlen_8);
  tcase_add_test(tc1_10, strlen_9);
  tcase_add_test(tc1_10, strlen_10);
  suite_add_tcase(curr_s, tc1_11);
  tcase_add_test(tc1_11, strpbrk_1);
  tcase_add_test(tc1_11, strpbrk_2);
  tcase_add_test(tc1_11, strpbrk_3);
  tcase_add_test(tc1_11, strpbrk_4);
  tcase_add_test(tc1_11, strpbrk_5);
  tcase_add_test(tc1_11, strpbrk_6);
  suite_add_tcase(curr_s, tc1_12);
  tcase_add_test(tc1_12, strrchr_1);
  tcase_add_test(tc1_12, strrchr_2);
  tcase_add_test(tc1_12, strrchr_3);
  tcase_add_test(tc1_12, strrchr_4);
  tcase_add_test(tc1_12, strrchr_5);
  tcase_add_test(tc1_12, strrchr_6);
  suite_add_tcase(curr_s, tc1_13);
  tcase_add_test(tc1_13, strstr_1);
  tcase_add_test(tc1_13, strstr_2);
  tcase_add_test(tc1_13, strstr_3);
  tcase_add_test(tc1_13, strstr_4);
  tcase_add_test(tc1_13, strstr_5);
  suite_add_tcase(curr_s, tc1_14);
  tcase_add_test(tc1_14, strtok_1);
  tcase_add_test(tc1_14, strtok_2);
  tcase_add_test(tc1_14, strtok_3);
  tcase_add_test(tc1_14, strtok_4);
  tcase_add_test(tc1_14, strtok_5);
  tcase_add_test(tc1_14, strtok_6);
  tcase_add_test(tc1_14, strtok_7);
  tcase_add_test(tc1_14, strtok_8);
  tcase_add_test(tc1_14, strtok_9);
  tcase_add_test(tc1_14, strtok_10);
  suite_add_tcase(curr_s, tc1_15);
  tcase_add_test(tc1_15, to_lower_1);
  tcase_add_test(tc1_15, to_lower_2);
  tcase_add_test(tc1_15, to_lower_3);
  tcase_add_test(tc1_15, to_lower_4);
  suite_add_tcase(curr_s, tc1_16);
  tcase_add_test(tc1_16, to_upper_1);
  tcase_add_test(tc1_16, to_upper_2);
  tcase_add_test(tc1_16, to_upper_3);
  tcase_add_test(tc1_16, to_upper_4);
  suite_add_tcase(curr_s, tc1_17);
  tcase_add_test(tc1_17, insert_1);
  tcase_add_test(tc1_17, insert_2);
  tcase_add_test(tc1_17, insert_3);
  tcase_add_test(tc1_17, insert_4);
  tcase_add_test(tc1_17, insert_5);
  tcase_add_test(tc1_17, insert_6);
  tcase_add_test(tc1_17, insert_7);
  suite_add_tcase(curr_s, tc1_18);
  tcase_add_test(tc1_18, trim_1);
  tcase_add_test(tc1_18, trim_2);
  tcase_add_test(tc1_18, trim_3);
  tcase_add_test(tc1_18, trim_4);
  tcase_add_test(tc1_18, trim_5);
  tcase_add_test(tc1_18, trim_6);
  suite_add_tcase(curr_s, tc1_19);
  tcase_add_test(tc1_19, strerror_1);
  tcase_add_test(tc1_19, strerror_2);
  tcase_add_test(tc1_19, strerror_3);
  tcase_add_test(tc1_19, strerror_4);
  tcase_add_test(tc1_19, strerror_5);
  tcase_add_test(tc1_19, strerror_6);

  return curr_s;
}
