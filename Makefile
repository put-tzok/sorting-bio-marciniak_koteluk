CFLAGS	= -Wall -Wextra -Wno-unused-parameter

all: release debug

release: main.c
	$(CC) $(CFLAGS) -Ofast -o $@ $^

debug: main.c
	$(CC) $(CFLAGS) -g -o $@ $^
