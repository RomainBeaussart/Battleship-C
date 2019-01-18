#ifndef _SHIP_H
#define _SHIP_H
enum type_of_ship {CARRIER = 0, BATTLESHIP = 1, SUBMARINE = 2, DESTROYER = 3, INVALID = 4};

typedef struct Ship Ship;
struct Ship{
    int lenght;
    char notHit;
    char hit;
    int type;
    int life;
};

void print_ship(Ship s);
char * get_ship_type(Ship s);
Ship new_destroyer();
Ship new_submarine();
Ship new_battleship();
Ship new_carrier();

#endif