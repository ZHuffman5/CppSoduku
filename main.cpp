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


    std::cout << board.point.first;
    std::cout << board.board[0][0] << std::endl;


    return 0;
}

