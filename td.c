#include <curses.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char * * argv)
{
	if (argc < 2)
		exit(-1);
	FILE *f;
	char t;
	char *filebuf;
	char *filename = argv[1];
	f = fopen(filename, "r");
	int i, fsize;
	i = fsize = 0;
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
	w = newwin(LINES, COLS, 0, 0);
	while (fscanf(f, "%c", &t) != EOF & i < fsize)
	{
		wprintw(w, "%c", t);
		filebuf[i] = t;
		i++;
		wrefresh(w);
	}
	fclose(f);
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
						//case 'o':
						
					}
				}
				break;
			case 127:
				if (fsize - 1 < 0)
					break;
				fsize--;
				char *bktmp = (char *)malloc(fsize + 2);
				strncpy(bktmp, filebuf, fsize);
				free(filebuf);
				filebuf = bktmp;
				break;
			default:
				fsize++;
				char *tmp = (char *)malloc(fsize);
				strcpy(tmp, filebuf);
				free(filebuf);
				filebuf = tmp;
				filebuf[fsize - 1] = t;
				break;
		}
		wclear(w);
		wrefresh(w);
		for (i = 0; i < fsize; i++)
		{
			wprintw(w, "%c", filebuf[i]);
		}
		wrefresh(w);
	}
	endwin();
	fclose(f);
}
