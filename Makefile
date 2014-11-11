
all: test

test: lcg.h test.cpp Makefile
	g++ test.cpp -o test
	./test 20
