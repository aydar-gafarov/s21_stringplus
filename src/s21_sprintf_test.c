#include "s21_string_test.h"

int main() {
  Suite *example_suite;
  int failed = 0;
  SRunner *SRunner_suite;

  example_suite = lib_suite();
  SRunner_suite = srunner_create(example_suite);
  srunner_run_all(SRunner_suite, CK_NORMAL);
  failed = srunner_ntests_failed(SRunner_suite);
  srunner_free(SRunner_suite);
  // return (failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
  return 0;
}

START_TEST(sprintf_1_string) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "Test %s Test";
  char *val = "Why am I here?!";
  ck_assert_int_eq(sprintf(str1, str3, val), s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);

  // Three string parameters
}
END_TEST

START_TEST(sprintf_2_string) {
  char str1[100];
  char str2[100];
  char *str3 = "%s Test %s Test %s";
  char *val = "I'm so tired";
  char *val2 = "Who invented this?";
  char *val3 = "This project gave me hemmoroids";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);

  // Three decimal parameters
}
END_TEST

START_TEST(sprintf_3_string) {
  char str1[100];
  char str2[100];
  char *str3 = "%s Test %s Test %s";
  char *val = "Don't need this test";
  char *val2 = "Just for the kicks";
  char *val3 = "Lol";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);

  // Different sizes WCHAR FOR LATER
}
END_TEST

START_TEST(sprintf_4_string) {
  char str1[100];
  char str2[100];
  char *str3 = "Test %s Test2";
  char *val = "3wtf80";
  sprintf(str1, str3, val);
  s21_sprintf(str2, str3, val);
  // ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
  //                s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);

  // Different width
}
END_TEST

START_TEST(sprintf_5_string) {
  char str1[200];
  char str2[200];
  char *str3 = "%3s Test %5s Test %10s";
  char *val = "WHAT IS THIS";
  char *val2 = "i don't care anymore";
  char *val3 = "PPAP";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);

  // Different precision and width
}
END_TEST

START_TEST(sprintf_6_string) {
  char str1[200];
  char str2[200];
  char *str3 = "%6.5s Test %.23s Test %3.s TEST %.s";
  char *val = "WHAT IS THIS";
  char *val2 = "i don't care anymore, really";
  char *val3 = "PPAP";
  char *val4 = "I don't feel so good";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);

  // Minus flag
}
END_TEST

START_TEST(sprintf_7_string) {
  char str1[200];
  char str2[200];
  char *str3 = "%-10.5s Test %-.8s Test %-7s TEST %-.s";
  char *val = "WHAT IS THIS";
  char *val2 = "i don't care anymore, really";
  char *val3 = "PPAP";
  char *val4 = "I don't feel so good";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);

  // Zeroes
}
END_TEST

START_TEST(sprintf_8_string) {
  char str1[200];
  char str2[200];
  char *str3 = "%0s Test %0.s Test %0.0s TEST %0s GOD %.s";
  char *val = "WHAT IS THIS";
  char *val2 = "i don't care anymore, really";
  char *val3 = "PPAP";
  char *val4 = "I don't feel so good";
  char *val5 = "What is lovin'?!";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);

  // Pluses
}
END_TEST

START_TEST(sprintf_9_string) {
  char str1[200];
  char str2[200];
  char *str3 = "%+s Test %+3.s Test %5.7s TEST %10s";
  char *val = "WHAT IS THIS";
  char *val2 = "i don't care anymore, really";
  char *val3 = "abcd";
  char *val4 = "I don't feel so good";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);

  // Zero vals
}
END_TEST

START_TEST(sprintf_10_string) {
  char str1[200];
  char str2[200];
  char *str3 = "%s Test %3.s Test %5.7s TEST %10s %#s %-s %+s %.s % .s";
  char *val = NULL;
  ck_assert_int_eq(
      sprintf(str1, str3, val, val, val, val, val, val, val, val, val),
      s21_sprintf(str2, str3, val, val, val, val, val, val, val, val, val));
  ck_assert_pstr_eq(str1, str2);

  // Spaces
}
END_TEST

START_TEST(sprintf_11_string) {
  char str1[200];
  char str2[200];
  char *str3 = "% s Test % 3.s Test % 5.7s TEST % 10s GOD %.s";
  char *val = "WHAT IS THIS";
  char *val2 = "i don't care anymore, really";
  char *val3 = "PPAP";
  char *val4 = "I don't feel so good";
  char *val5 = "What is lovin'?!";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);

  // Plus
}
END_TEST

START_TEST(sprintf_12_string) {
  char str1[200];
  char str2[200];
  char *str3 = "%+s Test %+3.s Test %+5.7s TEST %+10s GOD %+.s";
  char *val = "WHAT IS THIS";
  char *val2 = "i don't care anymore, really";
  char *val3 = "PPAP";
  char *val4 = "I don't feel so good";
  char *val5 = "What is lovin'?!";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);

  // Hash
}
END_TEST

START_TEST(sprintf_13_string) {
  char str1[200];
  char str2[200];
  char *str3 = "%#s Test %#3s Test %#5.7s TEST %#.7s Oof %#.s";
  char *val = "WHAT IS THIS";
  char *val2 = "i don't care anymore, really";
  char *val3 = "PPAP";
  char *val4 = "I don't feel so good";
  char *val5 = "What is lovin'?!";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);

  // ZERO flag
}
END_TEST

START_TEST(sprintf_14_string) {
  char str1[200];
  char str2[200];
  char *str3 = "%0s Test %06s Test %05.7s TEST %0.7s Oof %0.s";
  char *val = "WHAT IS THIS";
  char *val2 = "idx";
  char *val3 = "PPAP";
  char *val4 = "I don't";
  char *val5 = "What is lovin'?!";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);

  // Asterisk
}
END_TEST

START_TEST(sprintf_15_string) {
  char str1[200];
  char str2[200];
  char *str3 = "%*s Test %-*s Test %*.*s TEST %.*s";
  char *val = "WHAT IS THIS";
  char *val2 = "i don't care anymore, really";
  char *val3 = "PPAP";
  char *val4 = "I don't feel so good";
  int ast = 2;
  int ast2 = 5;
  int ast3 = 4;
  int ast4 = 10;
  int ast5 = 7;
  ck_assert_int_eq(
      sprintf(str1, str3, ast, val, ast2, val2, ast3, ast4, val3, ast5, val4),
      s21_sprintf(str2, str3, ast, val, ast2, val2, ast3, ast4, val3, ast5,
                  val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_16_string) {
  char str1[100];
  char str2[100];
  char *str3 = "%s %s %s %% %d";
  char *val = "This";
  char *val2 = "\0";
  int val3 = 65;
  char *val4 = "string";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val4, val3),
                   s21_sprintf(str2, str3, val, val2, val4, val3));
  ck_assert_pstr_eq(str1, str2);

  //#test sprintf_17_string
  //  char str1[1024];
  //  char str2[1024];
  //  char *str3 =
  //      "%0.0s %1.0s %2.0s %3.0s %5.0s %6.0s %7.0s %0.3s %0.7s %3.2s %3.7s
  //      %7.3s";
  //  char *val = NULL;
  //  s21_sprintf(str2, str3, val, val, val, val, val, val, val, val, val, val,
  //  val,
  //              val);
  //  sprintf(str1, str3, val, val, val, val, val, val, val, val, val, val, val,
  //          val);
  //  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_curr_s) {
  char str1[100] = {'\0'};
  char str2[100] = {'\0'};
  ck_assert_int_eq((int)s21_sprintf(str1, "Watsp %s", "tomorrow"),
                   (int)sprintf(str2, "Watsp %s", "tomorrow"));
  ck_assert_int_eq((int)s21_sprintf(str1, "Watsp %-s", "tomorrow"),
                   (int)sprintf(str2, "Watsp %-s", "tomorrow"));
  ck_assert_int_eq((int)s21_sprintf(str1, "Watsp %-20s", "tomorrow"),
                   (int)sprintf(str2, "Watsp %-20s", "tomorrow"));
  ck_assert_int_eq((int)s21_sprintf(str1, "Watsp %-20.s", "tomorrow"),
                   (int)sprintf(str2, "Watsp %-20.s", "tomorrow"));
  ck_assert_int_eq((int)s21_sprintf(str1, "Watsp %.5s", "tomorrow"),
                   (int)sprintf(str2, "Watsp %.5s", "tomorrow"));
  ck_assert_int_eq((int)s21_sprintf(str1, "Watsp %-10.20s", "tomorrow"),
                   (int)sprintf(str2, "Watsp %-10.20s", "tomorrow"));
  ck_assert_int_eq((int)s21_sprintf(str1, "Watsp %-.20s", "tomorrow"),
                   (int)sprintf(str2, "Watsp %-.20s", "tomorrow"));
  ck_assert_int_eq((int)s21_sprintf(str1, "Watsp %%s", "tomorrow"),
                   (int)sprintf(str2, "Watsp %%s", "tomorrow"));
  ck_assert_int_eq((int)s21_sprintf(str1, "Watsp %%20s", "tomorrow"),
                   (int)sprintf(str2, "Watsp %%20s", "tomorrow"));
  ck_assert_int_eq(
      (int)s21_sprintf(str1, "Watsp %21.20s and %-2.4s", "tomorrow", "school"),
      (int)sprintf(str2, "Watsp %21.20s and %-2.4s", "tomorrow", "school"));
  ck_assert_int_eq((int)s21_sprintf(str1, "Watsp %21.20s and %-*.*s",
                                    "tomorrow", 2, 3, "school"),
                   (int)sprintf(str2, "Watsp %21.20s and %-*.*s", "tomorrow", 2,
                                3, "school"));
}
END_TEST

START_TEST(sprintf_1_signed) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "Test %d Test";
  int val = -12;
  ck_assert_int_eq(sprintf(str1, str3, val), s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);

  // Three signed parameters
}
END_TEST

START_TEST(sprintf_2_signed) {
  char str1[100];
  char str2[100];
  char *str3 = "%d Test %d Test %d";
  int val = 012;
  int val2 = -017;
  int val3 = 07464;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);

  // Three decimal parameters
}
END_TEST

START_TEST(sprintf_3_signed) {
  char str1[100];
  char str2[100];
  char *str3 = "%d Test %d Test %d";
  int val = 3015;
  int val2 = 712;
  int val3 = 99;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);

  // Different sizes
}
END_TEST

START_TEST(sprintf_4_signed) {
  char str1[100];
  char str2[100];
  char *str3 = "%ld Test %ld Test %hd GOD %hd";
  long int val = 3088675747373646;
  long val2 = 33030030303;
  short int val3 = 22600;
  short val4 = -120;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);

  // Different width
}
END_TEST

START_TEST(sprintf_5_signed) {
  char str1[100];
  char str2[100];
  char *str3 = "%3d Test %5d Test %10d";
  int val = -3015;
  int val2 = -11234;
  int val3 = -99;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);

  // Different precision and width
}
END_TEST

START_TEST(sprintf_6_signed) {
  char str1[200];
  char str2[200];
  char *str3 = "%6.5d Test %.23d Test %3.d TEST %.d %.6d";
  int val = -3015;
  int val2 = -712;
  int val3 = -99;
  int val4 = -38;
  int val5 = -100;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);

  // Minus flag
}
END_TEST

START_TEST(sprintf_7_signed) {
  char str1[200];
  char str2[200];
  char *str3 = "%-10.5d Test %-.8d Test %-7d TEST %-.d";
  int val = -3015;
  int val2 = -712;
  int val3 = -99;
  int val4 = -2939;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);

  // Zeroes
}
END_TEST

START_TEST(sprintf_8_signed) {
  char str1[200];
  char str2[200];
  char *str3 = "%0d Test %0.d Test %0.0d TEST %0d GOD %.d";
  int val = -3015;
  int val2 = -712;
  int val3 = -99;
  int val4 = -2939;
  int val5 = -0123;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);

  // Pluses
}
END_TEST

START_TEST(sprintf_9_signed) {
  char str1[200];
  char str2[200];
  char *str3 = "%+d Test %+3.d Test %+5.7d TEST %+10d";
  int val = -3015;
  int val2 = -712;
  int val3 = -99;
  int val4 = -2939;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);

  // Zero vals
}
END_TEST

START_TEST(sprintf_10_signed) {
  char str1[200];
  char str2[200];
  char *str3 = "%d Test %3.d Test %5.7d TEST %10d %#d %-d %+d %.d % .d";
  int val = 0;
  ck_assert_int_eq(
      sprintf(str1, str3, val, val, val, val, val, val, val, val, val),
      s21_sprintf(str2, str3, val, val, val, val, val, val, val, val, val,
                  val));
  ck_assert_pstr_eq(str1, str2);

  // Spaces
}
END_TEST

START_TEST(sprintf_11_signed) {
  char str1[200];
  char str2[200];
  char *str3 = "% d Test % 3.d Test % 5.7d TEST % 10d GOD %.d";
  int val = -32;
  int val2 = -8899;
  int val3 = -91918;
  int val4 = -32311;
  int val5 = -23;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);

  // Plus
}
END_TEST

START_TEST(sprintf_12_signed) {
  char str1[200];
  char str2[200];
  char *str3 = "%+d Test %+3.d Test %+5.7d TEST %+10d GOD %+.d";
  int val = -32;
  int val2 = -8899;
  int val3 = 91918;
  int val4 = -32311;
  int val5 = 3261;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);

  // Hash
}
END_TEST

START_TEST(sprintf_13_signed) {
  char str1[200];
  char str2[200];
  char *str3 = "%#d Test %#3d Test %#5.7d TEST %#.7d Oof %#.d";
  int val = -32;
  int val2 = 8899;
  int val3 = -91918;
  int val4 = 32311;
  int val5 = -8894;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);

  // ZERO flag
}
END_TEST

START_TEST(sprintf_14_signed) {
  char str1[200];
  char str2[200];
  char *str3 = "%0d Test %06d Test %05.7d TEST %0.7d Oof %0.d";
  int val = -32;
  int val2 = 8899;
  int val3 = -91918;
  int val4 = -32311;
  int val5 = -8894;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);

  // Asterisk
}
END_TEST

