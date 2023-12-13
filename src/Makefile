CC=gcc -std=c11
CFLAGS=-Wall -Wextra -Werror
FLAG_COV=--coverage

SOURCES=*.c
FUNC_TESTS_C=tests/*_test.c

OS=$(shell uname -s)

ifeq ($(OS),Linux)
	TEST_LIBS =-lcheck -lsubunit -pthread -lrt -lm
else
	TEST_LIBS =-lcheck
endif

all: s21_decimal.a

s21_matrix.a:
	$(CC) $(CFLAGS) -c $(SOURCES)
	ar rc $@ *.o
	ranlib $@

test: s21_matrix.a
	$(CC) $(CFLAGS) -o s21_matrix tests/main.c $(FUNC_TESTS_C) $(SOURCES) $(FLAG_COV) $(TEST_LIBS)
	./s21_matrix

gcov_report: test
	gcov ./s21_matrix
	lcov -c -d . -o gcov.info
	genhtml gcov.info -o gcov_report
	open gcov_report/index.html

format:
	@cp ../materials/linters/.clang-format ./
	@clang-format -i *.c *.h tests/*.c tests/*.h
	@clang-format -n *.c *.h tests/*.c tests/*.h
	@rm .clang-format

clean:
	rm -rf gcov_report/
	rm -rf objects/
	rm -f *.info s21_matrix
	rm -f *.gcda *.gcno *.gcov *.o *.a

rebuild: clean all