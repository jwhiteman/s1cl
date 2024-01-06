build:
	cc -Wall -Wextra -Werror -pedantic -std=c11 4.c -o 4
	./4

clean:
	rm -rf 4

memcheck:
	export MallocStackLogging=1; \
	leaks --atExit -- ./4; \
	unset MallocStackLogging
