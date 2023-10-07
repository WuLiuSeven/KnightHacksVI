
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BOARD 9
int horizontalWin(char arr[3][3]) {
    int numRows = 3;
    int numCols = 3;
	int i=0;
	int j=0;
    for (i = 0; i < numRows; i++) {
        char temp = arr[i][0]; // Initialize temp with the first element of the row
        if(temp == ' '){
        	temp='N';
		}
        int consecutiveCount = 1;

        for (j = 1; j < numCols; j++) {
            if (temp == arr[i][j]) {
                consecutiveCount++;
            } else {
                consecutiveCount = 1; // Reset count if symbols don't match
                temp = arr[i][j];    // Update temp for the next check
            }
        }

        if (consecutiveCount >= 3) {
            return 1; // Return 1 to indicate a win
        }
    }

    return 0; // No horizontal win
}

int verticalWin(char arr[3][3]) {
    int numRows = 3;
    int numCols = 3;
    int i, j;
    
    for (i = 0; i < numCols; i++) { // Iterate through columns
        char temp = arr[0][i]; // Initialize temp with the first element of the column
        if (temp == ' ') {
            temp = 'N';
        }
        int consecutiveCount = 1;

        for (j = 1; j < numRows; j++) { // Iterate through rows in the same column
            if (temp == arr[j][i]) { // Compare elements in the same column
                consecutiveCount++;
            } else {
                consecutiveCount = 1; // Reset count if symbols don't match
                temp = arr[j][i];    // Update temp for the next check
            }
        }

        if (consecutiveCount >= 3) {
            return 1; // Return 1 to indicate a win
        }
    }

    return 0; // No vertical win
}

int diagonalWin(char arr[3][3]){
	char temp = arr[1][1]; //Initialize the mid piece
	if (temp == ' ') {
            temp = 'N';
    }
	int consecutiveCount = 1;
	if(arr[0][0]==temp && arr[2][2]==temp){
		return 1;
	}else if(arr[2][0]==temp && arr[0][2]== temp){
		return 1;
	}
	return 0;
}

// Function to display the Tic-Tac-Toe board
void displayBoard(char board[3][3]) {
    printf("   0   1   2\n"); // Column indices
    int i;
    for (i = 0; i < 3; i++) {
        printf("%d ", i); // Row index
        int j;
        for (j = 0; j < 3; j++) {
            printf(" %c ", board[i][j]); // Display the cell
            if (j < 2) {
                printf("|"); // Separate cells with vertical bars
            }
        }
        printf("\n");
        if (i < 2) {
            printf("  ---|---|---\n"); // Separate rows with horizontal bars
        }
    }
    printf("\n");
}


void permuteBoard(char board[3][3], int used[], int k, int n)
{
    // Player turn and symbol
    char player;
    if (k % 2 == 0)
        player = 'X';
    else
        player = 'O';

    //IF GAME IS WON, RETURN
    //
    //
    //
    //CODE HERE
    //
    //

    // Iterate through the empty cells of the board
    int i;
    for (i = 0; i < n; i++)
    {
        if (!used[i]) // If cell i was not used
        {
            used[i] = 1;        // Mark that it is used
            int row = i / 3;    // Calculate the row index from i
            int col = i % 3;    // Calculate the column index from i
            board[row][col] = player; // Update the board with the player's symbol
            displayBoard(board);     // Display the current state of the board
            permuteBoard(board, used, k + 1, n); // Recursively continue with the next player
            board[row][col] = ' '; // Clear the cell for the next process
            used[i] = 0;          // Unmark i for the next process
        }
    }
}


/////////////////////////////////////////////////////////////////////////////////

int main()
{

    char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    int used[9] = {0}; // Initialize the used array for permutations
    permuteBoard(board, used, 0, 9); // Call the permuteBoard function for watching every possible game
   
}