START_TEST(sprintf_15_signed) {
  char str1[200];
  char str2[200];
  char *str3 = "%*d Test %-*d Test %*.*d TEST %.*d";
  int val = 32;
  int val2 = 8899;
  int val3 = -919;
  int val4 = 32311;
  int ast = 2;
  int ast2 = 5;
  int ast3 = 4;
  int ast4 = 10;
  int ast5 = 7;
  ck_assert_int_eq(
      sprintf(str1, str3, ast, val, ast2, val2, ast3, ast4, val3, ast5, val4),
      s21_sprintf(str2, str3, ast, val, ast2, val2, ast3, ast4, val3, ast5,
                  val4));
  ck_assert_pstr_eq(str1, str2);

  // Simple extra test
}
END_TEST

START_TEST(sprintf_16_signed) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "%d";
  int val = 12;
  ck_assert_int_eq(sprintf(str1, str3, val), s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_17_signed) {
  char str1[1024] = "";
  char str2[1024] = "";
  int val = -75;
  sprintf(str1, "Hello %d %023d", val, val);  // нет нулей перед числом(бонус)
  s21_sprintf(str2, "Hello %d %023d", val, val);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_18_signed) {
  char str1[300];
  char str2[300];
  char *str3 = "%ld Test %ld Test %hd GOD %hd tt %d tt %d";
  long int val = LONG_MAX;
  long val2 = LONG_MIN;
  short int val3 = SHRT_MAX;
  short val4 = SHRT_MIN;
  int val5 = INT_MAX;
  int val6 = INT_MIN;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5, val6),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5, val6));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_19_signed) {
  char str1[200];
  char str2[200];
  char *str3 = "%- d Test %- 15d sdasda %- 15d sdsad %- d";
  int val = -3231;
  int val2 = -3231;
  int val3 = 3231;
  int val4 = 3231;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_d1) {
  char *str1 = (char *)calloc(100000, sizeof(char));
  char *str2 = (char *)calloc(100000, sizeof(char));
  str1[0] = '\0';
  str2[0] = '\0';

  ck_assert_int_eq(s21_sprintf(str1, "2 + 2 = %010.d ! = %.d", -4, 0),
                   sprintf(str2, "2 + 2 = %010.d ! = %.d", -4, 0));
  ck_assert_int_eq(s21_sprintf(str1, "2 + 2 = %d ! = %+- d", 4, 10),
                   sprintf(str2, "2 + 2 = %d ! = %+- d", 4, 10));
  ck_assert_int_eq(s21_sprintf(str1, "2 + 2 = % -10d ! = %0d", +4, +10),
                   sprintf(str2, "2 + 2 = % -10d ! = %0d", +4, +10));
  ck_assert_int_eq(s21_sprintf(str1, "2 + 2 = % .10d ! = %+-20d", -4, 10),
                   sprintf(str2, "2 + 2 = % .10d ! = %+-20d", -4, 10));
  ck_assert_int_eq(s21_sprintf(str1, "2 + 2 = % 10.d ! = %+-20.20d", 0, -182),
                   sprintf(str2, "2 + 2 = % 10.d ! = %+-20.20d", 0, -182));
  ck_assert_int_eq(s21_sprintf(str1, "2 + 2 = % .d ! = %020d", 12, -182),
                   sprintf(str2, "2 + 2 = % .d ! = %020d", 12, -182));
  ck_assert_int_eq(s21_sprintf(str1, "2 + 2 = %+-02.6d ! = %020.d", 12, -182),
                   sprintf(str2, "2 + 2 = %+-02.6d ! = %020.d", 12, -182));
  ck_assert_int_eq(
      s21_sprintf(str1, "2 + 2 = % 10.hd ! = %-20.20ld", 4, 276892067102856),
      sprintf(str2, "2 + 2 = % 10.hd ! = %-20.20ld", (short)4,
              276892067102856));
  ck_assert_int_eq(
      s21_sprintf(str1, "2 + 2 = % 10.hd ! = %-20.20ld", 010, 0x1275623445),
      sprintf(str2, "2 + 2 = % 10.hd ! = %-20.20ld", (short)010, 0x1275623445));
  ck_assert_int_eq(s21_sprintf(str1, "2 + 2 = %10000d ! = %d", +4, -1),
                   sprintf(str2, "2 + 2 = %10000d ! = %d", +4, -1));
  free(str1);
  free(str2);
}
END_TEST

// One parameter unsigned
START_TEST(sprintf_1_unsigned) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "Test %u Test";
  unsigned int val = 012;
  ck_assert_int_eq(sprintf(str1, str3, val), s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);

  // Three unsigned parameters
}
END_TEST

START_TEST(sprintf_2_unsigned) {
  char str1[100];
  char str2[100];
  char *str3 = "%u Test %u Test %u";
  unsigned int val = 012;
  unsigned int val2 = 017;
  unsigned int val3 = 07464;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);

  // Three decimal parameters
}
END_TEST

START_TEST(sprintf_3_unsigned) {
  char str1[100];
  char str2[100];
  char *str3 = "%u Test %u Test %u";
  unsigned int val = 3015;
  unsigned int val2 = 712;
  unsigned int val3 = 99;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);

  // Different sizes
}
END_TEST

START_TEST(sprintf_4_unsigned) {
  char str1[100];
  char str2[100];
  char *str3 = "%lu Test %lu Test %hu GOD %hu";
  long unsigned int val = 3088675747373646;
  long unsigned val2 = 33030030303;
  unsigned short val3 = 22600;
  unsigned short val4 = 120;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);

  // Different width
}
END_TEST

START_TEST(sprintf_5_unsigned) {
  char str1[100];
  char str2[100];
  char *str3 = "%3u Test %5u Test %10u";
  unsigned int val = 3015;
  unsigned int val2 = 01234;
  unsigned int val3 = 99;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);

  // Different precision and width
}
END_TEST

START_TEST(sprintf_6_unsigned) {
  char str1[200];
  char str2[200];
  char *str3 = "%6.5u Test %.23u Test %3.u TEST %.u";
  unsigned int val = 3015;
  unsigned int val2 = 712;
  unsigned int val3 = 99;
  unsigned int val4 = 38;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);

  // Minus flag
}
END_TEST

START_TEST(sprintf_7_unsigned) {
  char str1[200];
  char str2[200];
  char *str3 = "%-10.5u Test %-.8u Test %-7u TEST %-.u";
  unsigned int val = 3015;
  unsigned int val2 = 712;
  unsigned int val3 = 99;
  unsigned int val4 = 2939;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);

  // Zerues
}
END_TEST

START_TEST(sprintf_8_unsigned) {
  char str1[200];
  char str2[200];
  char *str3 = "%0u Test %0.u Test %0.0u TEST %0u GOD %.u";
  unsigned int val = 3015;
  unsigned int val2 = 712;
  unsigned int val3 = 99;
  unsigned int val4 = 2939;
  unsigned int val5 = 0123;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);

  // Pluses
}
END_TEST

START_TEST(sprintf_9_unsigned) {
  char str1[200];
  char str2[200];
  char *str3 = "%+u Test %+3.u Test %+5.7u TEST %+10u";
  unsigned int val = 3015;
  unsigned int val2 = 712;
  unsigned int val3 = 99;
  unsigned int val4 = 2939;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);

  // Zeru vals
}
END_TEST

START_TEST(sprintf_10_unsigned) {
  char str1[200];
  char str2[200];
  char *str3 = "%u Test %3.u Test %5.7u TEST %10u %#u %-u %+u %.u % .u";
  unsigned int val = 0;
  sprintf(str1, str3, val, val, val, val, val, val, val, val, val);
  s21_sprintf(str2, str3, val, val, val, val, val, val, val, val, val);
  ck_assert_int_eq(
      sprintf(str1, str3, val, val, val, val, val, val, val, val, val),
      s21_sprintf(str2, str3, val, val, val, val, val, val, val, val, val));
  ck_assert_pstr_eq(str1, str2);

  // Spaces
}
END_TEST

START_TEST(sprintf_11_unsigned) {
  char str1[200];
  char str2[200];
  char *str3 = "% u Test % 3.u Test % 5.7u TEST % 10u GOD %.u";
  unsigned int val = 32;
  unsigned int val2 = 8899;
  unsigned int val3 = 91918;
  unsigned int val4 = 32311;
  unsigned int val5 = 23;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);

  // Plus
}
END_TEST

START_TEST(sprintf_12_unsigned) {
  char str1[200];
  char str2[200];
  char *str3 = "%+u Test %+3.u Test %+5.7u TEST %+10u GOD %+.u";
  unsigned int val = 32;
  unsigned int val2 = 8899;
  unsigned int val3 = 91918;
  unsigned int val4 = 32311;
  unsigned int val5 = 3261;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);

  // Hash
}
END_TEST

START_TEST(sprintf_13_unsigned) {
  char str1[200];
  char str2[200];
  char *str3 = "%#u Test %#3u Test %#5.7u TEST %#.7u Ouf %#.u";
  unsigned int val = 32;
  unsigned int val2 = 8899;
  unsigned int val3 = 91918;
  unsigned int val4 = 32311;
  unsigned int val5 = 8894;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);

  // ZERO flag
}
END_TEST

START_TEST(sprintf_14_unsigned) {
  char str1[200];
  char str2[200];
  char *str3 = "%0u Test %06u Test %05.7u TEST %0.7u Ouf %0.u";
  unsigned int val = 32;
  unsigned int val2 = 8899;
  unsigned int val3 = 91918;
  unsigned int val4 = 32311;
  unsigned int val5 = 8894;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);

  // Asterisk
}
END_TEST

