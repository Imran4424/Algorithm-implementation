#include <stdio.h>

int maze[40][40];

int path[40][40];

int maxRow, maxCol;

bool SearchingPath(int row, int col)
{
	if(maxRow - 1 == row && maxCol - 1 == col)
	{
		path[row][col] = 1;

		return true;
	}

	path[row][col] = 1;

	int failCount = 0;

	
	if (row < maxRow - 1)
	{
		if (maze[row+1][col] == 1)
		{
			SearchingPath(row+1, col);
		}
		else
		{
			failCount++;
		}
	}

	if (col < maxCol - 1)
	{
		if (maze[row][col+1] == 1)
		{
			SearchingPath(row, col+1);
		}
		else
		{
			failCount++;
		}
	}


	if (failCount == 2)
	{
		path[row][col] = 0;

		return false;
	}
}


int main(int argc, char const *argv[])
{
	printf("enter row and col of the maze\n");

	scanf("%d %d", &maxRow, &maxCol);

	printf("enter the maze matrix\n");

	for(int i=0; i < maxRow; i++)
	{
		for(int j=0; j < maxCol; j++)
		{
			scanf("%d", &maze[i][j]);
		}
	}


	for(int i=0; i < maxRow; i++)
	{
		for(int j=0; j < maxCol; j++)
		{
			path[i][j] = 0;
		}
	}

	SearchingPath(0, 0);

	for(int i=0; i < maxRow; i++)
	{
		for(int j=0; j < maxCol; j++)
		{
			printf("%d ", path[i][j]);
		}

		printf("\n");
	}

	return 0;
}