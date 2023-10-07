
// -  -
// ----
#include <stdio.h>

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

int main() {
    char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    
    int currentPlayer = 0; // Player 0 (X) starts
    
    int gameOver = 0; // Flag to indicate whether the game is over
    
    int turn=0; //Flag to see the turn
    while (!gameOver) {
        // Display the current state of the board
        displayBoard(board);
        
        // Get the current player's move
        int row, col;
        if(currentPlayer==0){
        	printf("Player %d (X) Enter your move (row and column): ", currentPlayer + 1);
        	scanf("%d %d", &row, &col);
    	}else{
    		printf("Player %d (O) Enter your move (row and column): ", currentPlayer + 1);
        	scanf("%d %d", &row, &col);
		}
        
        // Check if the move is valid
        if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ') {
            printf("Invalid move. Try again.\n");
            continue; // Go back to the start of the loop
        }
        
        // Update the board with the player's move
        board[row][col] = (currentPlayer == 0) ? 'X' : 'O';
        
        // Switch to the next player
        currentPlayer = 1 - currentPlayer;
        // Check for a win or a draw (you can implement this logic in a separate function)
        turn+=1;
        if(turn>=5 && horizontalWin(board)==1){
        	break;
		}else if(turn>=5 && verticalWin(board)==1){
        	break;
		}else if(turn>=5 && diagonalWin(board)==1 && board[1][1]!=' '){
			break;
		}
		if(turn>=9){
        	gameOver+=1; // If the game is over, set gameOver to 1
		}
    }
    
    // Display the final state of the board and the game result
    displayBoard(board);
    // Print the result of the game (win, draw, or quit)
    // Ask players if they want to play again
    
    return 0;
}

