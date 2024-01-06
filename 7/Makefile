build: 7.c
	cc -Wall -Wextra -Werror -pedantic -std=c11 7.c base64.c -o 7 -lcrypto

clean:
	rm -rf 7

r: build
	export MallocStackLogging=1; \
	leaks --atExit -- ./7; \
	unset MallocStackLogging
