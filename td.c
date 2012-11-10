/*
 * TD (Text Editor) Copyright © 2012 phyrrus9 <phyrrus9@gmail.com>
 * Very simple text editing program using ncurses, dynamic memory allocation,
 * and all written in C. Have fun.
 */

#include <curses.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define version "1.1"

char *filename;
int fsize;

void display(WINDOW *s, int position, char *filebuf)
{
	wclear(s);
	int length = COLS / 6;
	wprintw(s, "[Position: %d] [Histrory: %d: ", position, length);
	for (int i = 0, p = position - length; i < length; i++)
	{
		if (filebuf[p + i] != '\n')
			wprintw(s, "%c", filebuf[p + i]);
		else
			wprintw(s, " ");
	}
	wprintw(s, "] ");
	wprintw(s, "[Lines: %d Cols: %d Total: %d %% of buffer used: %.2f] [File: %s]", LINES - 5, COLS, (LINES - 5) * COLS, filename, ((float)fsize / ((LINES - 5) * COLS)) * 100);
	wrefresh(s);
}

void render(WINDOW *w, int position, char *filebuf)
{

}

int main(int argc, char * * argv)
{
	if (argc < 2)
	{
		printf("TD VERSION %s ~phyrrus9\n", version);
		printf("ERROR! No file specified\n");
		exit(-1);
	}
	FILE *f;
	char t;
	char *filebuf;
	filename = argv[1];
	f = fopen(filename, "r");
	if (f == NULL)
	{
		f = fopen(filename, "w"); //create a new file
		fclose(f);
		f = fopen(filename, "r");
		if (f == NULL)
		{
			exit(-2);
		}
	}
	int i, position;
	i = fsize = position = 0;
	while (fscanf(f, "%c", &t) != EOF)
	{
		fsize++;
	}
	filebuf = (char *)malloc(fsize + 1);
	fclose(f);
	f = fopen(filename, "r");
	i = 0;
	initscr();
	refresh();
	noecho();
	WINDOW *w;
	WINDOW *s;
	w = newwin(LINES - 5, COLS, 0, 0);
	s = newwin(2, COLS, LINES - 4, 0);
	while (fscanf(f, "%c", &t) != EOF & i < fsize)
	{
		wprintw(w, "%c", t);
		filebuf[i] = t;
		i++;
		wrefresh(w);
	}
	fclose(f);
	position = fsize;
	char done = 0;
	while (done == 0)
	{
		t = getch();
		switch (t)
		{
			case 27:
				wprintw(w, "\n:");
				wrefresh(w);
				char cmd = '0';
				while (cmd != 'i' && done == 0)
				{
					display(s, position, filebuf);
					cmd = getch();
					switch (cmd)
					{
						case 'w':
							f = fopen(filename, "w");
							fwrite(filebuf, fsize, 1, f);
							fclose(f);
							break;
						case 'q':
							done = 1;
							break;
						case 'a':
							position --;
							if (position < 0)
								position++;
							break;
						case 'd':
							position++;
							if (position > fsize)
								position--;
							break;
						case 'e':
							position = fsize;
							break;
						case 'b':
							position = 0;
							break;
					}
				}
				break;
			case 127:
				if (fsize - 1 < 0)
					break;
				if (position == fsize)
				{
					fsize--;
					char *bktmp = NULL;//(char *)malloc(fsize + 2);
					while (bktmp == NULL)
					{
						bktmp = (char*)malloc(fsize + 2);
					}
					strncpy(bktmp, filebuf, fsize);
					free(filebuf);
					filebuf = bktmp;
				}
				else
				{
					filebuf[position] = ' ';
				}
				position--;
				break;
			default:
				position++;
				if (position > fsize)
				{
					fsize++;
					char *tmp = NULL;//(char *)malloc(fsize);
					while (tmp == NULL)
					{
						tmp = (char *)malloc(fsize);
					}
					strcpy(tmp, filebuf);
					free(filebuf);
					filebuf = tmp;
				}
				filebuf[position - 1] = t;
				break;
		}
		wclear(w);
		wrefresh(w);
		display(s, position, filebuf);
		for (i = 0; i < fsize; i++)
		{
			wprintw(w, "%c", filebuf[i]);
		}
		wrefresh(w);
	}
	endwin();
	fclose(f);
}
