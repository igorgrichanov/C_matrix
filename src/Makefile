CC=gcc -std=c11
CFLAGS=-Wall -Wextra -Werror
FLAG_COV=--coverage
VALGRIND_FLAGS=--tool=memcheck --track-origins=yes
FUNC_TESTS_C=tests/*_test.c

OS=$(shell uname -s)

ifeq ($(OS),Linux)
	TEST_LIBS=-lcheck -lsubunit -pthread -lrt -lm
else
	TEST_LIBS=`pkg-config --cflags --libs check` -lm
endif

all: matrix.a

matrix.a: *.c
	$(CC) $(CFLAGS) -c $^
	ar rc $@ *.o
	ranlib $@

test: *.c
	$(CC) $(CFLAGS) -o matrix tests/main.c $(FUNC_TESTS_C) $^ $(FLAG_COV) $(TEST_LIBS)
	./matrix

gcov_report: test
	gcov ./matrix
	lcov -c -d . -o gcov.info
	genhtml gcov.info -o gcov_report
	open gcov_report/index.html

format:
	@cp ../materials/linters/.clang-format ./
	@clang-format -i *.c *.h tests/*.c tests/*.h
	@clang-format -n *.c *.h tests/*.c tests/*.h
	@rm .clang-format

valgrind: clean
	$(CC) $(CFLAGS) -o s21_matrix tests/main.c $(FUNC_TESTS_C) -g -O0 *.c $(TEST_LIBS)
	valgrind $(VALGRIND_FLAGS) ./matrix

clean:
	rm -rf gcov_report/
	rm -rf objects/
	rm -f *.info matrix
	rm -f *.gcda *.gcno *.gcov *.o *.a

rebuild: clean all