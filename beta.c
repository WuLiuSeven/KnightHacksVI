#include <stdio.h>

/*int horizontalWin(char arr[3][3]){
	int i=0;
	int j=0;
	int numRows = 3;
	int numCols = 3;
	static char temp;
	int res=0;
	for(i=0; i<numRows; i++){
		for(j=0; j<numCols; j++){
			if(j==0){
				temp= arr[i][j];
			}
			if(temp==arr[i][j]){
				res+=1;
			}
		}
		if(res==2){
			if(temp !=' '){
				return res;
			}
		}
		res=0;
	}
	return 0;
	
} */
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
        //if(horizontalWin(board[3][3])==2){
        //	printf("wins");
        //	break;
		//}
        turn+=1;
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

