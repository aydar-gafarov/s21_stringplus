CC= gcc
CFLAGS = -Wall -Werror -Wextra -std=c11 -pedantic
OS := $(shell uname)
SRC = s21_memcmp.c s21_sprintf.c s21_strspn.c s21_strlen.c s21_strncpy.c s21_strstr.c s21_trim.c s21_insert.c s21_memcpy.c s21_strchr.c s21_strncat.c s21_strpbrk.c s21_strtok.c s21_to_lower.c s21_memchr.c s21_memset.c s21_strcspn.c s21_strncmp.c s21_strrchr.c s21_to_upper.c s21_strerror.c
GCOVFLAGS = -fprofile-arcs -ftest-coverage
COV_LIBS = -lgcov -coverage
FLAGS:= -lcheck -lgcov --coverage

ifeq ($(OS), Linux)
FLAGS+=-lrt -lsubunit -lm -lcheck_pic -pthread
endif

OBJ = $(addprefix obj/,$(SRC:.c=.o))
OBJ_GCOV = $(addprefix gcov_obj/,$(SRC:.c=.o))

all: s21_string.a s21_string_gcov.a gcov_report

s21_string.a: $(OBJ)
	ar -rcs $@ $(OBJ)

s21_string_gcov.a: $(OBJ_GCOV)
	ar -rcs $@ $(OBJ_GCOV)
	
test: s21_string_gcov.a sprintf_test string_func_test
	$(CC) gcov_obj/s21_string_func_test.o s21_string_gcov.a -o string_func_test $(GCOVFLAGS) $(FLAGS)
	./string_func_test
	$(CC) gcov_obj/s21_sprintf_test.o s21_string_gcov.a -o sprintf_test $(GCOVFLAGS) $(FLAGS)
	./sprintf_test

gcov_report: s21_string_gcov.a test
	lcov -t "s21_string" -o gcov_obj/test.info -c -d .
	genhtml gcov_obj/test.info --output-directory report
	open report/index.html

sprintf_test: 
	$(CC) $(GCOVFLAGS) s21_sprintf_test.c -c -o gcov_obj/s21_sprintf_test.o

string_func_test: 
	$(CC) $(GCOVFLAGS) s21_string_func_tests.c -c -o gcov_obj/s21_string_func_test.o

gcov_obj/%.o: %.c
	$(CC) $(CFLAGS) $(GCOVFLAGS) -c $< -o $@

obj/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

valgrind: test
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./sprintf_test >valgrind_sprintf_test_out.txt
# valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./string_func_test >valgrind_string_func_out.txt

clean: 
	rm -rf *.a *_test obj/* gcov_obj/* report *.txt

