#include <iostream>

#define BOARDSIZE 9

enum arrowKey { KEY_UP = 65, KEY_DOWN = 66, KEY_LEFT = 68, KEY_RIGHT = 67 };

typedef struct {
    // point == board[first][second]
    std::pair<short, short> point;
    short board[BOARDSIZE][BOARDSIZE];

} Board;

int getArrowKey();
void init(Board&);
void printBoard(Board&, int=-1, int=-1);