START_TEST(sprintf_15_unsigned) {
  char str1[200];
  char str2[200];
  char *str3 = "%*u Test %-*u Test %*.*u TEST %.*u";
  unsigned int val = 32;
  unsigned int val2 = 8899;
  unsigned int val3 = 919;
  unsigned int val4 = 32311;
  unsigned int ast = 2;
  unsigned int ast2 = 5;
  unsigned int ast3 = 4;
  unsigned int ast4 = 10;
  unsigned int ast5 = 7;
  ck_assert_int_eq(
      sprintf(str1, str3, ast, val, ast2, val2, ast3, ast4, val3, ast5, val4),
      s21_sprintf(str2, str3, ast, val, ast2, val2, ast3, ast4, val3, ast5,
                  val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_16_unsigned) {
  char str1[200];
  char str2[200];
  char *str3 = "fdsdsds %lu";
  unsigned long int val = ULONG_MAX;
  ck_assert_int_eq(sprintf(str1, str3, val), s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_17_unsigned) {
  char str1[200];
  char str2[200];
  char *str3 = "%- u Test %- 15u sdasda %- 15u sdsad %- u";
  unsigned int val = -3231;
  unsigned int val2 = -3231;
  unsigned int val3 = 3231;
  unsigned int val4 = 3231;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_u1) {
  char str1[100] = "\0";
  char str2[100] = "\0";

  ck_assert_int_eq(s21_sprintf(str1, "2 + 2 = %010.u ! = %.u", -4, 0),
                   sprintf(str2, "2 + 2 = %010.u ! = %.u", -4, 0));
  ck_assert_int_eq(s21_sprintf(str1, "2 + 2 = %u ! = %u", -4, 10),
                   sprintf(str2, "2 + 2 = %u ! = %u", -4, 10));
  ck_assert_int_eq(s21_sprintf(str1, "2 + 2 = %-u ! = %u", 4, 10),
                   sprintf(str2, "2 + 2 = %-u ! = %u", 4, 10));
  ck_assert_int_eq(s21_sprintf(str1, "2 + 2 = %-2.5u ! = %-5.2u", 4, 10),
                   sprintf(str2, "2 + 2 = %-2.5u ! = %-5.2u", 4, 10));
  ck_assert_int_eq(s21_sprintf(str1, "2 + 2 = %010u ! = %-20u", 4, 10),
                   sprintf(str2, "2 + 2 = %010u ! = %-20u", 4, 10));
  ck_assert_int_eq(s21_sprintf(str1, "2 + 2 = %+10.ud ! = %-20.22u", 4, 10),
                   sprintf(str2, "2 + 2 = %+10.ud ! = %-20.22u", 4, 10));
  ck_assert_int_eq(s21_sprintf(str1, "2 + 2 = %+-011u ! = %+011u", -4, 10),
                   sprintf(str2, "2 + 2 = %+-011u ! = %+011u", -4, 10));
  ck_assert_int_eq(s21_sprintf(str1, "2 + 2 = %+-u ! = %.u", -4, 10),
                   sprintf(str2, "2 + 2 = %+-u ! = %.u", -4, 10));
  ck_assert_int_eq(
      s21_sprintf(str1, "2 - 2 = %10.hu ! = %-20.20lu", 0, 276892067102856),
      sprintf(str2, "2 - 2 = %10.hu ! = %-20.20lu", (unsigned short)0,
              276892067102856));
}
END_TEST

START_TEST(sprintf_test_c1) {
  char str1[100] = "\0";
  char str2[100] = "\0";

  ck_assert_int_eq(s21_sprintf(str1, "Watsp school %c %lc", '2', '&'),
                   sprintf(str2, "Watsp school %c %lc", '2', '&'));
  ck_assert_int_eq(s21_sprintf(str1, "Watsp school %-c %c %%%%", '2', '1'),
                   sprintf(str2, "Watsp school %-c %c %%%%", '2', '1'));
  ck_assert_int_eq(s21_sprintf(str1, "Watsp school %20c %-10lc", '2', 0x61),
                   sprintf(str2, "Watsp school %20c %-10lc", '2', 0x61));
  ck_assert_int_eq(s21_sprintf(str1, "Watsp school %-c %c", '2', '1'),
                   sprintf(str2, "Watsp school %-c %c", '2', '1'));
}
END_TEST

START_TEST(sprintf_test_c2) {
  char *str1 = (char *)calloc(10000000, sizeof(char));
  char *str2 = (char *)calloc(10000000, sizeof(char));
  str1[0] = '\0';
  str2[0] = '\0';
  int r1 = sprintf(str1, "(%100000c%-10c%25c%-30c%25c%*c%2c%*c)", 'a', 'e', 'f',
                   'R', 'Q', 10, 'P', 'L', 20, 'x');
  int r2 = s21_sprintf(str2, "(%100000c%-10c%25c%-30c%25c%*c%2c%*c)", 'a', 'e',
                       'f', 'R', 'Q', 10, 'P', 'L', 20, 'x');
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(r1, r2);
  free(str1);
  free(str2);
}
END_TEST

START_TEST(sprintf_1_c) {
  char str1[100];
  char str2[100];
  char *str3 = "%c Test %c Test %c Test %c Test %c";
  int a = 9;
  int b = 10;
  int c = 17;
  int d = 66;
  int e = 124;
  ck_assert_int_eq(sprintf(str1, str3, a, b, c, d, e),
                   s21_sprintf(str2, str3, a, b, c, d, e));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_2_c) {
  char str1[100];
  char str2[100];
  char *str3 = "%c Test %c Test %c Test %c Test %c";
  int a = -6;
  int b = -10;
  int c = -17;
  int d = -66;
  int e = -124;
  ck_assert_int_eq(sprintf(str1, str3, a, b, c, d, e),
                   s21_sprintf(str2, str3, a, b, c, d, e));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_3_c) {
  char str1[100];
  char str2[100];
  char *str3 = "%c Test %c Test %c Test %c Test %c";
  int a = 60;
  int b = 50;
  int c = 1744;
  int d = 386;
  int e = 257;
  ck_assert_int_eq(sprintf(str1, str3, a, b, c, d, e),
                   s21_sprintf(str2, str3, a, b, c, d, e));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_4_c) {
  char str1[100];
  char str2[100];
  char *str3 = "%c Test %c Test %c Test %c Test %c";
  int a = 60;
  int b = 50;
  int c = 1744;
  int d = 386;
  int e = 257;
  ck_assert_int_eq(sprintf(str1, str3, a, b, c, d, e),
                   s21_sprintf(str2, str3, a, b, c, d, e));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_5_c) {
  char str1[100];
  char str2[100];
  char *str3 = "%c Test %c Test %c Test %c Test %c";
  char a = '0';
  ck_assert_int_eq(sprintf(str1, str3, a, a, a, a, a),
                   s21_sprintf(str2, str3, a, a, a, a, a));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_6_c) {
  char str1[100];
  char str2[100];
  char *str3 = "%05c Test % 5c Test %lc Test";
  int a = 70;
  unsigned long int b = 70;
  ck_assert_int_eq(sprintf(str1, str3, a, a, b),
                   s21_sprintf(str2, str3, a, a, b));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_7_c) {
  char str1[100];
  char str2[100];
  char *str3 = "%-010c Test % -10c Test %-lc";
  int a = 74;
  unsigned long int b = 74;
  ck_assert_int_eq(sprintf(str1, str3, a, a, b),
                   s21_sprintf(str2, str3, a, a, b));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_8_c) {
  char str1[100];
  char str2[100];
  char *str3 = "%+010.5c Test % +10.5c Test %-10lc Test %-10lc Test %+10lc";
  char a = 92;
  unsigned long int b = 92;
  unsigned long int c = 92;
  ck_assert_int_eq(sprintf(str1, str3, a, a, b, c, c),
                   s21_sprintf(str2, str3, a, a, b, c, c));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_9_c) {
  char str1[100];
  char str2[100];
  char *str3 = "%6.4c Test %-6.4c Test %4.10lc Test %-4.10lc Test %-0lc";
  int a = 10;
  unsigned long int b = 10;
  unsigned long int c = 10;
  ck_assert_int_eq(sprintf(str1, str3, a, a, b, c, c),
                   s21_sprintf(str2, str3, a, a, b, c, c));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_10_c) {
  char str1[100];
  char str2[100];
  char *str3 = "%6.4c Test %-6.4c Test %4.10lc Test %-4.10lc Test %-0lc";
  int a = -10;
  unsigned long int b = 10;
  unsigned long int c = 10;
  ck_assert_int_eq(sprintf(str1, str3, a, a, b, c, c),
                   s21_sprintf(str2, str3, a, a, b, c, c));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_11_c) {
  char str1[100];
  char str2[100];
  char *str3 = "%#c Test %#c Test %#c Test %#c Test %#c";
  ck_assert_int_eq(sprintf(str1, str3, ' ', 'n', '5', '%', '\\'),
                   s21_sprintf(str2, str3, ' ', 'n', '5', '%', '\\'));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_12_c) {
  char str1[100];
  char str2[100];
  char *str3 = "%c Test %c Test %c Test %c Test %c";
  ck_assert_int_eq(sprintf(str1, str3, '\n', '0', '\\', '0', 'c'),
                   s21_sprintf(str2, str3, '\n', '0', '\\', '0', 'c'));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_13_c) {
  char str1[100];
  char str2[100];
  char *str3 = "%c Test %c Test %c Test %c Test %c";
  ck_assert_int_eq(sprintf(str1, str3, 'b', '4', '#', '@', '0'),
                   s21_sprintf(str2, str3, 'b', '4', '#', '@', '0'));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_14_c) {
  char str1[100];
  char str2[100];
  char *str3 = "%c Test %c Test %c Test %c Test %c";
  ck_assert_int_eq(sprintf(str1, str3, 'Y', 'G', 123, '0', 'J'),
                   s21_sprintf(str2, str3, 'Y', 'G', 123, '0', 'J'));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_15_c) {
  char str1[400];
  char str2[400];
  char *str3 = "%.7c Test %-7c Test %-50c Test % 54c Test %0188c";
  int a = 112;
  ck_assert_int_eq(sprintf(str1, str3, a, a, a, a, a),
                   s21_sprintf(str2, str3, a, a, a, a, a));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_16_c) {
  char str1[400];
  char str2[400];
  char *str3 = "%.7c Test % -.7c Test %- 050c Test %- 54c Test %-0188c";
  int a = 45;
  ck_assert_int_eq(sprintf(str1, str3, a, a, a, a, a),
                   s21_sprintf(str2, str3, a, a, a, a, a));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_17_c) {
  char str1[400];
  char str2[400];
  char *str3 = "%70c Test %-90c Test %080c Test %-065c Test %- 60c";
  int a = 255;
  ck_assert_int_eq(sprintf(str1, str3, a, a, a, a, a),
                   s21_sprintf(str2, str3, a, a, a, a, a));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_18_c) {
  char str1[400];
  char str2[400];
  char *str3 = "%70c Test %-90c Test %080c Test %-065c Test %- 60c";
  int a = 255;
  ck_assert_int_eq(sprintf(str1, str3, a, a, a, a, a),
                   s21_sprintf(str2, str3, a, a, a, a, a));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_19_c) {
  char str1[100];
  char str2[100];  //%lc Test %llc Test %hc Test %hhc
  char *str3 = "%c Test %lc Test %hc";
  int a = 3;
  unsigned long int b = 103;
  unsigned short e = 255;
  ck_assert_int_eq(sprintf(str1, str3, a, b, e),
                   s21_sprintf(str2, str3, a, b, e));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_1_f) {
  char str1[200];
  char str2[200];
  char *str3 = "%f TEST %.f TEST %4f TEST %4.f TEST %5.10f!";
  double num = 76.756589367;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num, num, num),
                   s21_sprintf(str2, str3, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_2_f) {
  char str1[200];
  char str2[200];
  char *str3 = "%f TEST %.f TEST %3f TEST %4.f TEST %5.10f!";
  double num = -76.756589367;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num, num, num),
                   s21_sprintf(str2, str3, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_3_f) {
  char str1[400];
  char str2[400];
  char *str3 = "%Lf\n%.Lf!";
  long double num_long = -76.756589;
  ck_assert_int_eq(sprintf(str1, str3, num_long, num_long),
                   s21_sprintf(str2, str3, num_long, num_long));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_4_f) {
  char str1[400];
  char str2[400];
  char *str3 = "%20.10f\n%20.15f\n%-20.5f!";
  double num = -76.756589;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_5_f) {
  char str1[400];
  char str2[400];
  char *str3 = "%Lf\n%.Lf\n%+-#Lf\n%+#.Lf\n%-#.Lf!";
  long double num = 76.756589;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num, num, num),
                   s21_sprintf(str2, str3, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_6_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %5f\ntest: %6.1f\ntest: %8.2f!";
  double num = 76.756589;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_7_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %10.5f\ntest: %12.4f!";
  double num = 76.756589;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_8_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %15.1f\ntest: %16.2f\ntest: %18.3f!";
  double num = -7648938790.756589;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_9_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %10.4f\ntest: %25.5f!";
  double num = -7648938790.756589;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_10_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %+15.f\ntest: %+#16.f\ntest: %+#18.0f!";
  double num = 7648938790.756589;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_11_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %+ 18.0f\ntest: %+10.f\ntest: %+25.f!";
  double num = 7648938790.756589;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_12_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %-26.1f\ntest: %-18.0f\ntest: %#-10.f!";
  double num = 7648938790.756589;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_13_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %-#15.f\ntest: %-+25.f!";
  double num = 7648938790.756589;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_14_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %-15.4f!\ntest: %-26.1f!\ntest: %-18.0f!";
  double num = -365289.3462865487;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_15_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %#-10.9f!\ntest: %-+25.15f!";
  double num = -365289.3462865487;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_16_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %15.13f!\ntest: %26.15f!";
  double num = -365289.34628654873789362746834;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_17_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %18.7f!\ntest: %10.15f!\ntest: %25.15f!";
  double num = -365289.34628654873789362746834;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_18_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %15.13f!\ntest: %26.15f!";
  double num = 365289.34628654873789362746834;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_19_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %18.7f!\ntest: %10.15f!";
  double num = 365289.34628654873789362746834;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_20_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %- 23.14f!\ntest: %+ 25.15f!";
  double num = 365289.34628654873789362746834;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_21_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: % 15f!\ntest: % -26f!\ntest: %- 18f!";
  double num = -365789.34;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_22_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %+- 14f!\ntest: %+ 10f!\ntest: % +25f!";
  double num = -365789.34;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_23_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: % 14f!\ntest: % -27f!\ntest: %- 19f!";
  double num = 365789.34;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_24_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %+- 16f!\ntest: %+ 44f!\ntest: % +35f!";
  double num = 365789.34;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_25_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %26Lf!\ntest: %18Lf!\ntest: %60Lf!";
  long double num = -3752765839673496.34;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_26_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %15Lf!test: %100Lf!";
  long double num = -3752765839673496.34;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_27_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %- 26Lf!\ntest: %+- 18Lf!\ntest: %60Lf!";
  long double num = 3752765839673496.34;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_28_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: % +15Lf!test: %100Lf!";
  long double num = 3752765839673496.34;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_30_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %020f!\ntest: %-020f!\ntest: %+025f!";
  double num = 837564.4753366;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_31_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %-+ 025.5f!\ntest: %- 020.4f\ntest: %+ 016.6f!";
  double num = 837564.4753366;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_32_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %015f!\ntest: %-026f!\ntest: %+018f!";
  double num = -947.6785643;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_33_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %+- 010.2f!\ntest: %- 025.7f\ntest: %+- 18.4f!";
  double num = -947.6785643;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_34_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: % 15.1Lf!\ntest: % -26.15Lf!\ntest: %- 30.15Lf!";
  long double num = 278.723786;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_35_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %+ 50.15Lf!\ntest: % +40.15Lf!";
  long double num = 278.723786;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_36_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: % 15.1Lf!\ntest: % -26.13Lf!\ntest: %- 30.8Lf!";
  long double num = -2358.367776967;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_37_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %+ 50.14Lf!\ntest: % +40.14Lf!";
  long double num = -2358.367776967;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_38_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %.1Lf!\ntest: %.2Lf!\ntest: %.3Lf!";
  long double num = -9999.99999;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_39_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %.10Lf!\ntest: %.6Lf!\ntest: %.Lf!";
  long double num = -9999.99999;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_40_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %.1Lf!\ntest: %.2Lf!\ntest: %.3Lf!";
  long double num = 000000000000000.00000000000;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_41_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %.6Lf!\ntest: %.Lf\ntest: %+ 0Lf!!";
  long double num = 000000000000000.00000000000;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_42_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %.1Lf!\ntest: %.2Lf!\ntest: %.3Lf!";
  long double num = -635293201236310753.6495633;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_43_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %+ 0Lf!\ntest: %.6Lf!\ntest: %.15Lf!";
  long double num = -635293201236310753.6495633;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_44_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %.1Lf!\ntest: %.2Lf!\ntest: %.3Lf!";
  long double num = -236310753.6495633;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_45_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %+ 0Lf!\ntest: %.6Lf!\ntest: %.15Lf!";
  long double num = -236310753.6495633;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_46_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %.1Lf!\ntest: %.2Lf!\ntest: %.3Lf!";
  long double num = -9325781235683689988.;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_47_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %+ 0Lf!\ntest: %.6Lf!\ntest: %.15Lf!";
  long double num = -9325781235683689988.;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_48_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %.1Lf!\ntest: %.2Lf!\ntest: %.3Lf!";
  long double num = 3858585858447757573.6495633;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_49_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %+ 0Lf!\ntest: %.6Lf!\ntest: %.15Lf!";
  long double num = 3858585858447757573.6495633;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_50_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %25.5Lf!\ntest: %Lf!\ntest: %-50Lf!";
  long double num = -9325781235683689988.;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_51_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %+ 0Lf!\ntest: %060Lf!\ntest: %.15Lf!";
  long double num = -9325781235683689988.;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_52_f) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %-+.1Lf!\ntest: %- .2Lf!\ntest: %-0.3Lf!";
  long double num = -0.999999;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_54_f) {
  char str1[400];
  char str2[400];
  char *str3 = "fshgkaljck% 10.12f hgsakul";
  double num = 0.235300;
  ck_assert_int_eq(sprintf(str1, str3, num), s21_sprintf(str2, str3, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_f) {
  char str1[100] = "\0";
  char str2[100] = "\0";

  ck_assert_int_eq(s21_sprintf(str1, "2 + 2 = %f ! = % .f", -4.21, +42.21),
                   sprintf(str2, "2 + 2 = %f ! = % .f", -4.21, +42.21));
  ck_assert_int_eq(s21_sprintf(str1, "2 + 2 = %#.f ! = %#.f", -0.21, +42.21),
                   sprintf(str2, "2 + 2 = %#.f ! = %#.f", -0.21, +42.21));
  ck_assert_int_eq(s21_sprintf(str1, "2 + 2 = %-10f ! = %010f", -4.21, +42.21),
                   sprintf(str2, "2 + 2 = %-10f ! = %010f", -4.21, +42.21));
  ck_assert_int_eq(
      s21_sprintf(str1, "2 + 2 = %-.10f ! = %+01.1f", -4.21, +423.6521),
      sprintf(str2, "2 + 2 = %-.10f ! = %+01.1f", -4.21, +423.6521));
  ck_assert_int_eq(
      s21_sprintf(str1, "2 + 2 = %0.2f ! = %+ 012f", -4.248, +42.21),
      sprintf(str2, "2 + 2 = %0.2f ! = %+ 012f", -4.248, +42.21));
  ck_assert_int_eq(
      s21_sprintf(str1, "2 + 2 = %-2.10f ! = %+0.12f", -4.21, +42.21),
      sprintf(str2, "2 + 2 = %-2.10f ! = %+0.12f", -4.21, +42.21));
  ck_assert_int_eq(
      s21_sprintf(str1, "2 + 2 = %-.f ! = % +012.2f", (double)0, +42.444521),
      sprintf(str2, "2 + 2 = %-.f ! = % +012.2f", (double)0, +42.444521));
  ck_assert_int_eq(
      s21_sprintf(str1, "2 + 2 = %- 10.f ! = %+12.5f", -4.21, +42.21),
      sprintf(str2, "2 + 2 = %- 10.f ! = %+12.5f", -4.21, +42.21));
  ck_assert_int_eq(
      s21_sprintf(str1, "2 + 2 = %- 10.f ! = %+12.5lf", -4.21, +42.21),
      sprintf(str2, "2 + 2 = %- 10.f ! = %+12.5lf", -4.21, +42.21));
}
END_TEST

// One parameter octal
START_TEST(sprintf_1_octal) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "Test %o Test";
  int val = 012;
  ck_assert_int_eq(sprintf(str1, str3, val), s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);

  // Three octal parameters
}
END_TEST

START_TEST(sprintf_2_octal) {
  char str1[100];
  char str2[100];
  char *str3 = "%o Test %o Test %o";
  int val = 012;
  int val2 = 017;
  int val3 = 07464;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);

  // Three decimal parameters
}
END_TEST

START_TEST(sprintf_3_octal) {
  char str1[100];
  char str2[100];
  char *str3 = "%o Test %o Test %o";
  int val = 3015;
  int val2 = 712;
  int val3 = 99;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);

  // Different sizes
}
END_TEST

START_TEST(sprintf_4_octal) {
  char str1[100];
  char str2[100];
  char *str3 = "%lo Test %lo Test %ho GOD %ho";
  long int val = 3088675747373646;
  unsigned long int val2 = 33030030303;
  unsigned short int val3 = 22600;
  unsigned short val4 = 120;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);

  // Different width
}
END_TEST

