#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BOARD 9

int totalperm = 0;

///////////////////////////////////////////////////////////

void printBoard(int b[]) {
  printf("%d %d %d\n", b[0], b[1], b[2]);
  printf("%d %d %d\n", b[3], b[4], b[5]);
  printf("%d %d %d\n\n", b[6], b[7], b[8]);
}

int checkVictory(int board[]) 
{
    // Check rows
    for (int i = 0; i < 3; i++) 
	{
        if (board[i * 3] == board[i * 3 + 1] && board[i * 3 + 1] == board[i * 3 + 2] && board[i * 3] != 0) 
		{
            return board[i * 3]; // Return the player who won (1 or 2)
        }
    }

    // Check columns
    for (int i = 0; i < 3; i++) 
	{
        if (board[i] == board[i + 3] && board[i + 3] == board[i + 6] && board[i] != 0) 
		{
            return board[i]; // Return the player who won (1 or 2)
        }
    }

    // Check diagonals
    if ((board[0] == board[4] && board[4] == board[8] && board[0] != 0) ||
        (board[2] == board[4] && board[4] == board[6] && board[2] != 0)) 
	{
        return board[4]; // Return the player who won (1 or 2)
    }

    return 0; // No winner yet
}

void addTabs(int a, FILE ** fpointer)
{
	FILE *fp = *fpointer;
	for(int b = 0; b < a; b++)
		fprintf(fp, "\t");
}

void ifThing(FILE **fpointer)
{
	
}

void permuteBoard(int arr[], int used[], int k, int n, FILE**fpointer) 
{
	FILE *fp = *fpointer;
	
	//Test
	// char i = ' ';
	// scanf("%c", &i);
	
	// Player turn and symbol
	int player = (k % 2) + 1;
	
	if(checkVictory(arr) != 0)
	{
		int v = checkVictory(arr);
		addTabs(k + 1, &fp);
		fprintf(fp, "victory(%d);\n", v);
		return;
	}

	if(k == BOARD)
	{
		addTabs(k + 1, &fp);
		fprintf(fp, "fprintf(fp, \"\\n\\nTIE GAME\");\n");
		fprintf(fp, "exit(0);\n");
		return;
	}

	addTabs(k, &fp);
	fprintf(fp, "while (1 == 1)\n");
	addTabs(k, &fp);
	fprintf(fp, "{\n");
	
	// EVERY PERMUTATION OF TICTACTOE HAHAHAHA
	for (int i = 0; i < BOARD; i++) 
	{
		if (!used[i]) // if i was not usedw
		{
			used[i] = 1; // mark that it is used
			arr[i] = player;
			
			//printBoard(arr);
			int x = i % 3;
    		int y = i / 3;
				
			addTabs(k + 1, &fp);
			fprintf(fp, "if (next[%d] == 0 && next[%d] == 0) // INPUT\n", x, y);
			addTabs(k + 1, &fp);
			fprintf(fp, "{\n");

			//print array in fromat
			addTabs(k + 1, &fp);
			fprintf(fp, "int board[] = {%d, %d, %d, %d, %d, %d, %d, %d, %d};\n", arr[0], arr[1], arr[2], arr[3], arr[4], arr[5], arr[6], arr[7], arr[8]);
			addTabs(k + 1, &fp);
			fprintf(fp, "printBoard(board, 1);\n");
			
			totalperm++;
			permuteBoard(arr, used, k + 1, n, &fp);
			
			addTabs(k + 1, &fp);
			fprintf(fp, "}\n");
			
			arr[i] = 0;
			used[i] = 0; // unmark i for next process
		}
	}

	addTabs(k + 1, &fp);
	fprintf(fp, "fprintf(fp, \"Invalid move, please try again:\\n\");\n");
	
	addTabs(k, &fp);
	fprintf(fp, "}\n");

}

void fileInit(FILE **fpointer)
{
	//I used a program to crate this please do not warry for my sanity
	FILE *fp = *fpointer;
	
	fprintf(fp, "#include <stdio.h>\n");
	fprintf(fp, "#include <stdlib.h>\n");
	fprintf(fp, "#include <string.h>\n\n");

	fprintf(fp, "void printBoard(int board[], int p)\n");
	fprintf(fp, "{\n");
	fprintf(fp, "\tchar b[9];\n");
	fprintf(fp, "\tfor(int i = 0; i < 9; i++)\n");
	fprintf(fp, "\t{\n");
	fprintf(fp, "\t\tchar player = ' ';\n");
	fprintf(fp, "\t\tif(board[i] == 1)\n");
	fprintf(fp, "\t\t\tplayer = 'X';\n");
	fprintf(fp, "\t\telse if(board[i] == 2)\n");
	fprintf(fp, "\t\t\tplayer = 'O';\n");
	fprintf(fp, "\n");
	fprintf(fp, "\t\tb[i] = player;\n");
	fprintf(fp, "\t}\n");
	fprintf(fp, "\tprintf(\"\\n\");\n");
	fprintf(fp, "\tprintf(\"\\t0   1   2\\n\\n\");\n");
	fprintf(fp, "\tprintf(\"0\\t%%c | %%c | %%c\\n\", b[0], b[1], b[2]);\n");
	fprintf(fp, "\tprintf(\"\\t--|---|--\\n\");\n");
	fprintf(fp, "\tprintf(\"1\\t%%c | %%c | %%c\\n\", b[3], b[4], b[5]);\n");
	fprintf(fp, "\tprintf(\"\\t--|---|--\\n\");\n");
	fprintf(fp, "\tprintf(\"2\\t%%c | %%c | %%c\\n\\n\", b[6], b[7], b[8]);\n");
	fprintf(fp, "\n");
	fprintf(fp, "\t// Whose player turn it is\n");
	fprintf(fp, "\tchar player = 'X';\n");
	fprintf(fp, "\tif(p == 1)\n");
	fprintf(fp, "\t\tplayer = 'O';\n");
	fprintf(fp, "\n");
	fprintf(fp, "\tprintf(\"Player '%%c', make a move (x y):\\n\", player);\n");
	fprintf(fp, "}\n\n");

	fprintf(fp, "void victory(int p)\n");
	fprintf(fp, "{\n");
	fprintf(fp, "\tchar player = 'X';\n");
	fprintf(fp, "\tif(p == 1)\n");
	fprintf(fp, "\t\tplayer = 'O';\n");
	fprintf(fp, "\n");
	fprintf(fp, "\tprintf(\"\\n\\nPLAYER '%%c' WINS!\", player);\n");
	fprintf(fp, "\texit(0);\n");
	fprintf(fp, "}\n\n");

	fprintf(fp, "int main(void)\n");
	fprintf(fp, "{\n");
	fprintf(fp, "\tint board[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};\n");
	fprintf(fp, "\tprintBoard(board, 0);\n");
	fprintf(fp, "\tint next[2];\n");

}
///////////////////////////////////////////////////////////

int main(void) 
{
	FILE *fp = fopen("TicTacToe.c", "w");
	fileInit(&fp);
	
	int board[BOARD] = {0}, used[BOARD] = {0};
	permuteBoard(board, used, 0, BOARD, &fp);

	printf("%d",totalperm);
}

///////////////////////////////////////////////////////////
