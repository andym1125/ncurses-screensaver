#include <stdio.h>
#include <ncurses.h>
#include<unistd.h>

unsigned int second = 1000000;
int frame_period = second / 60;

int main()
{
	initscr();
	curs_set(0);

	printw("Hello World !!!");
	refresh();

	int winh = 15, winw = 50, winsx = 0, winsy = 0;
	WINDOW* mywin = newwin(winh, winw, winsy, winsx);
	box(mywin, '|', '-');

	int x = 1, y = 1, dx = -1, dy = -1;
	while(true)
	{
		mvwprintw(mywin, y, x, " ");
		if(y == winsy+1 || y == winsy+winh-2)
			dy = -dy;
		if(x == winsx+1 || x == winsx+winw-2)
			dx = -dx;

		

		x += dx;
		y += dy;

		if(
			(y == winsy+1 || y == winsy+winh-2) &&
			(x == winsx+1 || x == winsx+winw-2)
		)
			mvwprintw(mywin, 0, 6, "You Win!!!!!");

		mvwprintw(mywin, y, x, "D");
		wrefresh(mywin);

		usleep(frame_period);
	}

	
	

	getch();

	endwin();
	return 0;
}