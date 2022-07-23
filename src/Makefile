CC = gcc
CFLAGS = -Wall -Werror -Wextra
TEST_LIBS = -lcheck -lm -lpthread
OBJECTS = s21_math.o
SOURSES = s21_math.c
GCOVFLAGS = -fprofile-arcs -ftest-coverage

ifeq ($(OS),Linux)
	CFLAGS+=-D LINUX
	TST_LIBS+= -lcheck_pic -lrt -lsubunit
else
	ifeq ($(OS),Darwin)
		CFLAGS+=-D MAC
	else
		CFLAGS+=-D LINUX
		TST_LIBS+= -lcheck_pic -lrt -lsubunit
	endif
endif

all: clean s21_math.a test gcov_report

s21_math.a: s21_math.o
	$(CC) -c $(SOURSES)
	ar rcs s21_math.a $(OBJECTS)

clean:
	rm -rf ./*.o ./*.a ./a.out gcov_test *.html *.css ./GcovReport ./*.gcno ./*.gcda ./report ./*.info ./math_o ./*.dSYM ./s21_math_test ./CPPLINT* test

test: s21_test.c s21_math.a
	$(CC) $(CFLAGS) -c s21_test.c -o test.o
	$(CC) test.o s21_math.a $(TEST_LIBS) -o test
	./test

gcov_report: s21_math.a 
	$(CC) $(CFLAGS) --coverage s21_test.c s21_math.c s21_math.a $(TEST_LIBS) -o gcov_test
	chmod +x *
	./gcov_test
	lcov -t "gcov_test" -o gcov_test.info --no-external -c -d .
	genhtml -o report/ gcov_test.info
	open ./report/index.html
	
rebuild: clean all
