CC = gcc
CFLAGS	= -Wall -Wextra -Wno-unused-parameter

all: release debug

release: main.c Source/sorting.c Source/benchmark.c
	$(CC) $(CFLAGS) -Ofast -o $@ $^

debug: main.c Source/sorting.c Source/benchmark.c
	$(CC) $(CFLAGS) -g -Og -std=c11 -o $@ $^
