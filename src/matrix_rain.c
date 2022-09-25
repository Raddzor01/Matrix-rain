#include "../inc/header.h"

int main (int argc, char *argv[]) {
    setlocale(LC_ALL, "");
    WINDOW *win = initscr();
    int color_pair = 1;
    int row;
    int column;
    int speed = 10;
	getmaxyx(win, column, row);
    t_line *lines = (t_line *)malloc(sizeof(t_line) * row);

    for (int i = 0; i < row; i++) {
        lines[i].str = (wchar_t *)malloc(sizeof(wchar_t) * column);
	}    
	mx_set_lines(&lines, row, column);
    start_color();
	init_pair(1, COLOR_GREEN, COLOR_BLACK);
    init_pair(2, COLOR_WHITE, COLOR_BLACK);
    init_pair(3, COLOR_BLUE, COLOR_BLACK);
    init_pair(4, COLOR_YELLOW, COLOR_BLACK);
    init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(6, COLOR_RED, COLOR_BLACK);
    init_pair (7, COLOR_CYAN, COLOR_BLACK);
	wbkgd(win, COLOR_PAIR(color_pair));
    curs_set(false);
    noecho();
    if (argc != 2 || (argc == 2 && mx_strcmp(argv[1], "-s") != 0))
		mx_print_matrix(win, row, column);
    wclear(win);
	while (true) {
        wtimeout(win, 60 / speed * 10);
		switch(getch()) {
			case '+':
				speed -= 10;
				break;
			case '-':
				speed += 10;
				break;
			case 'q':
				exit(0);
        }
        wclear(win);
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {
                if (j >= lines[i].first && j <= lines[i].last) {
                    if(j == lines[i].last) {
						attroff(COLOR_PAIR(color_pair));
						attron(COLOR_PAIR(2));
                    }
                    mvprintw(j, i * 2, "%lc", lines[i].str[j]);
                    if(j == lines[i].last) {
        				attroff(COLOR_PAIR(2));
						attron(COLOR_PAIR(color_pair));
                    }
                    if (j == lines[i].first)
                        lines[i].str[j] = mx_random_char();
                    if (j == lines[i].last)
                        lines[i].str[j] = mx_random_char();
                }
            }
            lines[i].first++;
            lines[i].last++;
            if(lines[i].first > column) {
                lines[i].length = rand() % column;
                lines[i].first = 0 - lines[i].length - lines[i].length;
                lines[i].last = 0 - lines[i].length;
            }
        }
        refresh();
        color_pair++;
            if (color_pair > 7)
                color_pair = 1;
    }
    
	delwin(win);
    endwin();
	for(int i = 0; i < column; i++) {
		free(lines[i].str);
        lines[i].str = NULL;
    }
	free(lines);
	lines = NULL;
    return 0;
}
