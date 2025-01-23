#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#define ROWS 6
#define COLS 7

void createBoard(char board[ROWS][COLS])
{
    for (int i = 0; i<ROWS; i++)
    {
        for (int j = 0; j<COLS; j++)
        {
            board[i][j] = ' ';
        }
    }
}

void displayBoard(char board[ROWS][COLS])
{
    for (int i = 0; i < ROWS; i++) 
    {
        for (int j = 0; j < COLS; j++) 
        {
            printf("| %c ", board[i][j]);
        }
        printf("|\n");
    }
    for (int j = 0; j < COLS; j++)
    {
        printf("----");
    }
    printf("-\n");
    for (int j = 0; j < COLS; j++)
    {
        printf("  %d ", j + 1);
    }
    printf("\n");
}

bool makeMove(char board[ROWS][COLS], int col, char player) 
{
    for (int i = ROWS - 1; i >= 0; i--) 
    {
        if (board[i][col] == ' ') 
        {
            board[i][col] = player;
            return true;
        }
    }
    return false;
}
bool checkWin(char board[ROWS][COLS], char player) 
{
    // Check horizontal, vertical, and diagonal (both directions) for a win
    for (int i = 0; i < ROWS; i++) 
    {
        for (int j = 0; j < COLS; j++) 
        {
            if (board[i][j] == player) 
            {
                // Horizontal
                if (j + 3 < COLS && board[i][j + 1] == player && board[i][j + 2] == player && board[i][j + 3] == player) 
                {
                    return true;
                }
                // Vertical
                if (i + 3 < ROWS && board[i + 1][j] == player && board[i + 2][j] == player && board[i + 3][j] == player) 
                {
                    return true;
                }
                // Diagonal 1
                if (i + 3 < ROWS && j + 3 < COLS && board[i + 1][j + 1] == player && board[i + 2][j + 2] == player && board[i + 3][j + 3] == player) 
                {
                    return true;
                }
                // Diagonal 2
                if (i + 3 < ROWS && j - 3 >= 0 && board[i + 1][j - 1] == player && board[i + 2][j - 2] == player && board[i + 3][j - 3] == player) {
                    return true;
                }
            }
        }
    }
    return false;
}

int main()
{
    char board[ROWS][COLS];
    createBoard(board);
    int col;
    char currentPlayer = 'X';

    printf("Welcome to Connect 4!\n");
    displayBoard(board);

    while (true) 
    {
        printf("Player %c, choose a column (1-%d): ", currentPlayer, COLS);
        scanf("%d", &col);
        col -= 1;

        if (col >= 0 && col < COLS && makeMove(board, col, currentPlayer)) 
        {
            displayBoard(board);
            if (checkWin(board, currentPlayer)) 
            {
                printf("Player %c wins!\n", currentPlayer);
                break;
            }

            // Switch players
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        } 
        else 
        {
            printf("Invalid move. Try again.\n");
        }
    }

    return 0;
}
