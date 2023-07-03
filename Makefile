CC = clang
CFLAGS = -Wall -Wextra -Wpedantic -Werror -O2
LDFLAGS = -lm

SOURCES = $(wildcard *.c)
OBJECTS = $(patsubst %.c, %.o, $(SOURCES))
HFILE = mathlib.h

all: mathlib-test

%.o: %.c $(HFILE)
	$(CC) $(CFLAGS) -c $<

mathlib-test: $(OBJECTS) mathlib-test.o
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

tidy:
	rm -rf $(wildcard *.o)
clean: tidy
	rm -rf mathlib-test
format:
	clang-format -i -style=file *.[c,h]

