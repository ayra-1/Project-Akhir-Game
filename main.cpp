#include <iostream>
#include <ncurses.h>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {

    int angkaRahasia;
    int tebakan;
    int percobaan = 0;
    char ulang;

    srand(time(0));

    do {
        // Menentukan angka secara acak
        angkaRahasia = rand() % 100 + 1;

        percobaan = 0;

        cout << "============================" << endl;
        cout << "      GAME TEBAK ANGKA      " << endl;
        cout << "============================" << endl;

        cout << "Tebak angka dari 1 sampai 100!" << endl;