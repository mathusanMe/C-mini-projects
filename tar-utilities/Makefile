CC=gcc
SHELL=/bin/bash
CFLAGS=-Wall -std=c99 -g
EXEC=program
SRC= $(shell find src/ tests/ -maxdepth 3 -type f -regex ".*\.c")
OBJ= $(patsubst src/%, bin/%, $(SRC:.c=.o))
DIR= $(patsubst src/%, bin/%, $(shell find src/ -maxdepth 2 -type d))

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $(EXEC) $^

bin/%.o: src/%.c | directories
	$(CC) $(CFLAGS) -o $@ -c $<

directories: 
	mkdir -p $(DIR)

.PHONY: clean mrproper

clean:
	rm -rf $(OBJ)

mrproper: clean
	rm -rf $(EXEC)
	rm -R bin

tarexamples:
	echo "I tawt I taw a puddy tat" >| tweety
	echo "Sufferin' succotash" >| sylvester
	chmod ug+x sylvester
	tar cf tweety.tar tweety sylvester
	rm tweety sylvester
	head -c 2048 tweety.tar >| without_zeros.tar
	head -c 1545 tweety.tar >| truncated.tar
	mv tweety.tar without_zeros.tar truncated.tar /tmp
	(cd src/utils; tar cf tarutils.tar tarutils.c tarutils.h ; mv tarutils.tar /tmp)