START_TEST(sprintf_5_octal) {
  char str1[100];
  char str2[100];
  char *str3 = "%3o Test %5o Test %10o";
  int val = 3015;
  int val2 = 01234;
  int val3 = 99;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);

  // Different precision and width
}
END_TEST

START_TEST(sprintf_6_octal) {
  char str1[200];
  char str2[200];
  char *str3 = "%6.5o Test %.23o Test %3.o TEST %.o";
  int val = 3015;
  int val2 = 712;
  int val3 = 99;
  int val4 = 38;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);

  // Minus flag
}
END_TEST

START_TEST(sprintf_7_octal) {
  char str1[200];
  char str2[200];
  char *str3 = "%-10.5o Test %-.8o Test %-7o TEST %-.o";
  int val = 3015;
  int val2 = 712;
  int val3 = 99;
  int val4 = 2939;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);

  // Zeroes
}
END_TEST

START_TEST(sprintf_8_octal) {
  char str1[200];
  char str2[200];
  char *str3 = "%0o Test %0.o Test %0.0o TEST %0o GOD %.o";
  int val = 3015;
  int val2 = 712;
  int val3 = 99;
  int val4 = 2939;
  int val5 = 0123;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);

  // Pluses
}
END_TEST

START_TEST(sprintf_9_octal) {
  char str1[200];
  char str2[200];
  char *str3 = "%+o Test %+3.o Test %+5.7o TEST %+10o";
  int val = 3015;
  int val2 = 712;
  int val3 = 99;
  int val4 = 2939;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);

  // Zero vals
}
END_TEST

START_TEST(sprintf_10_octal) {
  char str1[200];
  char str2[200];
  char *str3 = "%o Test %3.o Test %5.7o TEST %10o %#o %-o %+o %.o % .o";
  int val = 0;
  ck_assert_int_eq(
      sprintf(str1, str3, val, val, val, val, val, val, val, val, val),
      s21_sprintf(str2, str3, val, val, val, val, val, val, val, val, val));
  ck_assert_pstr_eq(str1, str2);

  // Spaces
}
END_TEST

START_TEST(sprintf_11_octal) {
  char str1[200];
  char str2[200];
  char *str3 = "% o Test % 3.o Test % 5.7o TEST % 10o GOD %.o";
  int val = 32;
  int val2 = 8899;
  int val3 = 91918;
  int val4 = 32311;
  int val5 = 23;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);

  // Plus
}
END_TEST

START_TEST(sprintf_12_octal) {
  char str1[200];
  char str2[200];
  char *str3 = "%+o Test %+3.o Test %+5.7o TEST %+10o GOD %+.o";
  int val = 32;
  int val2 = 8899;
  int val3 = 91918;
  int val4 = 32311;
  int val5 = 3261;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);

  // Hash
}
END_TEST

START_TEST(sprintf_13_octal) {
  char str1[200];
  char str2[200];
  char *str3 = "%#o Test %#3o Test %#5.7o TEST %#.7o Oof %#.o";
  int val = 32;
  int val2 = 8899;
  int val3 = 91918;
  int val4 = 32311;
  int val5 = 8894;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);

  // ZERO flag
}
END_TEST

START_TEST(sprintf_14_octal) {
  char str1[200];
  char str2[200];
  char *str3 = "%0o Test %06o Test %05.7o TEST %0.7o Oof %0.o";
  int val = 32;
  int val2 = 8899;
  int val3 = 91918;
  int val4 = 32311;
  int val5 = 8894;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);

  // Asterisk
}
END_TEST

START_TEST(sprintf_15_octal) {
  char str1[200];
  char str2[200];
  char *str3 = "%*o Test %-*o Test %*.*o TEST %.*o";
  int val = 32;
  int val2 = 8899;
  int val3 = 919;
  int val4 = 32311;
  int ast = 2;
  int ast2 = 5;
  int ast3 = 4;
  int ast4 = 10;
  int ast5 = 7;
  ck_assert_int_eq(
      sprintf(str1, str3, ast, val, ast2, val2, ast3, ast4, val3, ast5, val4),
      s21_sprintf(str2, str3, ast, val, ast2, val2, ast3, ast4, val3, ast5,
                  val4));
  ck_assert_pstr_eq(str1, str2);

  // Simple extra test
}
END_TEST

START_TEST(sprintf_16_octal) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "%o";
  int val = 012;
  ck_assert_int_eq(sprintf(str1, str3, val), s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_17_octal) {
  char str1[200];
  char str2[200];
  char *str3 = "%- o Test %- 15o sdasda %- 15o sdsad %- o";
  int val = -3231;
  int val2 = -3231;
  int val3 = 3231;
  int val4 = 3231;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_18_octal) {
  char str1[200];
  char str2[200];
  char *str3 = "fdsdsds %lo";
  long int val = ULONG_MAX;
  ck_assert_int_eq(sprintf(str1, str3, val), s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_o) {
  char str1[100] = "\0";
  char str2[100] = "\0";

  ck_assert_int_eq(s21_sprintf(str1, "2 + 2 = %010.o ! = %.o", -4, 0),
                   sprintf(str2, "2 + 2 = %010.o ! = %.o", -4, 0));
  ck_assert_int_eq(s21_sprintf(str1, "2 + 2 = %o ! = %o", -4, 10),
                   sprintf(str2, "2 + 2 = %o ! = %o", -4, 10));
  ck_assert_int_eq(s21_sprintf(str1, "2 + 2 = %-o ! = %o", 4, 10),
                   sprintf(str2, "2 + 2 = %-o ! = %o", 4, 10));
  ck_assert_int_eq(s21_sprintf(str1, "2 + 2 = %-2.5o ! = %-5.2o", 4, 10),
                   sprintf(str2, "2 + 2 = %-2.5o ! = %-5.2o", 4, 10));
  ck_assert_int_eq(s21_sprintf(str1, "2 + 2 = %010o ! = %-20o", 4, 10),
                   sprintf(str2, "2 + 2 = %010o ! = %-20o", 4, 10));
  ck_assert_int_eq(s21_sprintf(str1, "2 + 2 = %+10.oud ! = %-20.22o", 4, 10),
                   sprintf(str2, "2 + 2 = %+10.oud ! = %-20.22o", 4, 10));
  ck_assert_int_eq(s21_sprintf(str1, "2 + 2 = %+-011o ! = %+011o", -4, 10),
                   sprintf(str2, "2 + 2 = %+-011o ! = %+011o", -4, 10));
  ck_assert_int_eq(s21_sprintf(str1, "2 + 2 = %+-o ! = %.o", -4, 10),
                   sprintf(str2, "2 + 2 = %+-o ! = %.o", -4, 10));
  ck_assert_int_eq(
      s21_sprintf(str1, "2 - 2 = %10.ho ! = %-20.20lo", 0, 276892067102856),
      sprintf(str2, "2 - 2 = %10.ho ! = %-20.20lo", (unsigned short)0,
              276892067102856));
}
END_TEST

// One parameter hex
START_TEST(sprintf_1_hex) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "Test %x Test";
  int val = 0x32;
  ck_assert_int_eq(sprintf(str1, str3, val), s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);

  // Three hex parameters
}
END_TEST

START_TEST(sprintf_2_hex) {
  char str1[100];
  char str2[100];
  char *str3 = "%x Test %x Test %x";
  int val = 0x7a4;
  int val2 = 0x91ba123f;
  int val3 = 0x3123;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);

  // Three decimal parameters
}
END_TEST

START_TEST(sprintf_3_hex) {
  char str1[100];
  char str2[100];
  char *str3 = "%x Test %x Test %x";
  int val = 0x3015;
  int val2 = 0x712;
  int val3 = 0x99;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);

  // Different sizes
}
END_TEST

START_TEST(sprintf_4_hex) {
  char str1[100];
  char str2[100];
  char *str3 = "%lx Test %lx Test %hx GOD %hx";
  long int val = 3088675747373646;
  long val2 = 33030030303;
  unsigned short int val3 = 22600;
  unsigned short val4 = 120;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);

  // Different width
}
END_TEST

START_TEST(sprintf_5_hex) {
  char str1[100];
  char str2[100];
  char *str3 = "%3x Test %5x Test %10x";
  int val = 3015;
  int val2 = 01234;
  int val3 = 99;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);

  // Different precision and width
}
END_TEST

START_TEST(sprintf_6_hex) {
  char str1[200];
  char str2[200];
  char *str3 = "%6.5x Test %.23x Test %3.x TEST %.x";
  int val = 3015;
  int val2 = 712;
  int val3 = 99;
  int val4 = 38;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);

  // Minus flag
}
END_TEST

START_TEST(sprintf_7_hex) {
  char str1[200];
  char str2[200];
  char *str3 = "%-10.5x Test %-.8x Test %-7x TEST %-.x";
  int val = 3015;
  int val2 = 712;
  int val3 = 99;
  int val4 = 2939;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);

  // Zeroes
}
END_TEST

START_TEST(sprintf_8_hex) {
  char str1[200];
  char str2[200];
  char *str3 = "%0x Test %0.x Test %0.0x TEST %0x GOD %.x";
  int val = 3015;
  int val2 = 712;
  int val3 = 99;
  int val4 = 2939;
  int val5 = 0123;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);

  // Pluses
}
END_TEST

START_TEST(sprintf_9_hex) {
  char str1[200];
  char str2[200];
  char *str3 = "%+x Test %+3.x Test %+5.7x TEST %+10x";
  int val = 3015;
  int val2 = 712;
  int val3 = 99;
  int val4 = 2939;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);

  // Zero vals
}
END_TEST

START_TEST(sprintf_10_hex) {
  char str1[200];
  char str2[200];
  char *str3 = "%x Test %3.x Test %5.7x TEST %10x %#x %-x %+x %.x % .x";
  int val = 0;
  ck_assert_int_eq(
      sprintf(str1, str3, val, val, val, val, val, val, val, val, val),
      s21_sprintf(str2, str3, val, val, val, val, val, val, val, val, val));
  ck_assert_pstr_eq(str1, str2);

  // Spaces
}
END_TEST

START_TEST(sprintf_11_hex) {
  char str1[200];
  char str2[200];
  char *str3 = "% x Test % 3.x Test % 5.7x TEST % 10x GOD %.x";
  int val = 32;
  int val2 = 8899;
  int val3 = 91918;
  int val4 = 32311;
  int val5 = 23;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);

  // Plus
}
END_TEST

START_TEST(sprintf_12_hex) {
  char str1[200];
  char str2[200];
  char *str3 = "%+x Test %+3.x Test %+5.7x TEST %+10x GOD %+.x";
  int val = 32;
  int val2 = 8899;
  int val3 = 91918;
  int val4 = 32311;
  int val5 = 3261;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);

  // Hash
}
END_TEST

START_TEST(sprintf_13_hex) {
  char str1[200];
  char str2[200];
  char *str3 = "%#x Test %#3x Test %#5.7x TEST %#.7x Oof %#.x";
  int val = 32;
  int val2 = 8899;
  int val3 = 91918;
  int val4 = 32311;
  int val5 = 8894;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);

  // ZERO flag
}
END_TEST

START_TEST(sprintf_14_hex) {
  char str1[200];
  char str2[200];
  char *str3 = "%0x Test %06x Test %05.7x TEST %0.7x Oof %0.x";
  int val = 32;
  int val2 = 8899;
  int val3 = 91918;
  int val4 = 32311;
  int val5 = 8894;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);

  // Asterisk
}
END_TEST

