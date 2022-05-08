#include <iostream>
#include <utility>
#include <stdlib.h>
#include "Utility.h"

int main(int argc, char const *argv[])
{
    Board board;
    int key;

    init(board);  
    while (key != 10) {
        clear();
        std::cout << "\n\n";
        printBoard(board, board.point.first, board.point.second);
        std::cout << "\n\n";
        key = getArrowKey();
        switch(key) {
            case KEY_UP:
                board.point.first -= board.point.first == 0 ? 0 : 1;
                break;
            case KEY_DOWN:
                board.point.first += board.point.first == BOARDSIZE-1 ? 0 : 1;
                break;
            case KEY_LEFT:
                board.point.second -= board.point.second == 0 ? 0 : 1;
                break;
            case KEY_RIGHT:
                board.point.second += board.point.second == BOARDSIZE-1 ? 0 : 1;
                break;
        }
    }
    
    

    return 1;
}

