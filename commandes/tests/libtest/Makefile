CC = gcc

all : test

test : libfoo.so
	$(CC) main.c -o $@ -I. -L. -lfoo #-Wl,-rpath=$(PWD)

libfoo.so : lib.c
	$(CC) -shared -fpic $^ -o $@

clean :
	rm -fr ./libfoo.so ./test
