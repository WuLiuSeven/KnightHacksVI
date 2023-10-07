#include <stdio.h>
#include <stdlib.h>


#define BOARD 9

///////////////////////////////////////////////////////////

void printBoard(int b[])
{
    printf("%d %d %d\n", b[0], b[1], b[2]);
    printf("%d %d %d\n", b[3], b[4], b[5]);
    printf("%d %d %d\n", b[6], b[7], b[8]);
}

void permuteBoard(int b[], int turn, int useable)
{
    //Player turn and symbol
    int player;
    if(turn == 0)
        player = '1';
    else
        player = '2';
    
    //break Case
    if(useable == 0)
        //PRINT BOARD
        return 0;

    //Permute Check
    for(int i = 0; i < useable; i++)
    {
        int j = i;
        while(b[j] != 0)
            j++;

        b[j] = player;
        printBoard(b);
        permuteBoard(b, (turn + 1)%2, useable - 1);
        b[j] = 0;
    }

}

///////////////////////////////////////////////////////////

int main(void)
{
    int board[BOARD] = {0};

    permuteBoard(board, 0, BOARD);
}

///////////////////////////////////////////////////////////

