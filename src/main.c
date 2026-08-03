#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>

int main() {
    initscr();

    printw("ncdm");

    refresh();
    getch();
    endwin();

    return 0;
}
