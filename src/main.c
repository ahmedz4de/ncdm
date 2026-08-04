#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ncurses.h>

int main() {
    char msg1[] = "username: ";
    char user[64];
    int userX, userY;
    char msg2[] = "password: ";
    char pass[64];
    int passX, passY;
    int rows, cols;

    initscr();
    getmaxyx(stdscr, rows, cols);

    mvprintw(rows/2-1, (cols-10-strlen(msg1))/2, "%s", msg1);
    getyx(stdscr, userY, userX);
    mvprintw(rows/2+1, (cols-10-strlen(msg2))/2, "%s", msg2);
    getyx(stdscr, passY, passX);

    move(userY, userX);
    getstr(user);
    move(passY, passX);
    getstr(pass);

    refresh();

    endwin();

    return 0;
}
