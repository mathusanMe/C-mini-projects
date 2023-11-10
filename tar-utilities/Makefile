# Makefile for tar-utilities

CC = gcc
CFLAGS = -Wall -Werror

all: list-tar de-tar mk-tar main

list-tar:
	$(MAKE) -C tar-utilities/list-tar

de-tar:
	$(MAKE) -C tar-utilities/de-tar

mk-tar:
	$(MAKE) -C tar-utilities/mk-tar

main: main.o
	$(CC) $(CFLAGS) -o main main.o

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

clean:
	rm -f main main.o
	$(MAKE) -C tar-utilities/list-tar clean
	$(MAKE) -C tar-utilities/de-tar clean
	$(MAKE) -C tar-utilities/mk-tar clean


tarexamples:
	echo "I tawt I taw a puddy tat" >| tweety
	echo "Sufferin' succotash" >| sylvester
	chmod ug+x sylvester
	tar cf tweety.tar tweety sylvester
	rm tweety sylvester
	head -c 2048 tweety.tar >| without_zeros.tar
	head -c 1545 tweety.tar >| truncated.tar
	mv tweety.tar without_zeros.tar truncated.tar /tmp
	(cd templates; tar cf tarutils.tar tarutils.c tarutils.h ; mv tarutils.tar /tmp)

