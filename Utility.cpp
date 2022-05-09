#include <conio.h>
#include "Utility.h"

#ifdef _WIN32
    int getKey() {
        int first = getch();
        if (first == 10)
            return first;
        int a = getch();
        return a;
    }
#else
    int getKey() {
        int first = getch();
        if (first == 10)
            return first;
        getch();
        int a = getch();
        return a;
    }
#endif

std::string newboard[9][9];

void init(Board &board) {
    board.point.first = 0;
    board.point.second = 0;
    for (int i=0; i<BOARDSIZE; i++) {
        for (int j=0; j<BOARDSIZE; j++)
            board.board[i][j] = 0;
    }

    for (int i=0; i<BOARDSIZE; i++)
        for (int j=0; j<BOARDSIZE; j++) 
            newboard[i][j] = board.board[i][j] == 0 ? " " : std::to_string(abs(board.board[i][j]));
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

void printBoard(Board &board, int row, int col, bool selected) {

    newboard[row][col] = board.board[row][col] == 0 ? " " : std::to_string(abs(board.board[row][col]));

    if (row >= 0 && col >= 0) {
        if (board.board[row][col] < 0)
            newboard[row][col] = "\e[101;90m" + newboard[row][col] + "\e[0m";     
        else if (selected)
            newboard[row][col] = "\e[45;90m" + newboard[row][col] + "\e[0m";    
        else
            newboard[row][col] = "\e[102m" + newboard[row][col] + "\e[0m";    
    }

    clear();
    std::cout << "\n\n";
 
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

    newboard[row][col] = board.board[row][col] == 0 ? " " : std::to_string(abs(board.board[row][col]));
    std::cout << "\n\n";
}

int getValue() {
    char c = getch();
    int x = (int)c -'0';
    return x <= 9 ? x : 0;
}