START_TEST(sprintf_15_hex) {
  char str1[200];
  char str2[200];
  char *str3 = "%*x Test %-*x Test %*.*x TEST %.*x";
  int val = 32;
  int val2 = 8899;
  int val3 = 919;
  int val4 = 32311;
  int ast = 2;
  int ast2 = 5;
  int ast3 = 4;
  int ast4 = 10;
  int ast5 = 7;
  ck_assert_int_eq(
      sprintf(str1, str3, ast, val, ast2, val2, ast3, ast4, val3, ast5, val4),
      s21_sprintf(str2, str3, ast, val, ast2, val2, ast3, ast4, val3, ast5,
                  val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_16_hex) {
  char str1[200];
  char str2[200];
  char *str3 = "%- x Test %- 15x sdasda %- 15x sdsad %- x";
  int val = -3231;
  int val2 = -3231;
  int val3 = 3231;
  int val4 = 3231;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_17_hex) {
  char str1[200];
  char str2[200];
  char *str3 = "fdsdsds %lx";
  long int val = ULONG_MAX;
  ck_assert_int_eq(sprintf(str1, str3, val), s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_x) {
  char str1[100] = "\0";
  char str2[100] = "\0";

  ck_assert_int_eq(s21_sprintf(str1, "2 + 2 = %X ! = %x", 4, 10),
                   sprintf(str2, "2 + 2 = %X ! = %x", 4, 10));
  ck_assert_int_eq(s21_sprintf(str1, "2 + 2 = %-X ! = %-x", 4, 132445),
                   sprintf(str2, "2 + 2 = %-X ! = %-x", 4, 132445));
  ck_assert_int_eq(s21_sprintf(str1, "2 + 2 = %10X ! = %-20.x", 4, 0),
                   sprintf(str2, "2 + 2 = %10X ! = %-20.x", 4, 0));
  ck_assert_int_eq(s21_sprintf(str1, "2 + 2 = %10.X ! = %04x", 0, 0x124),
                   sprintf(str2, "2 + 2 = %10.X ! = %04x", 0, 0x124));
  ck_assert_int_eq(
      s21_sprintf(str1, "2 + 2 = %10.hX ! = %-20.20lx", 5, 276892067102856),
      sprintf(str2, "2 + 2 = %10.hX ! = %-20.20lx", (unsigned short)5,
              276892067102856));
  ck_assert_int_eq(
      s21_sprintf(str1, "2 + 2 = %10.hX ! = %-20.lx", 21, 276892067102856),
      sprintf(str2, "2 + 2 = %10.hX ! = %-20.lx", (unsigned short)21,
              276892067102856));
}
END_TEST

START_TEST(sprintf_test_x2) {
  char str1[1000] = "\0";
  char str2[1000] = "\0";
  unsigned short h = 345;
  unsigned long l = 52342353242l;
  int r1 = sprintf(str1,
                   "(%x%-25x%#10x%#-10x%#10.5x%-25.34x%#-10.2x%*.*x%#*.10x%20.*"
                   "x%#10.*x%*.5hx%10.25lx)",
                   235, 1234, 3456, 12345, 222234, 68432, 34567, 10, 15, 3452,
                   8, 23452, 10, 34254, 3, 33334, 10, h, l);
  int r2 = s21_sprintf(str2,
                       "(%x%-25x%#10x%#-10x%#10.5x%-25.34x%#-10.2x%*.*x%#*.10x%"
                       "20.*x%#10.*x%*.5hx%10.25lx)",
                       235, 1234, 3456, 12345, 222234, 68432, 34567, 10, 15,
                       3452, 8, 23452, 10, 34254, 3, 33334, 10, h, l);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(r1, r2);
}
END_TEST

// One parameter HEX
START_TEST(sprintf_1_HEX) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "Test %X Test";
  int val = 0X32;
  ck_assert_int_eq(sprintf(str1, str3, val), s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);

  // Three HEX parameters
}
END_TEST

START_TEST(sprintf_2_HEX) {
  char str1[100];
  char str2[100];
  char *str3 = "%X Test %X Test %X";
  int val = 0X7a4;
  int val2 = 0X9112312f;
  int val3 = 0X3123;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);

  // Three decimal parameters
}
END_TEST

START_TEST(sprintf_3_HEX) {
  char str1[100];
  char str2[100];
  char *str3 = "%X Test %X Test %X";
  int val = 0X3015;
  int val2 = 0X712;
  int val3 = 0X99;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);

  // Different sizes
}
END_TEST

START_TEST(sprintf_4_HEX) {
  char str1[100];
  char str2[100];
  char *str3 = "%lX Test %lX Test %hX GOD %hX";
  unsigned long int val = 3088675747373646;
  unsigned long int val2 = 33030030303;
  unsigned short int val3 = 22600;
  unsigned short val4 = 120;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);

  // Different width
}
END_TEST

START_TEST(sprintf_5_HEX) {
  char str1[100];
  char str2[100];
  char *str3 = "%3X Test %5X Test %10X";
  int val = 3015;
  int val2 = 01234;
  int val3 = 99;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);

  // Different precision and width
}
END_TEST

START_TEST(sprintf_6_HEX) {
  char str1[200];
  char str2[200];
  char *str3 = "%6.5X Test %.23X Test %3.X TEST %.X";
  int val = 3015;
  int val2 = 712;
  int val3 = 99;
  int val4 = 38;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);

  // Minus flag
}
END_TEST

START_TEST(sprintf_7_HEX) {
  char str1[200];
  char str2[200];
  char *str3 = "%-10.5X Test %-.8X Test %-7X TEST %-.X";
  int val = 3015;
  int val2 = 712;
  int val3 = 99;
  int val4 = 2939;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);

  // Zeroes
}
END_TEST

START_TEST(sprintf_8_HEX) {
  char str1[200];
  char str2[200];
  char *str3 = "%0X Test %0.X Test %0.0X TEST %0X GOD %.X";
  int val = 3015;
  int val2 = 712;
  int val3 = 99;
  int val4 = 2939;
  int val5 = 0123;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);

  // Pluses
}
END_TEST

START_TEST(sprintf_9_HEX) {
  char str1[200];
  char str2[200];
  char *str3 = "%+X Test %+3.X Test %+5.7X TEST %+10X";
  int val = 3015;
  int val2 = 712;
  int val3 = 99;
  int val4 = 2939;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);

  // Zero vals
}
END_TEST

START_TEST(sprintf_10_HEX) {
  char str1[200];
  char str2[200];
  char *str3 = "%X Test %3.X Test %5.7X TEST %10X %#X %-X %+X %.X % .X";
  int val = 0;
  ck_assert_int_eq(
      sprintf(str1, str3, val, val, val, val, val, val, val, val, val),
      s21_sprintf(str2, str3, val, val, val, val, val, val, val, val, val));
  ck_assert_pstr_eq(str1, str2);

  // Spaces
}
END_TEST

START_TEST(sprintf_11_HEX) {
  char str1[200];
  char str2[200];
  char *str3 = "% X Test % 3.X Test % 5.7X TEST % 10X GOD %.X";
  int val = 32;
  int val2 = 8899;
  int val3 = 91918;
  int val4 = 32311;
  int val5 = 23;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);

  // Plus
}
END_TEST

START_TEST(sprintf_12_HEX) {
  char str1[200];
  char str2[200];
  char *str3 = "%+X Test %+3.X Test %+5.7X TEST %+10X GOD %+.X";
  int val = 32;
  int val2 = 8899;
  int val3 = 91918;
  int val4 = 32311;
  int val5 = 3261;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);

  // Hash
}
END_TEST

START_TEST(sprintf_13_HEX) {
  char str1[200];
  char str2[200];
  char *str3 = "%#X Test %#3X Test %#5.7X TEST %#.7X Oof %#.X";
  int val = 32;
  int val2 = 8899;
  int val3 = 91918;
  int val4 = 32311;
  int val5 = 8894;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);

  // ZERO flag
}
END_TEST

START_TEST(sprintf_14_HEX) {
  char str1[200];
  char str2[200];
  char *str3 = "%0X Test %06X Test %05.7X TEST %0.7X Oof %0.X";
  int val = 32;
  int val2 = 8899;
  int val3 = 91918;
  int val4 = 32311;
  int val5 = 8894;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);

  // Asterisk
}
END_TEST

