#include <iostream>
#include <utility>
#include <stdlib.h>
#include "Utility.h"

// Determine OS
#ifdef _WIN32  // If defined
    #define clear() (system("cls"))
#else
    #define clear() (system("clear"))
#endif

int main(int argc, char const *argv[])
{
    Board board;

    init(board);
    clear();   
    std::cout << "\n\n";
    printBoard(board, board.point.first, board.point.second);
    std::cout << "\n\n";

    return 1;
}

