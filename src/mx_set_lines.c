#include "../inc/header.h"

void mx_set_lines(t_line **lines, int row, int column) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++)
            (* lines)[i].str[j] = mx_random_char();
        (* lines)[i].length = rand() % column;
        (* lines)[i].first = 0 - (* lines)[i].length - (* lines)[i].length;
        (* lines)[i].last = 0 - (* lines)[i].length;
    }
}
