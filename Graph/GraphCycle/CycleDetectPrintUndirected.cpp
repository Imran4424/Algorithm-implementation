#include <iostream>
#include <stdio.h>
using namespace std;

const int vSize = 101;

int path[vSize][vSize];

int color[vSize];

int vertex, edges;

int cycleFound;

void Init()
{
	for (int i = 0; i <= vertex; ++i)
	{
		color[i] = 0;

		for (int j = 0; j <= edges; ++j)
		{
			path[i][j] = 0;
		}
	}
}

void ReadCase()
{
	cin >> vertex >> edges;

	Init();

	int x, y;

	while(edges--)
	{
		cin >> x >> y;

		// Undirected
		path[x][y] = 1;
		path[y][x] = 1;
	}
}

int DetectCycle(int current, int currentColor)
{
	if (0 == color[current])
	{

		color[current] = currentColor;

		for (int next = 1; next <= vertex; ++next)
		{
			if (path[current][next])
			{
				int status = DetectCycle(next, currentColor + 1);

				if (-1 == status)
				{
					color[next] = -1;
				}
			}


			
		}
	}
	else
	{
		return color[x];
	}
}

void Solve()
{
	cycleFound = -1;

	int color = 0;

	for (int x = 1; x <= vertex; ++x)
	{
		if (0 == color[x])
		{
			cycleFound = DetectCycle(x, color + 1);

			if (-1 != cycleFound)
			{
				break;
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	int test;
	cin >> test;

	for (int t = 1; t <= test; ++t)
	{
		printf("#%d ", t);

		ReadCase();
	}

	return 0;
}