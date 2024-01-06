all:
	cc -Wall -Wextra -Werror -pedantic -std=c11 decodehex.c main.c -o 1

clean:
	rm -rf 1 output output.c myadd.o

scm:
	csc decodehex.c -cxx gcc decodehex.scm -o output
