#include <stdio.h>

#include <stdlib.h>

char Array[3][3];

char check(void);

void init_Array(void);

void get_player_move(void);

void get_computer_move(void);

void disp_Array(void);

int main(void)

{
           



    char done;
    printf("*****************************************\n");
    printf("This is the game of Tic Tac Toe.\n");
    printf("You will be playing against the computer.\n");
    printf("*****************************************\n");
    printf("\nWhat is your name ? \n");
    char str[20];
    printf("\n");
    gets(str);
    printf("\n\nHello %s ... Let's have fun!! You = O | Computer = X\n",str);
    printf("\n");
    done = ' ';

    init_Array();

    do
    {

        disp_Array();

        get_player_move();

        done = check(); /// see if winner

        if(done!= ' ') break; ///winner!

        get_computer_move();

        done = check(); ///see if winner

    }
    while(done== ' ');

    disp_Array(); ///show final positions
    if(done=='X')
        printf("You won :)\n");

    else
        printf("You Lose (:\n");


    return 0;

}

/// Initialize the Array.

void init_Array(void)

{

    int i, j;

    for(i=0; i<3; i++)

        for(j=0; j<3; j++) Array[i][j] = ' ';

}

/// Get a player's move.

void get_player_move(void)

{

    int x, y;

    printf("Enter X,Y coordinates for your move : ");

    scanf("%d%*c%d", &x, &y);

    x--;
    y--;

    if(Array[x][y]!= ' ')
    {

        printf("Invalid move, try again.\n");

        get_player_move();

    }

    else Array[x][y] = 'X';

}

/// Get a move from the computer.

void get_computer_move(void)

{

    int i, j;

    for(i=0; i<3; i++)
    {

        for(j=0; j<3; j++)

            if(Array[i][j]==' ') break;

        if(Array[i][j]==' ') break;

    }

    if(i*j==9)
    {

        printf("draw\n");

        exit(0);

    }

    else

        Array[i][j] = 'O';

}

/// Display the Array on the screen.

void disp_Array(void)

{

    int t;

    for(t=0; t<3; t++)
    {

        printf(" %c | %c | %c ",Array[t][0],

               Array[t][1], Array [t][2]);

        if(t!=2) printf("\n---|---|---\n");

    }

    printf("\n");

}

/// See if there is a winner.

char check(void)

{

    int i;

    for(i=0; i<3; i++) /// check rows

        if(Array[i][0]==Array[i][1] &&

                Array[i][0]==Array[i][2]) return Array[i][0];

    for(i=0; i<3; i++) /// check columns

        if(Array[0][i]==Array[1][i] &&

                Array[0][i]==Array[2][i]) return Array[0][i];

/// test diagonals

    if(Array[0][0]==Array[1][1] &&

            Array[1][1]==Array[2][2])

        return Array[0][0];

    if(Array[0][2]==Array[1][1] &&

            Array[1][1]==Array[2][0])

        return Array[0][2];

    return ' ';
}

