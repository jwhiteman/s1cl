build:
	csc 4.scm

clean:
	rm -rf 4

benchmark: build
	hyperfine --runs 10 ./4
