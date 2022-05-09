#include <iostream>
#include <utility>
#include <stdlib.h>
#include "Utility.h"

int main(int argc, char const *argv[])
{
    Board board;
    int key;

    init(board);  
    while (key != KEY_ENTER) {
        printBoard(board, board.point.first, board.point.second);
        key = getKey();
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
            case KEY_ENTER:
                printBoard(board, board.point.first, board.point.second, true);
                
                break;
        }
    }
    std::cout << "Enter Num: ";
    int c;
    c = getValue();
    std::cout << (int)c << std::endl;
    std::cout << (int)c << std::endl;
    

    return 1;
}

