#include <conio.h>
#include "Utility.h"

void init(Board &board) {
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

void repeatString(std::string str, int times=7, std::string board[][9]=NULL, int row=0) {
    for (int i=0; i<times; i++) {
        if (board) {
            if (times != 7) 
                std::cout << str.substr(0, 1) << board[row][i] << str.substr(1);
            else 
                std::cout << str.substr(0, 1) << board[row][i+1] << str.substr(1);       
        } else
            std::cout << str;            
    }    
}

void printBoard(Board &board, int row, int col) {
    std::string newboard[9][9];
    for (int i=0; i<BOARDSIZE; i++)
        for (int j=0; j<BOARDSIZE; j++) 
            newboard[i][j] = board.board[i][j] == 0 ? " " : std::to_string(abs(board.board[i][j]));     

    if (row >= 0 && col >= 0)
        newboard[row][col] = "\e[101m" + newboard[row][col] + "\e[0m";

        
    /* 
        ┳ \u2533
        ┻ \u253b
        ┣ \u2523
        ┫ \u252b

        ┃ \u2503
        ━ \u2501

        ┏ \u250F
        ┓ \u2513
        ┗ \u2517
        ┛ \u251b

        ╋ \u254b
    */

    std::cout << "\u250f\u2501\u2501\u2501\u2533";
    repeatString("\u2501\u2501\u2501\u2533");
    std::cout << "\u2501\u2501\u2501\u2513";
    for (int i=0; i<8; i++) {
        std::cout << "\n\u2503";
        repeatString("  \u2503", 9, newboard, i);
        std::cout << "\n\u2523";
        repeatString("\u2501\u2501\u2501\u254b", 8);
        std::cout << "\u2501\u2501\u2501\u252b";
    }
    std::cout << "\n\u2503";
    repeatString("  \u2503", 9, newboard, 8);
    std::cout << "\n\u2517\u2501\u2501\u2501\u253b";
    repeatString("\u2501\u2501\u2501\u253b");
    std::cout << "\u2501\u2501\u2501\u251b";
}