#include <stdio.h>

int maze[40][40];

int path[40][40];

int maxRow, maxCol;

void SearchingPath(int row, int col)
{
	if(maxRow - 1 == row && maxCol - 1 == col)
	{
		path[row][col] = 1;

		return;
	}

	if (maxRow - 1 == row)
	{
		return;
	}

	if (maxCol - 1 == col)
	{
		return;
	}

	path[row][col] = 1;

	if (maze[row+1][col] == 1)
	{
		SearchingPath(row+1, col);
	}

	if (maze[row][col+1] == 1)
	{
		SearchingPath(row, col+1);
	}
}


int main(int argc, char const *argv[])
{
	printf("enter row and col of the maze\n");

	scanf("%d %d", &maxRow, &maxCol);

	printf("enter the maze matrix\n");

	for(int i=0; i < maxRow; i++)
	{
		for(int col=0; j < maxCol; j++)
		{
			scanf("%d", &maze[i][j]);
		}
	}


	for(int i=0; i < maxRow; i++)
	{
		for(int col=0; j < maxCol; j++)
		{
			path = 0;
		}
	}


	return 0;
}