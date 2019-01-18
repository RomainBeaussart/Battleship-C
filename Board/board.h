#ifndef _BOARD_H
#define _BOARD_H

#include "../Ship/ship.h"

/*

Board elements description:
'-' = the case is FREE
'X' = the case has been hitted

*/

typedef struct Board Board;
struct Board{
    char board[10][10];
};

typedef struct Boards Boards;
struct Boards{
    Board * mainBoard;
    Board * markBoard;
};

typedef struct Box Box;
struct Box{
    char abs;
    int ord;
};

Board * new_board();
Boards * new_boards();
void print_board(Board* b);
void print_boards(Boards b);
void print_box(Box* box);
int get_state(Box b, Board board);
char get_case_from_box(Box box, Board board);
void set_case(Board* board, Box b, char car);
int set_ship(Board* b, Ship s);

#endif