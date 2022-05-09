#include <iostream>

#define BOARDSIZE 9

// Determine OS
#ifdef _WIN32  // If defined
    #define clear() (system("cls"))
    enum arrowKey { KEY_UP = 72, KEY_DOWN = 80, KEY_LEFT = 75, KEY_RIGHT = 77, KEY_ENTER = 10 };
#else
    #define clear() (system("clear"))
    enum arrowKey { KEY_UP = 65, KEY_DOWN = 66, KEY_LEFT = 68, KEY_RIGHT = 67, KEY_ENTER = 10 };
#endif

typedef struct {
    // point == board[first][second]
    std::pair<short, short> point;
    short board[BOARDSIZE][BOARDSIZE];

} Board;

int getKey();
void init(Board&);
void printBoard(Board&, int=-1, int=-1, bool=false);
int getValue();