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
         else if (ch >= '0' && ch <= '9') {
            if (input.length() < 3) {
                input += static_cast<char>(ch);
                mvprintw(y, x, "%s", input.c_str());
                refresh();
            }
        }
    }
}
void petunjukPermainan() {
    tampilkanJudul();

    attron(COLOR_PAIR(2) | A_BOLD);
    mvprintw(9, 12, "PETUNJUK");
    attroff(COLOR_PAIR(2) | A_BOLD);

    mvprintw(11, 10, "1. Komputer akan memilih angka rahasia 1 sampai 100.");
    mvprintw(12, 10, "2. Masukkan angka tebakan kamu lalu tekan ENTER.");
    mvprintw(13, 10, "3. Perhatikan petunjuk terlalu besar atau terlalu kecil.");
    mvprintw(14, 10, "4. Setelah menang, kamu bisa memilih main lagi (y/n).");

    mvprintw(17, 10, "Tekan tombol apa saja untuk kembali ke menu.");
    refresh();

    getch();
}
void mulaiPermainan() {
    char ulang;

    do {
        int angkaRahasia = rand() % 100 + 1;
        int tebakan;
        int percobaan = 0;

        // Perulangan selama tebakan belum benar
        do {
            tampilkanJudul();

            mvprintw(9, 10, "Percobaan ke-%d", percobaan + 1);
            mvprintw(11, 10, "Masukkan tebakan kamu: ");
            tebakan = inputAngka(11, 34);

            percobaan++;

            // Percabangan untuk memeriksa tebakan
            if (tebakan > angkaRahasia) {
                attron(COLOR_PAIR(3) | A_BOLD);
                mvprintw(14, 10, "Terlalu besar! Coba lagi.");
                attroff(COLOR_PAIR(3) | A_BOLD);
                mvprintw(16, 10, "Tekan tombol apa saja untuk lanjut...");
                refresh();
                getch();
            }
            else if (tebakan < angkaRahasia) {
                attron(COLOR_PAIR(3) | A_BOLD);
                mvprintw(14, 10, "Terlalu kecil! Coba lagi.");
                attroff(COLOR_PAIR(3) | A_BOLD);
                mvprintw(16, 10, "Tekan tombol apa saja untuk lanjut...");
                refresh();
                getch();
            }
            else {
                tampilkanJudul();
                attron(COLOR_PAIR(2) | A_BOLD);
                mvprintw(9, 10, "SELAMAT! Tebakan kamu benar!");
                attroff(COLOR_PAIR(2) | A_BOLD);
                mvprintw(11, 10, "Angka rahasianya adalah: %d", angkaRahasia);
                mvprintw(12, 10, "Jumlah percobaan: %d", percobaan);
                refresh();
            }

        } while (tebakan != angkaRahasia);

        mvprintw(15, 10, "Apakah ingin bermain lagi? (y/n): ");
        refresh();

        while (true) {
            ulang = getch();
            if (ulang == 'y' || ulang == 'Y' || ulang == 'n' || ulang == 'N') {
                mvprintw(15, 44, "%c", ulang);
                refresh();
                break;
            }
        }

    } while (ulang == 'y' || ulang == 'Y');
}