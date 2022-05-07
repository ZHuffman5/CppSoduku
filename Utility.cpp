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