START_TEST(sprintf_15_HEX) {
  char str1[200];
  char str2[200];
  char *str3 = "%*X Test %-*X Test %*.*X TEST %.*X";
  int val = 32;
  int val2 = 8899;
  int val3 = 919;
  int val4 = 32311;
  int ast = 2;
  int ast2 = 5;
  int ast3 = 4;
  int ast4 = 10;
  int ast5 = 7;
  ck_assert_int_eq(
      sprintf(str1, str3, ast, val, ast2, val2, ast3, ast4, val3, ast5, val4),
      s21_sprintf(str2, str3, ast, val, ast2, val2, ast3, ast4, val3, ast5,
                  val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_16_HEX) {
  char str1[200];
  char str2[200];
  char *str3 = "%- X Test %- 15X sdasda %- 15X sdsad %- X";
  int val = -3231;
  int val2 = -3231;
  int val3 = 3231;
  int val4 = 3231;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_1_percent) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "%%Test %o Test";
  int val = 012;
  ck_assert_int_eq(sprintf(str1, str3, val), s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_2_percent) {
  char str1[100];
  char str2[100];
  char *str3 = "Test %o Tes%%%%t %o";
  int val = 012;
  int val2 = 017;
  ck_assert_int_eq(sprintf(str1, str3, val, val2),
                   s21_sprintf(str2, str3, val, val2));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_3_percent) {
  char str1[100];
  char str2[100];
  char *str3 = "%o Te%%st %o Test %o";
  int val = 3015;
  int val2 = 712;
  int val3 = 99;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_percent) {
  char str1[1000] = "\0";
  char str2[1000] = "\0";
  int r1 = sprintf(str1, "%%%%");
  int r2 = s21_sprintf(str2, "%%%%");
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(sprintf_1_e) {
  char str1[100];
  char str2[100];
  char *str3 = "%e Test %5e Test %5.e";
  double num = -764231539.;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_2_e) {
  char str1[100];
  char str2[100];
  char *str3 = "%e\n%.e\n%4e\n%4.e\n%5.10e!";
  double num = -764231539.;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num, num, num),
                   s21_sprintf(str2, str3, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_3_e) {
  char str1[100];
  char str2[100];
  char *str3 = "%#e\n%#.e\n%#5.e\n%#.0e\n%#0.0e!";
  double num = -665695342471359.;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num, num, num),
                   s21_sprintf(str2, str3, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_4_e) {
  char str1[300];
  char str2[300];
  char *str3 = "New test: %020e\nSecond test: %020.e!";
  double num = -5921563224775967.;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_5_e) {
  char str1[300];
  char str2[300];
  char *str3 = "Third test: %010e\nForth test: %010.e!";
  double num = -5921563224775967.;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_6_e) {
  char str1[300];
  char str2[300];
  char *str3 = "Fifth test: %0.0e!";
  double num = -5921563224775967.;
  ck_assert_int_eq(sprintf(str1, str3, num), s21_sprintf(str2, str3, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_7_e) {
  char str1[300];
  char str2[300];
  char *str3 = "New test: %020e\nSecond test: %020.e!";
  double num =
      -5921563224775977777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777776.;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_8_e) {
  char str1[300];
  char str2[300];
  char *str3 = "Third test: %010e\nForth test: %010.e\nFifth test: %0.0e!";
  double num =
      -5921563224775977777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777776.;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_9_e) {
  char str1[300];
  char str2[300];
  char *str3 = "New test: %020e\nSecond test: %020.5e!";
  double num = -592156322477596.;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_10_e) {
  char str1[300];
  char str2[300];
  char *str3 = "Third test: %020.4e\nForth test: %020.3e!";
  double num = -592156322477596.;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_11_e) {
  char str1[300];
  char str2[300];
  char *str3 = "Fifth test: %020.2e\nSixth test: %020.1e!";
  double num = -592156322477596.;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_12_e) {
  char str1[300];
  char str2[300];
  char *str3 = "Seventh test: %020.e\n Eighth test: %020.0e!";
  double num = -592156322477596.;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_13_e) {
  char str1[300];
  char str2[300];
  char *str3 = "New test: % 20e\nSecond test: % 20.5e!";
  double num = -592156322477596.;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_14_e) {
  char str1[300];
  char str2[300];
  char *str3 = "Third test: % 20.4e\nForth test: % 20.3e!";
  double num = -592156322477596.;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_15_e) {
  char str1[300];
  char str2[300];
  char *str3 = "Fifth test: % 20.2e\nSixth test: % 20.1e!";
  double num = -592156322477596.;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_16_e) {
  char str1[300];
  char str2[300];
  char *str3 = "Seventh test: % 20.e\n Eighth test: % 20.0e!";
  double num = -592156322477596.;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_17_e) {
  char str1[300];
  char str2[300];
  char *str3 = "New test: % 31e\nSecond test: % 30.5e!";
  double num = -592156322477596.;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_18_e) {
  char str1[300];
  char str2[300];
  char *str3 = "Third test: % 33.4e\nForth test: % 35.3e!";
  double num = -592156322477596.;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_19_e) {
  char str1[300];
  char str2[300];
  char *str3 = "Fifth test: % 36.2e\nSixth test: % 45.1e!";
  double num = -592156322477596.;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_20_e) {
  char str1[300];
  char str2[300];
  char *str3 = "Seventh test: % 64.e\n Eighth test: % 80.0e!";
  double num = -592156322477596.;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_21_e) {
  char str1[300];
  char str2[300];
  double num1 = -89435776876.;
  double num2 = -894357768.76;
  char *str3 = "New test: %e\nSecond test: %e!";
  ck_assert_int_eq(sprintf(str1, str3, num1, num2),
                   s21_sprintf(str2, str3, num1, num2));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_22_e) {
  char str1[300];
  char str2[300];
  double num3 = -89435.776876;
  double num4 = -0.89435776876;
  char *str3 = "Third test: %e\nForth test: %e\n!";
  ck_assert_int_eq(sprintf(str1, str3, num3, num4),
                   s21_sprintf(str2, str3, num3, num4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_23_e) {
  char str1[300];
  char str2[300];
  double num1 = -.89435776876;
  double num2 = -.00089435776876;
  char *str3 = "New test: %e\nSecond test: %e!";
  ck_assert_int_eq(sprintf(str1, str3, num1, num2),
                   s21_sprintf(str2, str3, num1, num2));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_24_e) {
  char str1[300];
  char str2[300];
  double num3 = -0.000000089435776876;
  double num4 = -0000000000000.89435776876;
  char *str3 = "Third test: %e\nForth test: %e\n!";
  ck_assert_int_eq(sprintf(str1, str3, num3, num4),
                   s21_sprintf(str2, str3, num3, num4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_25_e) {
  char str1[300];
  char str2[300];
  double num1 = -.89435776876;
  double num2 = -.00089435776876;
  double num3 = -0.000000089435776876;
  double num4 = -0000000000000.89435776876;
  char *str3 = "test: %.E!\ntest: %#E!\ntest: %#.E!\ntest: %0.E!\n";
  ck_assert_int_eq(sprintf(str1, str3, num1, num2, num3, num4),
                   s21_sprintf(str2, str3, num1, num2, num3, num4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_26_e) {
  char str1[300];
  char str2[300];
  double num1 = -.3529373967;
  double num2 = -.0003529373967;
  double num3 = -0.00000003529373967;
  char *str3 = "test: % 013.E\ntest: %#4.9E\ntest: %016.2E!";
  ck_assert_int_eq(sprintf(str1, str3, num1, num2, num3),
                   s21_sprintf(str2, str3, num1, num2, num3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_27_e) {
  char str1[300];
  char str2[300];
  double num1 = -.3529373967;
  double num4 = -0000000000000.3529373967;
  char *str3 = "test: %20.E\ntest: %-20.E\n!";
  ck_assert_int_eq(sprintf(str1, str3, num4, num1),
                   s21_sprintf(str2, str3, num4, num1));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_28_e) {
  char str1[300];
  char str2[300];
  double num1 = .3529373967;
  double num2 = .0003529373967;
  double num3 = 0.00000003529373967;
  char *str3 = "test: % 30.1E\ntest: % 30.E\ntest: %030.0E!";
  ck_assert_int_eq(sprintf(str1, str3, num1, num2, num3),
                   s21_sprintf(str2, str3, num1, num2, num3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_29_e) {
  char str1[300];
  char str2[300];
  double num1 = .3529373967;
  double num4 = 0000000000000.3529373967;
  char *str3 = "test: %066.E\ntest: %-20.E\n!";
  ck_assert_int_eq(sprintf(str1, str3, num4, num1),
                   s21_sprintf(str2, str3, num4, num1));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_30_e) {
  char str1[300];
  char str2[300];
  double num1 = 53296575676899283734747273752737878257.;
  char *str3 = "test: %- 17.1E\ntest: % -17.1E!";
  ck_assert_int_eq(sprintf(str1, str3, num1, num1),
                   s21_sprintf(str2, str3, num1, num1));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_31_e) {
  char str1[300];
  char str2[300];
  double num2 = -53296575676899283734747273752737878257.;
  char *str3 = "test: %# 10.2E\ntest: % #10.0E\ntest: %010.E\n!";
  ck_assert_int_eq(sprintf(str1, str3, num2, num2, num2),
                   s21_sprintf(str2, str3, num2, num2, num2));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_32_e) {
  char str1[600];
  char str2[600];
  double num1 = 1234567890000.0938217586;
  char *str3 = "test: %- 67.1E\ntest: % -67.1E!";
  ck_assert_int_eq(sprintf(str1, str3, num1, num1),
                   s21_sprintf(str2, str3, num1, num1));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_33_e) {
  char str1[600];
  char str2[600];
  double num2 = -.12345678900000938217586;
  char *str3 = "test: %# 100.0E\ntest: % #100.0E\ntest: %0100.E\n!";
  ck_assert_int_eq(sprintf(str1, str3, num2, num2, num2),
                   s21_sprintf(str2, str3, num2, num2, num2));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_34_e) {
  char str1[1000];
  char str2[1000];
  double num1 = 1234567890000.0938217586;
  double num2 = -.12345678900000938217586;
  char *str3 = "test: % 070.10E\ntest: % -67.10E\n!";
  ck_assert_int_eq(sprintf(str1, str3, num1, num2),
                   s21_sprintf(str2, str3, num1, num2));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_35_e) {
  char str1[1000];
  char str2[1000];
  double num1 = -12345678900000938217586.;
  double num2 = .12345678900000938217586;
  char *str3 = "test: % 070.10E\ntest: % -67.10E\n!";
  ck_assert_int_eq(sprintf(str1, str3, num1, num2),
                   s21_sprintf(str2, str3, num1, num2));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_36_e) {
  char str1[600];
  char str2[600];
  double num1 = 53296575676899283734747273752737878257.;
  char *str3 = "test: % 10.1E\ntest: %- 10.1E!";
  ck_assert_int_eq(sprintf(str1, str3, num1, num1),
                   s21_sprintf(str2, str3, num1, num1));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_37_e) {
  char str1[600];
  char str2[600];
  double num2 = 53296575676899283.734747273752737878257;
  char *str3 = "test: % -10.0E\ntest: %- 10.0E\ntest: % -10.E\n!";
  ck_assert_int_eq(sprintf(str1, str3, num2, num2, num2),
                   s21_sprintf(str2, str3, num2, num2, num2));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_38_e) {
  char str1[600];
  char str2[600];
  double num1 = .000000005329657567689928373474727375273787825732159676631957;
  double num2 = 53296575676899283.73474727375273787825732159676631957;
  char *str3 = "test: % 20E\ntest: %-20E\ntest: %+ 020.E\n!";
  ck_assert_int_eq(sprintf(str1, str3, num1, num2, num1),
                   s21_sprintf(str2, str3, num1, num2, num1));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_39_e) {
  char str1[600];
  char str2[600];
  double num3 = 5329657567689928373474727375.273787825732159676631957;
  double num4 = 53296575676899283734747273752737878257.32159676631957;
  char *str3 = "test: %#20.E\ntest: %- 20E!";
  ck_assert_int_eq(sprintf(str1, str3, num3, num4),
                   s21_sprintf(str2, str3, num3, num4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_40_e) {
  char str1[100];
  char str2[100];
  char *str3 = "%.e\n%.2e\n%.5E\n%.9E\n%.13E!";
  double num = -2599999999.;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num, num, num),
                   s21_sprintf(str2, str3, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_41_e) {
  char str1[200];
  char str2[200];
  char *str3 = "%.Le\n%.2Le\n%.5Le\n%.9Le\n%.13LE!";
  long double num = -2599999999.;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num, num, num),
                   s21_sprintf(str2, str3, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_42_e) {
  char str1[200];
  char str2[200];
  char *str3 = "%e\n%.e\n%.5e\n%.9e\n%.15E!";
  double num = 0;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num, num, num),
                   s21_sprintf(str2, str3, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_43_e) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %20Le!\ntest: %Le!\ntest: %-10Le!";
  long double num =
      -93257812350000000000000000000683689988320616583292392563908359623906832590653989623598263628236642932982362398.;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_44_e) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %060Le!\ntest: %.14Le!";
  long double num =
      -93257812350000000000000000000683689988320616583292392563908359623906832590653989623598263628236642932982362398.;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_45_e) {
  char str1[100];
  char str2[100];
  char *str3 = "%e Test %5e Test %5.e";
  double num = -764231539.;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_46_e) {
  char str1[100];
  char str2[100];
  char *str3 = "%e\n%.e\n%4e\n%4.e\n%5.10e!";
  double num = -764231539.;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num, num, num),
                   s21_sprintf(str2, str3, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_47_e) {
  char str1[100];
  char str2[100];
  char *str3 = "%#e\n%#.e\n%#5.e\n%#.0e\n%#0.0e!";
  double num = -665695342471359.;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num, num, num),
                   s21_sprintf(str2, str3, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_48_e) {
  char str1[300];
  char str2[300];
  char *str3 = "New test: %020e\nSecond test: %020.e!";
  double num = -5921563224775967.;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_49_e) {
  char str1[300];
  char str2[300];
  double num1 = -.3529373967;
  double num4 = -0000000000000.3529373967;
  char *str3 = "test: %20.E\ntest: %-20.E\n!";
  ck_assert_int_eq(sprintf(str1, str3, num4, num1),
                   s21_sprintf(str2, str3, num4, num1));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_50_e) {
  char str1[300];
  char str2[300];
  char *str3 = "Fifth test: %0.0e!";
  double num = -5921563224775967.;
  ck_assert_int_eq(sprintf(str1, str3, num), s21_sprintf(str2, str3, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_1_g) {
  char str1[200];
  char str2[200];
  char *str3 = "%g TEST %.g TEST %4g TEST %4.g TEST %5.10g!";
  double num = 76.756589367;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num, num, num),
                   s21_sprintf(str2, str3, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_2_g) {
  char str1[200];
  char str2[200];
  char *str3 = "%g TEST %.g TEST %4g TEST %4.g TEST %5.10g!";
  double num = -76.756589367;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num, num, num),
                   s21_sprintf(str2, str3, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_3_g) {
  char str1[200];
  char str2[200];
  char *str3 = "%25.18g TEST\n%.6g TEST\n";
  double num = 838.65400000;
  double num1 = 640.783289182;
  ck_assert_int_eq(sprintf(str1, str3, num, num1),
                   s21_sprintf(str2, str3, num, num1));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_4_g) {
  char str1[200];
  char str2[200];
  char *str3 = "%.2g TEST\n%.3g TEST\n";
  double num = 838.65400000;
  double num1 = 640.783289182;
  ck_assert_int_eq(sprintf(str1, str3, num, num1),
                   s21_sprintf(str2, str3, num, num1));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_5_g) {
  char str1[200];
  char str2[200];
  char *str3 = "%g TEST %.g TEST %4g TEST %4.g TEST %#5.10g!";
  double num = 0.0000756589367;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num, num, num),
                   s21_sprintf(str2, str3, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_6_g) {
  char str1[200];
  char str2[200];
  char *str3 = "%g TEST %.g TEST %4g TEST %4.g TEST %#5.10g!";
  double num = -0.0000756589367;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num, num, num),
                   s21_sprintf(str2, str3, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_7_g) {
  char str1[200];
  char str2[200];
  char *str3 = "%g TEST %.g TEST %4g TEST %4.g TEST %5.10g!";
  double num = 573429.56589367;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num, num, num),
                   s21_sprintf(str2, str3, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_8_g) {
  char str1[200];
  char str2[200];
  char *str3 = "%g TEST %.0g TEST %4.2g TEST %4.g TEST %5.10g!";
  double num = -57251397732103429.56589367;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num, num, num),
                   s21_sprintf(str2, str3, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_9_g) {
  char str1[200];
  char str2[200];
  char *str3 = "test: %15.1g\ntest: %16.2g\ntest: %18.3g!";
  double num = -57251397732103429.56589367;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_10_g) {
  char str1[200];
  char str2[200];
  char *str3 = "test: %10.4g\ntest: %25.5g!";
  double num = -57251397732103429.56589367;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_11_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %-#15.g\ntest: %-26.1g\ntest: %-18.0g!";
  double num = -7648938790.756589;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_12_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %#-10.g\ntest: %-+25.g!";
  double num = -7648938790.756589;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_13_g) {
  char str1[200];
  char str2[200];
  char *str3 = "%6g TEST %.2g TEST %4.5g TEST %4.3g TEST %5.10g!";
  double num = -0.0000756589367;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num, num, num),
                   s21_sprintf(str2, str3, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_14_g) {
  char str1[200];
  char str2[200];
  char *str3 = "%g TEST %.g TEST %4g TEST %4.g TEST %5.10g!";
  double num = 573429.56589367;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num, num, num),
                   s21_sprintf(str2, str3, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_15_g) {
  char str1[400];
  char str2[400];
  char *str3 = "%Lg\n%.Lg!";
  long double num_long = -76.756589;
  ck_assert_int_eq(sprintf(str1, str3, num_long, num_long),
                   s21_sprintf(str2, str3, num_long, num_long));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_16_g) {
  char str1[400];
  char str2[400];
  char *str3 = "%20.10g\n%20.15g\n%-20.5g!";
  double num = -76.756589;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_17_g) {
  char str1[400];
  char str2[400];
  char *str3 = "%Lg\n%.Lg\n%+-#Lg\n%+#.Lg\n%-#.Lg!";
  long double num = 76.756589;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num, num, num),
                   s21_sprintf(str2, str3, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_18_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %15.13g!\ntest: %26.15g!";
  double num = -365289.34628654873789362746834;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_19_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %18.7g!\ntest: %10.15g!\ntest: %25.15g!";
  double num = -365289.34628654873789362746834;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_20_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %15.13g!\ntest: %26.15g!";
  double num = 365289.34628654873789362746834;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_21_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %18.7g!\ntest: %10.15g!\ntest: %25.15g!";
  double num = 365289.34628654873789362746834;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_22_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %020g!\ntest: %-020g!\ntest: %+025g!";
  double num = 837564.4753366;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_23_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %-+ 025.5g!\ntest: %- 020.4g!";
  double num = 837564.4753366;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_24_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %020g!\ntest: %-020g!\ntest: %+025g!";
  double num = -837564.4753366;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_25_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %-+ 025.5g!\ntest: %- 020.4g!";
  double num = -837564.4753366;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_26_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %015g!\ntest: %-026g!\ntest: %+018g!";
  double num = -947.6785643;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_27_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %+- 010.2g!\ntest: %- 025.7g!";
  double num = -947.6785643;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_28_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: % 15.1Lg!\ntest: % -26.15Lg!";
  long double num = 278.723786;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_29_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %- 30.15Lg!\ntest: %+ 50.15Lg!";
  long double num = 278.723786;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_30_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: % +40.15Lg\ntest: % +-25.15Lg!";
  long double num = 278.723786;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_31_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: % 15.1Lg!\ntest: % -26.15Lg!";
  long double num = -2358.367776967;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_32_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %- 30.13Lg!\ntest: %+ 50.15Lg!";
  long double num = -2358.367776967;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_33_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: % +40.15Lg!";
  long double num = -2358.367776967;
  ck_assert_int_eq(sprintf(str1, str3, num), s21_sprintf(str2, str3, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_34_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %.1Lg!\ntest: %.2Lg!\ntest: %.3Lg!";
  long double num = 9999.999999;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_35_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %.6Lg!\ntest: %.Lg!";
  long double num = 9999.999999;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_36_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %.g!\ntest: %.2g!\ntest: %.3g!";
  double num = 0;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_37_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %.10g!\ntest: %.6g!\ntest: %.g!";
  double num = 0;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_38_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %-20.13g!\ntest: %-25.7g!";
  double num = -4353.235300;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_39_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %-.15g!\ntest: %-16g!\ntest: %- 13.5g!";
  double num = -4353.235300;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_40_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %+20.13g!\ntest: %+25.7g!";
  double num = 0.00000235300;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_41_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %+.15g!\ntest: %+16g!\ntest: %+ 13.5g!";
  double num = 0.00000235300;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_42_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %.Lg!\ntest: %.2Lg!\ntest: %.3Lg!";
  long double num = 8236310759735201795485858585858447757573.6495633;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_43_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %.12Lg!\ntest: %.6Lg!\ntest: %.9Lg!";
  long double num = 8236310759735201795485858585858447757573.6495633;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_44_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %Lg!\n";
  long double num = INFINITY;
  ck_assert_int_eq(sprintf(str1, str3, num), s21_sprintf(str2, str3, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_45_g) {
  char str1[400];
  char str2[400];
  char *str3 = "test: %Lg!\ntest: %Lg!\n";
  long double num = NAN;
  long double num1 = 1.;
  ck_assert_int_eq(sprintf(str1, str3, num, num1),
                   s21_sprintf(str2, str3, num, num1));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_46_g) {
  char str1[200];
  char str2[200];
  char *str3 = "%g TEST %.g TEST %4g TEST %4.g TEST %5.10g!";
  double num = 76.756589367;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num, num, num),
                   s21_sprintf(str2, str3, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_47_g) {
  char str1[200];
  char str2[200];
  char *str3 = "%g TEST %.g TEST %4g TEST %4.g TEST %5.10g!";
  double num = -76.756589367;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num, num, num),
                   s21_sprintf(str2, str3, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_48_g) {
  char str1[200];
  char str2[200];
  char *str3 = "%25.18g TEST\n%.6g TEST\n";
  double num = 838.65400000;
  double num1 = 640.783289182;
  ck_assert_int_eq(sprintf(str1, str3, num, num1),
                   s21_sprintf(str2, str3, num, num1));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_49_g) {
  char str1[200];
  char str2[200];
  char *str3 = "%.2g TEST\n%.3g TEST\n";
  double num = 838.65400000;
  double num1 = 640.783289182;
  ck_assert_int_eq(sprintf(str1, str3, num, num1),
                   s21_sprintf(str2, str3, num, num1));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_50_g) {
  char str1[200];
  char str2[200];
  char *str3 = "%g TEST %.g TEST %4g TEST %4.g TEST %#5.10g!";
  double num = 0.0000756589367;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num, num, num),
                   s21_sprintf(str2, str3, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_51_g) {
  char str1[200];
  char str2[200];
  char *str3 = "%g TEST %.g TEST %4g TEST %4.g TEST %#5.10g!";
  double num = 0;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num, num, num),
                   s21_sprintf(str2, str3, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// One parameter pointer
START_TEST(sprintf_1_pointer) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "Test %p Test";
  char *val = "0p32";
  ck_assert_int_eq(sprintf(str1, str3, val), s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);

  // Three pointer parameters
}
END_TEST

START_TEST(sprintf_2_pointer) {
  char str1[100];
  char str2[100];
  char *str3 = "%p Test %p Test %p";
  char *val = "0p7a4";
  char *val2 = "0p91ba123f";
  char *val3 = "0p3123";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);

  // Three decimal parameters
}
END_TEST

START_TEST(sprintf_3_pointer) {
  char str1[100];
  char str2[100];
  char *str3 = "%p Test %p Test %p";
  char *val = "0p3015";
  char *val2 = "0p712";
  char *val3 = "0p99";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);

  // Different sizes
}
END_TEST

START_TEST(sprintf_4_pointer) {
  char str1[100];
  char str2[100];
  char *str3 = "%p Test %p Test %p GOD %p";
  long int *val = (void *)3088675747373646;
  long long int *val2 = (void *)33030030303;
  unsigned short int *val3 = (void *)22600;
  unsigned char *val4 = (void *)120;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);

  // Different width
}
END_TEST

START_TEST(sprintf_5_pointer) {
  char str1[100];
  char str2[100];
  char *str3 = "%3p Test %5p Test %12p";
  char *val = "3015";
  char *val2 = "01234";
  char *val3 = "99";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);

  // Different precision and width
}
END_TEST

START_TEST(sprintf_6_pointer) {
  char str1[200];
  char str2[200];
  char *str3 = "%6.5p Test %.23p Test %3.p TEST %.p";
  char *val = "3015";
  char *val2 = "712";
  char *val3 = "99";
  char *val4 = "38";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);

  // Minus flag
}
END_TEST

START_TEST(sprintf_7_pointer) {
  char str1[200];
  char str2[200];
  char *str3 = "%-10.5p Test %-.4p Test %-16p TEST %-.5p";
  char *val = "3015";
  char *val2 = "712";
  char *val3 = "99";
  char *val4 = "2939";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);

  // Zeroes
}
END_TEST

START_TEST(sprintf_8_pointer) {
  char str1[200];
  char str2[200];
  char *str3 = "%0p Test %0.p Test %0.0p TEST %0p GOD %.p";
  char *val = "3015";
  char *val2 = "712";
  char *val3 = "99";
  char *val4 = "2939";
  char *val5 = "0123";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);

  // Pluses
}
END_TEST

START_TEST(sprintf_9_pointer) {
  char str1[200];
  char str2[200];
  char *str3 = "%+p Test %+3.p Test %+5.7p TEST %+10p";
  char *val = "3015";
  char *val2 = "712";
  char *val3 = "99";
  char *val4 = "2939";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);

  // Zero vals
}
END_TEST

START_TEST(sprintf_10_pointer) {
  char str1[200];
  char str2[200];
  char *str3 = "%p Test %3.p Test %5.7p TEST %10p %#p %-p %+p %.p % .p";
  char *val = 0;
  ck_assert_int_eq(
      sprintf(str1, str3, val, val, val, val, val, val, val, val, val),
      s21_sprintf(str2, str3, val, val, val, val, val, val, val, val, val));
  ck_assert_pstr_eq(str1, str2);

  // Spaces
}
END_TEST

START_TEST(sprintf_11_pointer) {
  char str1[200];
  char str2[200];
  char *str3 = "% p Test % 3.p Test % 5.7p TEST % 10p GOD %.p";
  char *val = "32";
  char *val2 = "8899";
  char *val3 = "91918";
  char *val4 = "32311";
  char *val5 = "23";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);

  // Plus
}
END_TEST

START_TEST(sprintf_12_pointer) {
  char str1[200];
  char str2[200];
  char *str3 = "%+p Test %+3.p Test %+5.7p TEST %+10p GOD %+.p";
  char *val = "32";
  char *val2 = "8899";
  char *val3 = "91918";
  char *val4 = "32311";
  char *val5 = "3261";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);

  // Hash
}
END_TEST

START_TEST(sprintf_13_pointer) {
  char str1[200];
  char str2[200];
  char *str3 = "%#p Test %#3p Test %#5.7p TEST %#.7p Oof %#.p";
  char *val = "32";
  char *val2 = "8899";
  char *val3 = "91918";
  char *val4 = "32311";
  char *val5 = "8894";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);

  // ZERO flag
}
END_TEST

START_TEST(sprintf_14_pointer) {
  char str1[200];
  char str2[200];
  char *str3 = "%0p Test %06p Test %05.7p TEST %0.7p Oof %0.p";
  char *val = "32";
  char *val2 = "8899";
  char *val3 = "91918";
  char *val4 = "32311";
  char *val5 = "8894";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
  // Asterisk
}
END_TEST

START_TEST(sprintf_15_pointer) {
  char str1[200];
  char str2[200];
  char *str3 = "%*p Test %-*p Test %*.*p TEST %.*p Lololol %.*p";
  char *val = "32";
  char *val2 = "8899";
  char *val3 = "9193112312312";
  char *val4 = "32311";
  char *val5 = "WTF cmon";
  int ast = 2;
  int ast2 = 5;
  int ast3 = 4;
  int ast4 = 10;
  int ast5 = 7;
  int ast6 = 18;
  ck_assert_int_eq(sprintf(str1, str3, ast, val, ast2, val2, ast3, ast4, val3,
                           ast5, val4, ast6, val5),
                   s21_sprintf(str2, str3, ast, val, ast2, val2, ast3, ast4,
                               val3, ast5, val4, ast6, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

Suite *lib_suite() {
  Suite *curr_s;
  curr_s = suite_create("CHECK");

  TCase *tc1_1 = tcase_create("sprintf_s");
  TCase *tc1_2 = tcase_create("sprintf_d");
  TCase *tc1_3 = tcase_create("sprintf_u");
  TCase *tc1_4 = tcase_create("sprintf_c");
  TCase *tc1_5 = tcase_create("sprintf_f");
  TCase *tc1_6 = tcase_create("sprintf_o");
  TCase *tc1_7 = tcase_create("sprintf_x");
  TCase *tc1_8 = tcase_create("sprintf_X");
  TCase *tc1_9 = tcase_create("sprintf_percent");
  TCase *tc1_10 = tcase_create("sprintf_e_E");
  TCase *tc1_11 = tcase_create("sprintf_g_G");
  TCase *tc1_12 = tcase_create("sprintf_pointer");

  suite_add_tcase(curr_s, tc1_1);
  tcase_add_test(tc1_1, sprintf_1_string);
  tcase_add_test(tc1_1, sprintf_2_string);
  tcase_add_test(tc1_1, sprintf_3_string);
  tcase_add_test(tc1_1, sprintf_4_string);
  tcase_add_test(tc1_1, sprintf_5_string);
  tcase_add_test(tc1_1, sprintf_6_string);
  tcase_add_test(tc1_1, sprintf_7_string);
  tcase_add_test(tc1_1, sprintf_8_string);
  tcase_add_test(tc1_1, sprintf_9_string);
  tcase_add_test(tc1_1, sprintf_10_string);
  tcase_add_test(tc1_1, sprintf_11_string);
  tcase_add_test(tc1_1, sprintf_12_string);
  tcase_add_test(tc1_1, sprintf_13_string);
  tcase_add_test(tc1_1, sprintf_14_string);
  tcase_add_test(tc1_1, sprintf_15_string);
  tcase_add_test(tc1_1, sprintf_16_string);
  tcase_add_test(tc1_1, sprintf_test_curr_s);
  suite_add_tcase(curr_s, tc1_2);
  tcase_add_test(tc1_2, sprintf_1_signed);
  tcase_add_test(tc1_2, sprintf_2_signed);
  tcase_add_test(tc1_2, sprintf_3_signed);
  tcase_add_test(tc1_2, sprintf_4_signed);
  tcase_add_test(tc1_2, sprintf_5_signed);
  tcase_add_test(tc1_2, sprintf_6_signed);
  tcase_add_test(tc1_2, sprintf_7_signed);
  tcase_add_test(tc1_2, sprintf_8_signed);
  tcase_add_test(tc1_2, sprintf_9_signed);
  tcase_add_test(tc1_2, sprintf_10_signed);
  tcase_add_test(tc1_2, sprintf_11_signed);
  tcase_add_test(tc1_2, sprintf_12_signed);
  tcase_add_test(tc1_2, sprintf_13_signed);
  tcase_add_test(tc1_2, sprintf_14_signed);
  tcase_add_test(tc1_2, sprintf_15_signed);
  tcase_add_test(tc1_2, sprintf_16_signed);
  tcase_add_test(tc1_2, sprintf_17_signed);
  tcase_add_test(tc1_2, sprintf_18_signed);
  tcase_add_test(tc1_2, sprintf_19_signed);
  tcase_add_test(tc1_2, sprintf_test_d1);
  suite_add_tcase(curr_s, tc1_3);
  tcase_add_test(tc1_3, sprintf_1_unsigned);
  tcase_add_test(tc1_3, sprintf_2_unsigned);
  tcase_add_test(tc1_3, sprintf_3_unsigned);
  tcase_add_test(tc1_3, sprintf_4_unsigned);
  tcase_add_test(tc1_3, sprintf_5_unsigned);
  tcase_add_test(tc1_3, sprintf_6_unsigned);
  tcase_add_test(tc1_3, sprintf_7_unsigned);
  tcase_add_test(tc1_3, sprintf_8_unsigned);
  tcase_add_test(tc1_3, sprintf_9_unsigned);
  tcase_add_test(tc1_3, sprintf_10_unsigned);
  tcase_add_test(tc1_3, sprintf_11_unsigned);
  tcase_add_test(tc1_3, sprintf_12_unsigned);
  tcase_add_test(tc1_3, sprintf_13_unsigned);
  tcase_add_test(tc1_3, sprintf_14_unsigned);
  tcase_add_test(tc1_3, sprintf_15_unsigned);
  tcase_add_test(tc1_3, sprintf_16_unsigned);
  tcase_add_test(tc1_3, sprintf_17_unsigned);
  tcase_add_test(tc1_3, sprintf_test_u1);
  suite_add_tcase(curr_s, tc1_4);
  tcase_add_test(tc1_4, sprintf_test_c1);
  tcase_add_test(tc1_4, sprintf_test_c2);
  tcase_add_test(tc1_4, sprintf_1_c);
  tcase_add_test(tc1_4, sprintf_2_c);
  tcase_add_test(tc1_4, sprintf_3_c);
  tcase_add_test(tc1_4, sprintf_4_c);
  tcase_add_test(tc1_4, sprintf_5_c);
  tcase_add_test(tc1_4, sprintf_6_c);
  tcase_add_test(tc1_4, sprintf_7_c);
  tcase_add_test(tc1_4, sprintf_8_c);
  tcase_add_test(tc1_4, sprintf_9_c);
  tcase_add_test(tc1_4, sprintf_10_c);
  tcase_add_test(tc1_4, sprintf_11_c);
  tcase_add_test(tc1_4, sprintf_12_c);
  tcase_add_test(tc1_4, sprintf_13_c);
  tcase_add_test(tc1_4, sprintf_14_c);
  tcase_add_test(tc1_4, sprintf_15_c);
  tcase_add_test(tc1_4, sprintf_16_c);
  tcase_add_test(tc1_4, sprintf_17_c);
  tcase_add_test(tc1_4, sprintf_18_c);
  tcase_add_test(tc1_4, sprintf_19_c);
  suite_add_tcase(curr_s, tc1_5);
  tcase_add_test(tc1_5, sprintf_1_f);
  tcase_add_test(tc1_5, sprintf_2_f);
  tcase_add_test(tc1_5, sprintf_3_f);
  tcase_add_test(tc1_5, sprintf_4_f);
  tcase_add_test(tc1_5, sprintf_5_f);
  tcase_add_test(tc1_5, sprintf_6_f);
  tcase_add_test(tc1_5, sprintf_7_f);
  tcase_add_test(tc1_5, sprintf_8_f);
  tcase_add_test(tc1_5, sprintf_9_f);
  tcase_add_test(tc1_5, sprintf_10_f);
  tcase_add_test(tc1_5, sprintf_11_f);
  tcase_add_test(tc1_5, sprintf_12_f);
  tcase_add_test(tc1_5, sprintf_13_f);
  tcase_add_test(tc1_5, sprintf_14_f);
  tcase_add_test(tc1_5, sprintf_15_f);
  tcase_add_test(tc1_5, sprintf_16_f);
  tcase_add_test(tc1_5, sprintf_17_f);
  tcase_add_test(tc1_5, sprintf_18_f);
  tcase_add_test(tc1_5, sprintf_19_f);
  tcase_add_test(tc1_5, sprintf_20_f);
  tcase_add_test(tc1_5, sprintf_21_f);
  tcase_add_test(tc1_5, sprintf_22_f);
  tcase_add_test(tc1_5, sprintf_23_f);
  tcase_add_test(tc1_5, sprintf_24_f);
  tcase_add_test(tc1_5, sprintf_25_f);
  tcase_add_test(tc1_5, sprintf_26_f);
  tcase_add_test(tc1_5, sprintf_27_f);
  tcase_add_test(tc1_5, sprintf_28_f);
  tcase_add_test(tc1_5, sprintf_30_f);
  tcase_add_test(tc1_5, sprintf_31_f);
  tcase_add_test(tc1_5, sprintf_32_f);
  tcase_add_test(tc1_5, sprintf_33_f);
  tcase_add_test(tc1_5, sprintf_34_f);
  tcase_add_test(tc1_5, sprintf_35_f);
  tcase_add_test(tc1_5, sprintf_36_f);
  tcase_add_test(tc1_5, sprintf_37_f);
  tcase_add_test(tc1_5, sprintf_38_f);
  tcase_add_test(tc1_5, sprintf_39_f);
  tcase_add_test(tc1_5, sprintf_40_f);
  tcase_add_test(tc1_5, sprintf_41_f);
  tcase_add_test(tc1_5, sprintf_42_f);
  tcase_add_test(tc1_5, sprintf_43_f);
  tcase_add_test(tc1_5, sprintf_44_f);
  tcase_add_test(tc1_5, sprintf_45_f);
  tcase_add_test(tc1_5, sprintf_46_f);
  tcase_add_test(tc1_5, sprintf_47_f);
  tcase_add_test(tc1_5, sprintf_48_f);
  tcase_add_test(tc1_5, sprintf_49_f);
  tcase_add_test(tc1_5, sprintf_50_f);
  tcase_add_test(tc1_5, sprintf_51_f);
  tcase_add_test(tc1_5, sprintf_52_f);
  tcase_add_test(tc1_5, sprintf_54_f);
  tcase_add_test(tc1_5, sprintf_test_f);
  suite_add_tcase(curr_s, tc1_6);
  tcase_add_test(tc1_6, sprintf_1_octal);
  tcase_add_test(tc1_6, sprintf_2_octal);
  tcase_add_test(tc1_6, sprintf_3_octal);
  tcase_add_test(tc1_6, sprintf_4_octal);
  tcase_add_test(tc1_6, sprintf_5_octal);
  tcase_add_test(tc1_6, sprintf_6_octal);
  tcase_add_test(tc1_6, sprintf_7_octal);
  tcase_add_test(tc1_6, sprintf_8_octal);
  tcase_add_test(tc1_6, sprintf_9_octal);
  tcase_add_test(tc1_6, sprintf_10_octal);
  tcase_add_test(tc1_6, sprintf_11_octal);
  tcase_add_test(tc1_6, sprintf_12_octal);
  tcase_add_test(tc1_6, sprintf_13_octal);
  tcase_add_test(tc1_6, sprintf_14_octal);
  tcase_add_test(tc1_6, sprintf_15_octal);
  tcase_add_test(tc1_6, sprintf_16_octal);
  tcase_add_test(tc1_6, sprintf_17_octal);
  tcase_add_test(tc1_6, sprintf_18_octal);
  tcase_add_test(tc1_6, sprintf_test_o);
  suite_add_tcase(curr_s, tc1_7);
  tcase_add_test(tc1_7, sprintf_1_hex);
  tcase_add_test(tc1_7, sprintf_2_hex);
  tcase_add_test(tc1_7, sprintf_3_hex);
  tcase_add_test(tc1_7, sprintf_4_hex);
  tcase_add_test(tc1_7, sprintf_5_hex);
  tcase_add_test(tc1_7, sprintf_6_hex);
  tcase_add_test(tc1_7, sprintf_7_hex);
  tcase_add_test(tc1_7, sprintf_8_hex);
  tcase_add_test(tc1_7, sprintf_9_hex);
  tcase_add_test(tc1_7, sprintf_10_hex);
  tcase_add_test(tc1_7, sprintf_11_hex);
  tcase_add_test(tc1_7, sprintf_12_hex);
  tcase_add_test(tc1_7, sprintf_13_hex);
  tcase_add_test(tc1_7, sprintf_14_hex);
  tcase_add_test(tc1_7, sprintf_15_hex);
  tcase_add_test(tc1_7, sprintf_16_hex);
  tcase_add_test(tc1_7, sprintf_17_hex);
  tcase_add_test(tc1_7, sprintf_test_x);
  tcase_add_test(tc1_7, sprintf_test_x2);
  suite_add_tcase(curr_s, tc1_8);
  tcase_add_test(tc1_8, sprintf_1_HEX);
  tcase_add_test(tc1_8, sprintf_2_HEX);
  tcase_add_test(tc1_8, sprintf_3_HEX);
  tcase_add_test(tc1_8, sprintf_4_HEX);
  tcase_add_test(tc1_8, sprintf_5_HEX);
  tcase_add_test(tc1_8, sprintf_6_HEX);
  tcase_add_test(tc1_8, sprintf_7_HEX);
  tcase_add_test(tc1_8, sprintf_8_HEX);
  tcase_add_test(tc1_8, sprintf_9_HEX);
  tcase_add_test(tc1_8, sprintf_10_HEX);
  tcase_add_test(tc1_8, sprintf_11_HEX);
  tcase_add_test(tc1_8, sprintf_12_HEX);
  tcase_add_test(tc1_8, sprintf_13_HEX);
  tcase_add_test(tc1_8, sprintf_14_HEX);
  tcase_add_test(tc1_8, sprintf_15_HEX);
  tcase_add_test(tc1_8, sprintf_16_HEX);
  suite_add_tcase(curr_s, tc1_9);
  tcase_add_test(tc1_9, sprintf_1_percent);
  tcase_add_test(tc1_9, sprintf_2_percent);
  tcase_add_test(tc1_9, sprintf_3_percent);
  tcase_add_test(tc1_9, sprintf_test_percent);
  suite_add_tcase(curr_s, tc1_10);
  tcase_add_test(tc1_10, sprintf_1_e);
  tcase_add_test(tc1_10, sprintf_2_e);
  tcase_add_test(tc1_10, sprintf_3_e);
  tcase_add_test(tc1_10, sprintf_4_e);
  tcase_add_test(tc1_10, sprintf_5_e);
  tcase_add_test(tc1_10, sprintf_6_e);
  tcase_add_test(tc1_10, sprintf_7_e);
  tcase_add_test(tc1_10, sprintf_8_e);
  tcase_add_test(tc1_10, sprintf_9_e);
  tcase_add_test(tc1_10, sprintf_10_e);
  tcase_add_test(tc1_10, sprintf_11_e);
  tcase_add_test(tc1_10, sprintf_12_e);
  tcase_add_test(tc1_10, sprintf_13_e);
  tcase_add_test(tc1_10, sprintf_14_e);
  tcase_add_test(tc1_10, sprintf_15_e);
  tcase_add_test(tc1_10, sprintf_16_e);
  tcase_add_test(tc1_10, sprintf_17_e);
  tcase_add_test(tc1_10, sprintf_18_e);
  tcase_add_test(tc1_10, sprintf_19_e);
  tcase_add_test(tc1_10, sprintf_20_e);
  tcase_add_test(tc1_10, sprintf_21_e);
  tcase_add_test(tc1_10, sprintf_22_e);
  tcase_add_test(tc1_10, sprintf_23_e);
  tcase_add_test(tc1_10, sprintf_24_e);
  tcase_add_test(tc1_10, sprintf_25_e);
  tcase_add_test(tc1_10, sprintf_26_e);
  tcase_add_test(tc1_10, sprintf_27_e);
  tcase_add_test(tc1_10, sprintf_28_e);
  tcase_add_test(tc1_10, sprintf_29_e);
  tcase_add_test(tc1_10, sprintf_30_e);
  tcase_add_test(tc1_10, sprintf_31_e);
  tcase_add_test(tc1_10, sprintf_32_e);
  tcase_add_test(tc1_10, sprintf_33_e);
  tcase_add_test(tc1_10, sprintf_34_e);
  tcase_add_test(tc1_10, sprintf_35_e);
  tcase_add_test(tc1_10, sprintf_36_e);
  tcase_add_test(tc1_10, sprintf_37_e);
  tcase_add_test(tc1_10, sprintf_38_e);
  tcase_add_test(tc1_10, sprintf_39_e);
  tcase_add_test(tc1_10, sprintf_40_e);
  tcase_add_test(tc1_10, sprintf_41_e);
  tcase_add_test(tc1_10, sprintf_42_e);
  tcase_add_test(tc1_10, sprintf_43_e);
  tcase_add_test(tc1_10, sprintf_44_e);
  tcase_add_test(tc1_10, sprintf_45_e);
  tcase_add_test(tc1_10, sprintf_46_e);
  tcase_add_test(tc1_10, sprintf_47_e);
  tcase_add_test(tc1_10, sprintf_48_e);
  tcase_add_test(tc1_10, sprintf_49_e);
  tcase_add_test(tc1_10, sprintf_50_e);
  suite_add_tcase(curr_s, tc1_11);
  tcase_add_test(tc1_11, sprintf_1_g);
  tcase_add_test(tc1_11, sprintf_2_g);
  tcase_add_test(tc1_11, sprintf_3_g);
  tcase_add_test(tc1_11, sprintf_4_g);
  tcase_add_test(tc1_11, sprintf_5_g);
  tcase_add_test(tc1_11, sprintf_6_g);
  tcase_add_test(tc1_11, sprintf_7_g);
  tcase_add_test(tc1_11, sprintf_8_g);
  tcase_add_test(tc1_11, sprintf_9_g);
  tcase_add_test(tc1_11, sprintf_10_g);
  tcase_add_test(tc1_11, sprintf_11_g);
  tcase_add_test(tc1_11, sprintf_12_g);
  tcase_add_test(tc1_11, sprintf_13_g);
  tcase_add_test(tc1_11, sprintf_14_g);
  tcase_add_test(tc1_11, sprintf_15_g);
  tcase_add_test(tc1_11, sprintf_16_g);
  tcase_add_test(tc1_11, sprintf_17_g);
  tcase_add_test(tc1_11, sprintf_18_g);
  tcase_add_test(tc1_11, sprintf_19_g);
  tcase_add_test(tc1_11, sprintf_20_g);
  tcase_add_test(tc1_11, sprintf_21_g);
  tcase_add_test(tc1_11, sprintf_22_g);
  tcase_add_test(tc1_11, sprintf_23_g);
  tcase_add_test(tc1_11, sprintf_24_g);
  tcase_add_test(tc1_11, sprintf_25_g);
  tcase_add_test(tc1_11, sprintf_26_g);
  tcase_add_test(tc1_11, sprintf_27_g);
  tcase_add_test(tc1_11, sprintf_28_g);
  tcase_add_test(tc1_11, sprintf_29_g);
  tcase_add_test(tc1_11, sprintf_30_g);
  tcase_add_test(tc1_11, sprintf_31_g);
  tcase_add_test(tc1_11, sprintf_32_g);
  tcase_add_test(tc1_11, sprintf_33_g);
  tcase_add_test(tc1_11, sprintf_34_g);
  tcase_add_test(tc1_11, sprintf_35_g);
  tcase_add_test(tc1_11, sprintf_36_g);
  tcase_add_test(tc1_11, sprintf_37_g);
  tcase_add_test(tc1_11, sprintf_38_g);
  tcase_add_test(tc1_11, sprintf_39_g);
  tcase_add_test(tc1_11, sprintf_40_g);
  tcase_add_test(tc1_11, sprintf_41_g);
  tcase_add_test(tc1_11, sprintf_42_g);
  tcase_add_test(tc1_11, sprintf_43_g);
  tcase_add_test(tc1_11, sprintf_44_g);
  tcase_add_test(tc1_11, sprintf_45_g);
  tcase_add_test(tc1_11, sprintf_46_g);
  tcase_add_test(tc1_11, sprintf_47_g);
  tcase_add_test(tc1_11, sprintf_48_g);
  tcase_add_test(tc1_11, sprintf_49_g);
  tcase_add_test(tc1_11, sprintf_50_g);
  tcase_add_test(tc1_11, sprintf_51_g);
  suite_add_tcase(curr_s, tc1_12);
  tcase_add_test(tc1_12, sprintf_1_pointer);
  tcase_add_test(tc1_12, sprintf_2_pointer);
  tcase_add_test(tc1_12, sprintf_3_pointer);
  tcase_add_test(tc1_12, sprintf_4_pointer);
  tcase_add_test(tc1_12, sprintf_5_pointer);
  tcase_add_test(tc1_12, sprintf_6_pointer);
  tcase_add_test(tc1_12, sprintf_7_pointer);
  tcase_add_test(tc1_12, sprintf_8_pointer);
  tcase_add_test(tc1_12, sprintf_9_pointer);
  tcase_add_test(tc1_12, sprintf_10_pointer);
  tcase_add_test(tc1_12, sprintf_11_pointer);
  tcase_add_test(tc1_12, sprintf_12_pointer);
  tcase_add_test(tc1_12, sprintf_13_pointer);
  tcase_add_test(tc1_12, sprintf_14_pointer);
  tcase_add_test(tc1_12, sprintf_15_pointer);
  return curr_s;
}