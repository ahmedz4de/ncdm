#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ncurses.h>

WINDOW *create_centered_window(int height, int width);

int main(int argc, char *argv[]) {

    char hostname[64];
    gethostname(hostname, sizeof(hostname));
    char msg0[] = "session: tty";
    char msg1[] = "username: ";
    char user[64];
    int userX, userY;
    char msg2[] = "password: ";
    char pass[64];
    int passX, passY;

    initscr();

    int cols, rows;
    getmaxyx(stdscr, cols, rows);

    WINDOW *win = create_centered_window(12, 64);
    box(win, 0, 0);

    mvwprintw(win, 0, 2, "%s", hostname);
    mvwprintw(win, 3, 2, "%s", msg0);
    mvwprintw(win, 6, 2, "%s", msg1);
    getyx(win, userY, userX);
    mvwprintw(win, 9, 2, "%s", msg2);
    getyx(win, userY, userX);

    mvwgetstr(win, 6, 12, user);
    noecho();
    mvwgetstr(win, 9, 12, pass);

    endwin();

    return 0;
}

WINDOW *create_centered_window(int height, int width) {
    int rows, cols;
    getmaxyx(stdscr, rows, cols);

    int starty = (rows - height) / 2;
    int startx = (cols - width) / 2;

    return newwin(height, width, starty, startx);
}
