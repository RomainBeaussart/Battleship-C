#include "ship.h"

#include <stdio.h>
#include <stdlib.h>



Ship new_carrier()
{
    Ship myCarrier = {
        .type = CARRIER,
        .lenght = 5,
        .hit = 'c',
        .notHit = 'C',
        .life = 5
    };
    return myCarrier;
}

Ship new_battleship()
{
    Ship myBattleship = {
        .type = BATTLESHIP,
        .lenght = 4,
        .hit = 'b',
        .notHit = 'B',
        .life = 4
    };
    return myBattleship; 
}

Ship new_submarine()
{
    Ship mySubmarine = {
        .type = SUBMARINE,
        .lenght = 3,
        .hit = 's',
        .notHit = 'S',
        .life = 3
    };
    return mySubmarine;
}

Ship new_destroyer()
{
    Ship myDestroyer = {
        .type = DESTROYER,
        .lenght = 2,
        .hit = 'd',
        .notHit = 'D',
        .life = 2
    };
    return myDestroyer;
}

void print_ship(Ship s){
    printf("The ship has :\n    type: %d    Lenght: %d      hit symbol: %c      not hit symbol: %c\n", s.type, s.lenght, s.hit, s.notHit);
}

char * get_ship_type(Ship s){
    switch(s.type){
        case CARRIER:
            return "Carrier";
        case BATTLESHIP:
            return "Battleship";
        case SUBMARINE:
            return "Submarine";
        case DESTROYER:
            return "Destroyer";
    }
    return "[error: get_ship_type()]";
}
