#pragma once

#include <ncurses.h>
#include <unistd.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

typedef struct s_line {
    wchar_t *str;
    int length;
    int first;
    int last;
}   t_line;

void mx_set_lines(t_line **lines, int row, int column);
void mx_set_color(char c, int *color_pair);
void mx_set_speed(char ch, int *pvar);
wchar_t mx_random_char();
void mx_print_matrix(WINDOW *win, int row, int column);
int mx_strcmp(const char *s1, const char *s2);

