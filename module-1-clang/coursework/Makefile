CC = gcc
CFLAGS = -std=c99 -Wall -Wextra -pedantic -O3
TARGET = coursework
SRCS = main.c temp_functions.c vector.c cli.c
OBJS = $(SRCS:.c=.o)
HEADERS = temp_functions.h vector.h cli.h

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)