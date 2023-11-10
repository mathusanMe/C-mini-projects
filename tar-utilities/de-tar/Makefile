# Makefile for de-tar

CC = gcc
CFLAGS = -Wall -Werror

# List the source files for de-tar
SRCS = de-tar.c

# Define the target executable
TARGET = de-tar

# Generate a list of object files from the source files
OBJS = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
    $(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

%.o: %.c
    $(CC) $(CFLAGS) -c $<

clean:
    rm -f $(TARGET) $(OBJS)
