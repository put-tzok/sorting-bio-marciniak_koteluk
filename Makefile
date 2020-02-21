all: release debug

release: main.c
	$(CC) -Ofast -o $@ $^

debug: main.c
	$(CC) -g -o $@ $^
