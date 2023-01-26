CC = gcc
CFLAGS = -c -Wall
PROFILE_FLAGS = -fprofile-arcs -ftest-coverage
TST_LIBS = -lcheck -lm -lpthread
COV_LIBS = -lgcov -coverage
SRC_DIR= src
TST_DIR= tests
SRC_FILES = $(addprefix $(SRC_DIR)/, *.c) 
TST_FILES = $(addprefix $(TST_DIR)/, *.c)
GCOV = gcovr 
GCONV_FLAGS = -r . --html --html-details 


all: coverage_report.html

s21_math.o:
	$(CC) $(CFLAGS) $(PROFILE_FLAGS) s21_math.c

s21_test.o: $(TST_FILES)
	$(CC) $(CFLAGS) $(PROFILE_FLAGS) $(TST_FILES)

s21_test_all: s21_math.o s21_test.o
	$(CC) s21_math.o s21_test.o $(TST_LIBS) $(COV_LIBS) -o s21_test_all

test: s21_test_all
	./s21_test_all

rebuild: clean s21_test_all test
	
gcov_report: test
	$(GCOV) $(GCONV_FLAGS) -o coverage_report.html

.PHONY: clean all

clean:
	-rm *.o *.html *.gcda *.gcno s21_test_all
