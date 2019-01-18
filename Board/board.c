#include "board.h"

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

Board * new_board(){
    Board * b = malloc(sizeof(Board));
    for(int i = 0; i<=9; i++){
        for(int j = 0; j<=9; j++){
            b->board[i][j] = '-';
        }
    }
    return b;
}

Boards * new_boards(){
    Boards * b = malloc(sizeof(Boards));

    b->mainBoard = new_board();
    b->markBoard = new_board();

    return b;
}

Box * new_box(char c, int i){
    Box * b = malloc(sizeof(Box));
    b -> abs = c;
    b -> ord = i;
    return b;
}

void set_case(Board* board, Box b, char car){
    int abss;
    switch (b.abs){
        case 'A':
            abss = 0;
            break;
        case 'B':
            abss = 1;
            break;
        case 'C':
            abss = 2;
            break;
        case 'D':
            abss = 3;
            break;
        case 'E':
            abss = 4;
            break;
        case 'F':
            abss = 5;
            break;
        case 'G':
            abss = 6;
            break;
        case 'H':
            abss = 7;
            break;
        case 'I':
            abss = 8;
            break;
        case 'J':
            abss = 9;
            break;
    }
    board->board[b.ord][abss] = car;
}



char get_case(char abs, int ord, Board b){
    int abss;
    abs = toupper(abs);
    switch (abs){
        case 'A':
            abss = 0;
            break;
        case 'B':
            abss = 1;
            break;
        case 'C':
            abss = 2;
            break;
        case 'D':
            abss = 3;
            break;
        case 'E':
            abss = 4;
            break;
        case 'F':
            abss = 5;
            break;
        case 'G':
            abss = 6;
            break;
        case 'H':
            abss = 7;
            break;
        case 'I':
            abss = 8;
            break;
        case 'J':
            abss = 9;
            break;
    }
    return b.board[ord][abss];
}

char get_case_from_box(Box box, Board board){
    return get_case(box.abs, box.ord, board);
}

void print_boards(Boards b){
    printf("\nMain Board               Mark Board\n");
    for(int i = 0; i<=9; i++){
        printf("%i ",i);
        for(int j = 0; j<=9; j++){
            printf("%c ",b.mainBoard->board[i][j]);
        }
        printf("   %i ",i);
        for(int j = 0; j<=9; j++){
            printf("%c ",b.markBoard->board[i][j]);
        }
        printf("\n");
    }
    printf("  A B C D E F G H I J      A B C D E F G H I J\n\n");
}

void print_board(Board* b){
    for(int i = 0; i<=9; i++){
        printf("%i ",i);
        for(int j = 0; j<=9; j++){
            printf("%c ",(*b).board[i][j]);
        }
        printf("\n");
    }
    printf("  A B C D E F G H I J \n");
}

int is_available(char val){
    if(val == '-'){
        return 1;
    }
    return 0;
}

int get_state(Box b, Board board){
    char value_on_board = get_case_from_box(b, board);
    int available = is_available(value_on_board);
    if(available == 1){
        return 0;
    }
    if(value_on_board == 'C' || value_on_board == 'B' || value_on_board == 'S' || value_on_board == 'D'){
        return 1;
    }
    else
    {
        return 0;
    }
}

