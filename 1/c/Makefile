build: 1.c
	cc -Wall -Wextra -Werror -pedantic -std=c11 ../../lib/decodehex.c ../../lib/base64.c 1.c -o 1

clean:
	rm -rf 1

r: build
	export MallocStackLogging=1; \
	leaks --atExit -- ./1; \
	unset MallocStackLogging
