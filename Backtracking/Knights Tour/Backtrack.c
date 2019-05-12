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

	return 0;
}