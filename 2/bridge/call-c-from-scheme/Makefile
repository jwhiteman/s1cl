build: 2.c 2.h
	cc -g -Wall -Wextra -Werror -pedantic -std=c11 2.c -o ex2

clean:
	rm -rf ex2 output

x:
	csc 2.c 2.scm -o output

y:
	csc -t 2.scm

scm:
	csc 2.c -cxx gcc 2.scm -o output
