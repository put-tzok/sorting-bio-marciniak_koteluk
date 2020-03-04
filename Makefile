CFLAGS	= -Wall -Wextra -Wno-unused-parameter -std=c11

all: release debug

release: Source/main.c Source/sorting.c Source/benchmark.c
	$(CC) $(CFLAGS) -Ofast -o $@ $^

debug: Source/main.c Source/sorting.c Source/benchmark.c
	$(CC) $(CFLAGS) -g -o $@ $^
