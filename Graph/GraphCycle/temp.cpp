#include<stdio.h>
#define MAXNODE 101
int T, Case;
int Colored[MAXNODE];
int path[MAXNODE][MAXNODE];
int node, edge;
int Ans;

void readCase()
{
	int i, j;

	int x, y;
	scanf("%d %d", &node, &edge);

	for (i = 1; i <= node; i++)
	{
		for (j = 1; j <= node; j++)
		{
			path[i][j] = 0; 
		}
	}

	for (i = 0; i < edge; i++)
	{
		scanf("%d %d", &x, &y);
		path[x][y] = 1;
		path[y][x] = 1; //if its a bidirectional
	}
}

int solve(int i, int color)
{
	int j;
	int x;

	if (0 == Colored[i])
	{
		Colored[i] = color;

		for (j = 1; j <= node; j++)
		{
			if (path[i][j])
			{
				path[i][j] = 0;
				path[j][i] = 0;

				x = solve(j, color + 1);
				if (x == -1)
				{
					Colored[j] = -1;
				}
				else
				{
					return x;
				}
			}
		}
		return -1;
	}
	else
	{
		return Colored[i];
	}
}

void solveCase()
{
	int i;
	int color = 0;
	
	for (i = 1; i <= node; i++)
	{
		Colored[i] = 0;
	}

	for (i = 1; i <= node; i++)
	{
		if (0 == Colored[i])
		{
			Ans = solve(i, color + 1);
			if (Ans != -1)
			{
				break;
			}
		}
	}
}

void printCase()
{
	int i;
	printf("#%d", Case);
	if (Ans != -1)
	{
		for (i = 1; i <= node; i++)
		{
			if (Ans <= Colored[i])
			{
				printf(" %d", i);
			}
		}
	}
	else
	{
		printf(" -1");
	}
	printf("\n");
}
int main()
{
	//freopen("input.txt", "r", stdin);
	scanf("%d", &T);
	
	for (Case = 1; Case <= T; Case++)
	{
		readCase();
		solveCase();
		printCase();
	}
	return 0;
}