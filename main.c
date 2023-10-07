#include <stdio.h>
#include <stdlib.h>


#define BOARD 9

///////////////////////////////////////////////////////////

void printBoard(int b[])
{
    printf("%d %d %d\n", b[0], b[1], b[2]);
    printf("%d %d %d\n", b[3], b[4], b[5]);
    printf("%d %d %d\n\n", b[6], b[7], b[8]);
}

void permuteBoard(int arr[], int used[], int k, int n)
{
	//Test
	char r = ' ';
	scanf("%c", &r);
	
    //Player turn and symbol
    int player;
    if(k % 2 == 0)
        player = 1;
    else
        player = 2;

	//EVERY PERMUTATION OF TICTACTOE HAHAHAHA
	for(int i=0; i<n; i++)
	{
		if(!used[i]) //if i was not used
		{
			used[i] = 1; //mark that it is used
			arr[i] = player;
			printBoard(arr);
			permuteBoard(arr, used, k+1, n); //increase k and grow further
			arr[i] = 0;
			used[i] = 0; //unmark i for next process
		}
	}
	

}

///////////////////////////////////////////////////////////

int main(void)
{
    int board[BOARD] = {0}, used[BOARD] = {0};

    permuteBoard(board, used, 0, BOARD);
}

///////////////////////////////////////////////////////////

