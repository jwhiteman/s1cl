build:
	cc -Wall -Wextra -Werror -pedantic -std=c11 6.c base64.c -o 6

clean:
	rm -rf 6 *dSYM

nonewlines: 6.txt
	tr -d '\n' < 6.txt > 6-no-newlines.txt

r: build
	export MallocStackLogging=1; \
	leaks --atExit -- ./6; \
	unset MallocStackLogging
