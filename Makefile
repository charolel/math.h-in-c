CC = gcc
CFLAGS = -Wall -Werror -Wextra
STYLE = clang-format
LIB_O_FILES = *.o
LIB_C_FILE = s21_abs.c s21_acos.c s21_asin.c s21_atan.c s21_ceil.c s21_cos.c s21_exp.c s21_fabs.c s21_floor.c s21_fmod.c s21_log.c s21_pow.c s21_sin.c s21_sqrt.c s21_tan.c
TEST_LIBS=-lcheck -lm -lpthread 
TESTFLAGS := -lcheck -coverage -lpthread -pthread
OUTPUT = test.out

all: s21_math.a test gcov_report clean

s21_math.a: $(LIB_C_FILE)
	$(CC) -c $(CFLAGS) $(LIB_C_FILE)
	ar r s21_math.a *.o
	ranlib s21_math.a

test: s21_math.a
	$(CC) test.c $(CFLAGS) $(TESTFLAGS) -L. s21_math.a -o test
	./test

gcov_report: s21_math.a
	$(CC) --coverage test.c $(LIB_C_FILE) s21_math.a -L. s21_math.a $(TEST_LIBS) -o ./test.out
	./test.out
	gcov s21_*.gcno > report.html
	open report.html

lcov_report: s21_math.a
	$(CC) --coverage test.c $(LIB_C_FILE) s21_math.a -L. s21_math.a $(TEST_LIBS) -o ./test.out
	./test.out
	lcov -t "test" -o test_report.info -c -d .
	genhtml -o report test_report.info
	open report/index.html

style:
	clang-format -i *.c *.h
	clang-format -n *.c *.h

check:
	leaks --atExit -- ./test
	cppcheck --enable=all --suppress=missingIncludeSystem *.c

clean:
	rm *.o *.a test *.g* test.out

total_clean: 
	rm -rf test_report.info report.html report

rebuild:
	make clean
	make all
