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
char checkWinner();
void printWinner();


int main()
{
        char winner = ' ';

        resetBoard();
	while (winner == ' ' && checkFreeSpaces() != 0)
	{
        	printBoard();

		playerMove();

		winner = checkWinner();

		if (winner != ' ' || checkFreeSpaces() == 0)
		{
			break;
		}

		computerMove();

		winner = checkWinner();

		if (winner != ' ' || checkFreeSpaces() == 0)
		{
			break;
		}
		
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
	srand(time(0));
	int x;
	int y;

	if (checkFreeSpaces() > 0)
	{
		do
		{
			x = rand() % 3;
			y = rand() % 3;
		} while (board[x][y] != ' ');
		
		board[x][y] = Computer;
	}
	else
	{
		printWinner(' ');
	}
	
	
}


char checkWinner()
{
	for (int i = 0; i < 3; i++)
	{
		if (board[i][0] == board[i][1] && board[i][0] == board[i][2])
		{
			return board[i][0];
		}
		
	}

	for (int j = 0; j < 3; j++)
	{
		if (board[0][j] == board[1][j] && board[0][j] == board[2][j])
		{
			return board[0][j];
		}
		
	}
	if (board[0][0] == board[1][1] && board[0][0] == board[2][2])
	{
		return board[0][0];
	}
	if (board[0][2] == board[1][1] && board[0][0] == board[2][0])
	{
		return board[0][2];
	}
	return ' ';
}


// void printWinner(char winner)
// {

// }