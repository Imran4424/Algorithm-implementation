#include <stdio.h>

int maze[40][40];

int path[40][40];

int maxRow, maxCol;



int main(int argc, char const *argv[])
{
	printf("enter row and col of the maze\n");

	scanf("%d %d", &row, &col);

	printf("enter the maze matrix\n");

	for(int i=0; i < row; i++)
	{
		for(int col=0; j < col; j++)
		{
			scanf("%d", &maze[i][j]);
		}
	}


	for(int i=0; i < row; i++)
	{
		for(int col=0; j < col; j++)
		{
			path = 0;
		}
	}


	return 0;
}