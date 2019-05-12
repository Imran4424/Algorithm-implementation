#include <stdio.h>
#include <stdbool.h>


int solution[8][8];

bool isSafe(int row, int col)
{
	if(row >= 0 && row < 8)
	{
		if (col >= 0 && col < 8)
		{
			if (solution[row][col] == -1)
			{
				return true;
			}
		}
	}

	return false;
}


bool KnightTour(int row, int col, int noMoves, int *xMove, int *yMove)
{
	if (noMoves == 8*8)
	{
		return true;
	}

	int nextX, nextY;

	for(int i = 0; i < 8; i++)
	{
		nextX = row + xMove[i];
		nextY = col + yMove[i];

		if(isSafe(nextX, nextY))
		{
			solution[nextX][nextY] = noMoves;

			if (KnightTour(nextX, nextY, noMoves+1, xMove, yMove))
			{
				return true;
			}
			else
			{
				solution[nextX][nextY] = -1; // backtracking
			}
		}
	}

	return false;
}


int main(int argc, char const *argv[])
{
	for (int i = 0; i < 8; ++i)
	{
		for(int j = 0; j < 8; ++j)
		{
			solution[i][j] = -1;
		}
	}

	int yMove[8] = {1, 2, 2, 1, -1, -2, -2, -1};
	int xMove[8] = {2, 1, -1, -2, -2, -1, 1, 2};

	printf("enter the starting position of Knight\n");

	int x, y;

	scanf("%d %d", &x, &y);

	solution[x][y] = 0;

	bool status = KnightTour(x, y, 1, xMove, yMove);

	if (status)
	{
		for (int i = 0; i < 8; ++i)
		{
			for (int j = 0; j < 8; ++j)
			{
				printf("%d ", solution[i][j]);
			}
			printf("\n");
		}
	}
	else
	{
		printf("solution doesn't exist\n");
	}

	return 0;
}