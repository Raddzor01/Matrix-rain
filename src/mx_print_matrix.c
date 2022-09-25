#include "../inc/header.h"
 
void mx_print_matrix(WINDOW *win, int row, int column) {
    init_pair(1, COLOR_GREEN, COLOR_BLACK);

	int pause = 250000;
    if (column > 16 && row > 32) {
        int x = column / 8;
        int y = row / 64;

        usleep(pause);

        char first[] = "Wake up , Neo..";
        char second[] = "The Matrix has you..";
        char third[] = "Follow the white rabbit";
        char fourth[] = "Knock, knock, Neo";

        wclear(win);

        for (int index = 0; index < 15; index++) {
            mvwaddch(win, y, x + index, first[index] | COLOR_PAIR(1));
            refresh();
            wtimeout(win, 60/1700000);
            usleep(pause);
        }

        wclear(win);

        for (int index = 0; index < 20; index++) {
            mvwaddch(win, y, x + index, second[index] | COLOR_PAIR(1));
            refresh();
            wtimeout(win, 60/1700000);
            usleep(pause);
        }

        wclear(win);

        for (int index = 0; index < 23; index++) {
            mvwaddch(win, y, x + index, third[index] | COLOR_PAIR(1));
            refresh();
            wtimeout(win, 60/1700000);
            usleep(pause);
        }

        wclear(win);

        for (int index = 0; index < 17; index++) {
            mvwaddch(win, y, x + index, fourth[index]);
            refresh();
            wtimeout(win, 60/1700000);
            usleep(pause);
        }
    }
}
