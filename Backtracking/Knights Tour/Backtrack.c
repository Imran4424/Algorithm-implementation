#include <stdio.h>
#include <stdbool.h>

bool isVisited[8][8];
int solution[8][8];

bool isSafe(int row, int col)
{
	if(row >= 0 && row < 8)
	{
		if (col >= 0 && col < 8)
		{
			if (!isVisited[row][col])
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
			isVisited[nextX][nextY] = true;

			if (KnightTour(nextX, nextY, noMoves+1, xMove, yMove))
			{
				return true;
			}
			else
			{
				solution[nextX][nextY] = 0; // backtracking
				isVisited[nextX][nextY] = false;
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
			isVisited[i][j] = false;
		}
	}

	int yMove[8] = {1, 2, 2, 1, -1, -2, -2, -1};
	int xMove[8] = {2, 1, -1, -2, -2, -1, 1, 2};

	printf("enter the starting position of Knight\n");

	int x, y;

	scanf("%d %d", &x, &y);

	solution[x][y] = 1;

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