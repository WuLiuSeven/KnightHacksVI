
// -  -
// ----
#include <stdio.h>

#define BOARD 9
int winDetected = 0;
int horizontalWin(char arr[3][3]) {
    int numRows = 3;
    int numCols = 3;
    int i = 0;
    int j = 0;

    for (i = 0; i < numRows; i++) {
        char temp = arr[i][0]; // Initialize temp with the first element of the row
        if (temp == ' ') {
            temp = 'N';
        }
        int consecutiveCount = 1;

        for (j = 1; j < numCols; j++) {
            if (temp == arr[i][j]) {
                consecutiveCount++;
            }
            else {
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
            }
            else {
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

int diagonalWin(char arr[3][3]) {
    char temp = arr[1][1]; //Initialize the mid piece
    if (temp == ' ') {
        temp = 'N';
    }
    int consecutiveCount = 1;
    if (arr[0][0] == temp && arr[2][2] == temp) {
        return 1;
    }
    else if (arr[2][0] == temp && arr[0][2] == temp) {
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

int checkWin(char board[3][3]) {
    if (horizontalWin(board) || verticalWin(board) || diagonalWin(board)) {
        return 1; // Return 1 to indicate a win
    }
    return 0; // No win yet
}
void permuteBoard(char board[3][3], int used[], int k, int n, int iterations)
{
    // Player turn and symbol
    char player;
    if (k % 2 == 0)
        player = 'X';
    else
        player = 'O';

    //IF GAME IS WON, RETURN
    if (checkWin(board)) {
        displayBoard(board); // Display the winning board
        printf("-------------------------------------------------\n");
        winDetected += 1;     // Set the flag to indicate a win
        iterations -= 1;
        return;              // Terminate the current call
    }
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
            permuteBoard(board, used, k + 1, n, iterations); // Recursively continue with the next player
            board[row][col] = ' '; // Clear the cell for the next process
            used[i] = 0;          // Unmark i for the next process
            if (winDetected == iterations) {
                return; // Terminate all levels of recursion if a win is detected
            }
        }
    }
}
int main() {
    char board[3][3] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };

    int currentPlayer = 0; // Player 0 (X) starts

    int gameOver = 0; // Flag to indicate whether the game is over

    int turn = 0; //Flag to see the turn
    int used[9] = { 0 }; // Initialize the used array for permutations
    int typeOfGame = 1;
    int continue1 = 1;
    int it = 0;
    while (continue1 != 0) {

        printf("Choose the type of game:\n");
        printf("1. Normal Tic-Tac-Toe\n");
        printf("2. Watch every possible game\n");
        scanf("%d", &typeOfGame);

        if (typeOfGame == 1) {

            while (!gameOver) {
                // Display the current state of the board
                displayBoard(board);

                // Get the current player's move
                int row, col;
                if (currentPlayer == 0) {
                    printf("Player %d (X) Enter your move (row and column): ", currentPlayer + 1);
                    scanf("%d %d", &row, &col);
                }
                else {
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
                turn += 1;
                if (turn >= 5 && horizontalWin(board) == 1) {
                    break;
                }
                else if (turn >= 5 && verticalWin(board) == 1) {
                    break;
                }
                else if (turn >= 5 && diagonalWin(board) == 1 && board[1][1] != ' ') {
                    break;
                }
                if (turn >= 9) {
                    gameOver += 1; // If the game is over, set gameOver to 1
                }
            }

            // Display the final state of the board and the game result
            displayBoard(board);
            // Print the result of the game (win, draw, or quit)

        }
        else if (typeOfGame == 2) {
            printf("Choose the number of wins to end the game:\n");
            scanf("%d", &it);
            winDetected = 0;
            permuteBoard(board, used, 0, 9, it); // Call the permuteBoard function for watching every possible game
        }
        else {
            printf("Invalid choice. Exiting.\n");
        }
        // Ask players if they want to play again
        printf("Want to play again?\n");
        printf("1. Yes\n");
        printf("0. No\n");
        scanf("%d", &continue1);
    }
    return 0;
}
