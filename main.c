#include <stdio.h>
#include <stdlib.h>


#define BOARDX 3
#define BOARDY 3

<<<<<<< Updated upstream
=======
// 0 = nothing, 1 = x, 2 = O
///////////////////////////////////////////////////////////

void printBoard(int **board)
{
    //column
    for(int i = 0; i < BOARDX; i++)
    {
        //row
        for (int j = 0; j < BOARDY; j++) 
        {
            if board

            printf("\n");
        }
    } 
}

int** permuteBoard(int **b, int pos[])
{
    
}

///////////////////////////////////////////////////////////

>>>>>>> Stashed changes
int main(void)
{
    int **board = malloc(sizeof(int*) * BOARDY);
    for(int i = 0; i < BOARDY; i++)
    {
        board[i] = malloc(sizeof(int) * BOARDX);
        
    } 

    
}