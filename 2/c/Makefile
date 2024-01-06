build: 2.c
	cc -g -Wall -Wextra -Werror -pedantic -std=c11 2.c -o 2
	./2

clean:
	rm -rf 2 *.dSYM

r: build
	export MallocStackLogging=1; \
	leaks --atExit -- ./2; \
	unset MallocStackLogging
