#include <stdio.h>
#include <stdlib.h>


#define BOARDX 3
#define BOARDY 3

///////////////////////////////////////////////////////////

void printBoard(int **board)
{
    for(int i = 0; i < BOARDY; i++)
    {
        for(int j = 0; j < BOARDX; j++)
            printf("%d ", board[i][j]);

        printf("\n");
    } 
}

int** permuteBoard(int **b, int pos[])
{
    
}

///////////////////////////////////////////////////////////

int main(void)
{
    int **board = malloc(sizeof(int*) * BOARDY);
    for(int i = 0; i < BOARDY; i++)
    {
        board[i] = malloc(sizeof(int) * BOARDX);
        
        for(int j = 0; j < BOARDX; j++)
            board[i][j] = 0;
    } 

    int pos[2] = {0}
    permuteBoard(board, pos);
}

///////////////////////////////////////////////////////////

