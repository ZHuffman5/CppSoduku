#include <iostream>
#include <utility>
#include <stdlib.h>
#include "Utility.h"

int main(int argc, char const *argv[])
{
    Board board;
    int key;

    init(board);  
    while (true) {
        short &boardX = board.point.first;
        short &boardY = board.point.second;
        printBoard(board, boardX, boardY);
        key = getKey();
        switch(key) {
            case KEY_UP:
                boardX -= boardX == 0 ? 0 : 1;
                break;
            case KEY_DOWN:
                boardX += boardX == BOARDSIZE-1 ? 0 : 1;
                break;
            case KEY_LEFT:
                boardY -= boardY == 0 ? 0 : 1;
                break;
            case KEY_RIGHT:
                boardY += boardY == BOARDSIZE-1 ? 0 : 1;
                break;
            case KEY_ENTER:
                int val = 0;
                do {
                    printBoard(board, boardX, boardY, true);
                    std::cout << "Enter Num: ";
                    val = getValue();
                    short &temp = board.board[boardX][boardY];
                    temp = val == KEY_ENTER ? temp : (short)val;
                } while (val != KEY_ENTER);
                break;
        }
    }
    
    
    

    return 1;
}

