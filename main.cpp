#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <ncurses/ncurses.h>

using namespace std;

void tampilkanJudul() {
    clear();

    attron(COLOR_PAIR(1) | A_BOLD);
    mvprintw(2, 10, "===================================");
    mvprintw(3, 10, "         GAME TEBAK ANGKA       ");
    mvprintw(4, 10, "===================================");
    attroff(COLOR_PAIR(1) | A_BOLD);

    mvprintw(6, 15, "Tebak angka dari 1 sampai 100!");
    refresh();
}
int inputAngka(int y, int x){
    string input = "";
    int ch;

    move(y, x);
    clrtoeol();
    refresh();

    while (true) {
        ch = getch();

        if (ch == '\n' || ch == KEY_ENTER) {
            if (!input.empty()) {
              return stoi(input);  
            }
        }
        else if (ch == KEY_BACKSPACE || ch == 127 || ch == '\b') {
            if (!input.empty()) {
                input.pop_back();
                mvprintw(y, x, "%-5s", input.c_str());
                move(y, x + input.length());
                refresh();
            }
        }
        }
    }
