#include <conio.h>
#include "Utility.h"

void init(Board &board) {
    short (*data)[] = board.board;
    for (int i=0; i<BOARDSIZE; i++) {
        for (int j=0; j<BOARDSIZE; j++)
            board.board[i][j] = 0;
    }
}

int getArrowKey() {
    getch();
    getch();
    int a = getch();
    return a;
}

void printMenu(int active=-1) {
    std::string TRC = "\u250f";
    TRC = "\e[91m" + TRC + "\e[0m";
    std::cout << TRC << "\u2501\u2501\u2501\u2533    \n";
    std::cout << "\u2503 x \u2503\n";
}