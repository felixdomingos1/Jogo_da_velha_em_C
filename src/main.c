#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

char board[3][3];
const char Player = 'X';
const char Computer = 'o';


void resetBoard();
void printBoard();
int checkFreeSpaces();
void playerMove();
void computerMove();
void checkWinner();
void printWinner();


int main()
{
        char winner = ' ';

        resetBoard();
	while (winner == ' ' && checkFreeSpaces() != 0)
	{
        	printBoard();

		playerMove();

		winner = checkFreeSpaces();
	}
	
        return 0;
}


void resetBoard()
{
        for (int i = 0; i < 3; i++)
        {
         for (int j = 0; j < 3; j++)
         {
                board[i][j] = ' ';
         }
         
        }
        
}


void printBoard()
{
        printf("  %c  |    %c   |  %c  ", board[0][0], board[0][1], board[0][2]);
        printf("\n     |        |      ");
        printf("\n-----|--------|------");
        printf("\n     |        |      ");
        printf("\n %c   |   %c    |  %c  ", board[1][0], board[1][1], board[1][2]);
        printf("\n     |        |      ");
        printf("\n-----|--------|------");
        printf("\n     |        |      ");
        printf("\n  %c  |   %c    |   %c   ",board[2][0], board[2][1], board[2][2]);
        printf("\n");
}


int checkFreeSpaces()
{
	int freeSpaces = 8 + 1;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (board[i][j] != ' ')
			{
				freeSpaces--;
			}
			
		}
		
	}
	return freeSpaces;
	
}


void playerMove()
{
	int x ;
	int y;
	do
	{
		printf("Enter row #(1-3): ");
		scanf(" %d ",&x);
		x--;
		printf("Enter column #(1-3): ");
		scanf(" %d ",&y);
		y--;

		if (board[x][y] == ' ')
		{
			printf("Envalid Move!\n");
		}
		else
		{
			board[x][y] = Player;
			break;
		}
	} while (board[x][y] == ' ');
	
	
}


void computerMove()
{

}


void checkWinner()
{

}


// void printWinner(char winner)
// {

// }