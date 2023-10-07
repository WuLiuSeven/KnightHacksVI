#include <stdio.h>
#include <stdlib.h>


#define BOARDX 3
#define BOARDY 3

int main(void)
{
    int **board = malloc(sizeof(int*) * BOARDY);
    for(int i = 0; i < BOARDY; i++)
    {
        board[i] = malloc(sizeof(int) * BOARDX);
        
    } 

    
}