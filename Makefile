all: td.c
	cc -o td td.c -lncurses
clean:
	rm td