int set_ship(Board* b, Ship s){
    printf("Place this boat\n");
    print_ship(s);
    char msg[256] = {'\0'};
    printf("Enter the initial box for the ship: ");
    fflush(stdout);
    scanf("%s", msg);
    Box my_placement_box;
    my_placement_box.abs = msg[0];
    my_placement_box.ord = msg[1]-'0';
    char dir[4] = {'/','/','/','/'};
    int nb_direction = 0;

    char c = get_case_from_box(my_placement_box, *b);
    if(c != '-'){
        printf("This case isn't available for place a ship. Try again please.\n");
        return 0;
    }
<<<<<<< HEAD
    char verif = 't';
    // WEST TEST
   if(my_placement_box.abs-s.lenght-'A'>0){
        printf("I'm testing the west direction.\n");
        for(int i = 0; i < s.lenght; i++){
            c = get_case(my_placement_box.abs - i, my_placement_box.ord, *b);
            if(c != '-'){
=======

    if( (my_placement_box.abs-'A')-s.lenght > 0){
        printf("testW ");
        int i = 0;
        char verif = 't';
        while(i < s.lenght){
            i++;
            Box placement_box = *new_box(my_placement_box.abs-i,my_placement_box.ord);
            char d = get_case_from_box(placement_box,*b);
            if(d != '-'){
>>>>>>> 5549d02ec6f1f462bcc359cf17eae3ca35942e14
                verif = 'f';
            }
        }

        if (verif == 't'){
            dir[0] = 'W';
            nb_direction += 1;
        }
<<<<<<< HEAD
   }

    // EAST TEST
    if(my_placement_box.abs-'A'+s.lenght<10){
        printf("I'm testing the east direction.\n");
        for(int i = 0; i < s.lenght; i++){
            c = get_case(my_placement_box.abs + i, my_placement_box.ord, *b);
=======
    }
    if((my_placement_box.abs-'A')+s.lenght <10){
        printf("testE ");
        int i = 0;
        char verif = 't';
        while(i < s.lenght){
            i++;
            char c = get_case(my_placement_box.abs+i,my_placement_box.ord,*b);
>>>>>>> 5549d02ec6f1f462bcc359cf17eae3ca35942e14
            if(c != '-'){
                verif = 'f';
            }
        }

        if (verif == 't'){
            dir[1] = 'E';
            nb_direction += 1;
        }
    }
<<<<<<< HEAD
    
    // NORTH TEST
    if(my_placement_box.ord-s.lenght>0){
        printf("I'm testing the north direction.\n");
        c = '-';
        verif = 't';
        for(int i = 0; i < s.lenght; i++){
            c = get_case(my_placement_box.abs, my_placement_box.ord - i, *b);
            if(c != '-'){
                verif = 'f';
            }
        }

        if (verif == 't'){
            dir[2] = 'N';
            nb_direction += 1;
        }
   }

    // SOUTH TEST
   if(my_placement_box.ord+s.lenght<10){
        printf("I'm testing the south direction.\n");
        c = '-';
        verif = 't';
        for(int i = 0; i < s.lenght; i++){
            c = get_case(my_placement_box.abs, my_placement_box.ord + i, *b);
=======
    if((my_placement_box.ord-s.lenght)>0){
        printf("testN ");
        int i = 0;
        char verif = 't';
        while(i < s.lenght){
            i++;
            char c = get_case(my_placement_box.abs,my_placement_box.ord-i,*b);
            if(c !='-'){
                verif = 'f';
            }
        }
        if (verif == 't'){
            dir[2]='N';
            nb_direction += 1;
        }
    }
    if((my_placement_box.ord+s.lenght)<10){
        printf("testS ");
        int i = 0;
        char verif = 't';
        while(i < s.lenght){
            i++;
            char c = get_case(my_placement_box.abs,my_placement_box.ord+i,*b);
>>>>>>> 5549d02ec6f1f462bcc359cf17eae3ca35942e14
            if(c != '-'){
                verif = 'f';
            }
        }

        if (verif == 't'){
            dir[3] = 'S';
            nb_direction += 1;
        }
   }

    char orient = '\0';
    int orient_choose = -1;
    if(nb_direction == 0){
        printf("no direction available. Please try another time.\n");
        return 0;
    }
<<<<<<< HEAD
  
    printf("there are %d directions available: ", nb_direction);
    for(int i = 0; i<4; i++){
        if(dir[i] != '/'){
            printf("%d: %c\t", i, dir[i]);
=======
    char verif = 'f';
    while(verif == 'f'){
        printf("there are %d directions available: ", nb_direction);
        for(int i = 0; i<4; i++){
           
                printf("%c\t", dir[i]);
            
>>>>>>> 5549d02ec6f1f462bcc359cf17eae3ca35942e14
        }
    }
    printf("\n");
    printf("please choose a direction: ");
    fflush(stdout);
    scanf("%d", &orient_choose);

    switch(orient_choose){
        case 0:
            orient = 'W';
            break;
        case 1:
            orient = 'E';
            break;
        case 2:
            orient = 'N';
            break;
        case 3:
            orient = 'S';
            break;
        default:
            printf("Your input is %d. So you don't choose an available direction. Try again.\n", orient_choose);
            return 0;
    }
    
    // on place deja le symbol sur la premiere case.
    set_case(b,my_placement_box,s.notHit);
    int i = 0;

    if(orient == 'W'){
        while(i < s.lenght-1){
            i++;
            my_placement_box.abs = my_placement_box.abs-1;
            set_case(b,my_placement_box,s.notHit);
        }
    } else if(orient == 'E'){
        while(i < s.lenght-1){
            i++;
            my_placement_box.abs = my_placement_box.abs+1;
            set_case(b,my_placement_box,s.notHit);
        }
    } else if(orient == 'N'){
        while(i < s.lenght-1){
            i++;
            my_placement_box.ord = my_placement_box.ord-1;
            set_case(b,my_placement_box,s.notHit);
        }
    } else if(orient == 'S'){
        while(i < s.lenght-1){
            i++;
            my_placement_box.ord = my_placement_box.ord+1;
            set_case(b,my_placement_box,s.notHit);
        }
    }
    return 1;
}

void print_box(Box* b){
    printf("%c%i", b->abs, b->ord);
}
