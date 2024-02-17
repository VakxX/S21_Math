OS = $(shell uname)
FLAGS = -Wall -Wextra -Werror -std=c11
FLAGS_FOR_GCOV = -fprofile-arcs -ftest-coverage
ALL_TESTS = $(wildcard s21_math_for_test/s21_functions_test/*.c)

ifeq ($(OS), GNU/Linux)
	TEST_FLAGS = -lcheck -lm -lpthread -lrt -lsubunit
else
	TEST_FLAGS = -lcheck -lm -lpthread
endif

all: s21_math.a

clean:
	@rm -rf *.gcda *.gcno *.o *.info *.a report gcov

rebuild:
	@make clean && make gcov_report

test: s21_math.a
	gcc $(FLAGS) $(ALL_TESTS) s21_math_for_test/s21_tests.c --coverage s21_math.a $(TEST_FLAGS) -o s21_tests
	./s21_tests

s21_math.a:
	gcc $(FLAGS) -c s21_functions/*.c
	ar rc s21_math.a *.o
	ranlib s21_math.a

s21_math.a_gcov:
	gcc $(FLAGS) $(FLAGS_FOR_GCOV) -c s21_functions/*.c
	ar rc s21_math.a *.o
	ranlib s21_math.a

gcov_report: s21_math.a_gcov test
	mkdir gcov
	mv s21_*.gcda ./gcov
	mv s21_*.gcno ./gcov
	lcov -t "s21_math" -o s21_math.info -c -d ./gcov/.
	genhtml -o report ./s21_math.info
	rm -fr ./gcov 
	rm *.o s21_tests

cl_fr:
	@cp ../materials/linters/.clang-format ../src  
	@clang-format -n -style=google *.h ./s21_math_for_test/s21_functions_test/*.c ./s21_math_for_test/*.c ./s21_math_for_test/*.h ./s21_functions/*.c

install_brew:
	cd ~
	curl -fsSL https://rawgit.com/kube/42homebrew/master/install.sh | zsh
	brew install lcov
