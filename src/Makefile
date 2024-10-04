CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11
LFLAGS = -lcheck -lm -lrt -lsubunit -lpthread -lgcov
GCOVFLAGS = -fprofile-arcs -ftest-coverage -lgcov
LC = gcov
OPEN_CMD = xdg-open

SOURCE_FILES = $(wildcard s21_*.c)
OBJECT_FILES = $(patsubst %.c, %.o, $(SOURCE_FILES))

all: gcov_report

s21_string.a: $(SOURCE_FILES)
	$(foreach file, $(SOURCE_FILES), $(CC) $(CFLAGS) -c $(file) -o $(basename $(file)).o;)
	ar rcs s21_string.a *.o
	rm *.o


s21_gcov_string.a: $(OBJECT_FILES)
	ar rsc $@ $^


$(OBJECT_FILES): $(SOURCE_FILES)
	$(CC) $(CFLAGS) -c $^ $(GCOVFLAGS)

gcov_report: clean s21_gcov_string.a
	$(CC) $(CFLAGS) unit_tests.c s21_gcov_string.a -o gcov_test $(GCOVFLAGS) $(LFLAGS)
	./gcov_test
	mkdir -p coverage_report
	~/.local/bin/gcovr -o coverage_report/gcov_report.html --html --html-details
	$(OPEN_CMD) coverage_report/gcov_report.html

check:
	clang-format -n *.c *.h

valgrind:
	valgrind --tool=memcheck --leak-check=yes ./gcov_test

clean: 
	rm -rf *.o *.gcno *.gcda *.gcov *.html *.css gcov_test *.a coverage_report
