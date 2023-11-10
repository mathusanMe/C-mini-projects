# Makefile for mk-tar

CC = gcc
CFLAGS = -Wall -Werror

# List the source files for mk-tar
SRCS = mk-tar.c

# Define the target executable
TARGET = mk-tar

# Generate a list of object files from the source files
OBJS = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
    $(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

%.o: %.c
    $(CC) $(CFLAGS) -c $<

clean:
    rm -f $(TARGET) $(OBJS)
