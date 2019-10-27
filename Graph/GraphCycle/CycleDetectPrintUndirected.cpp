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
				// clearing Undirected edges

				path[current][next] = 0;
				path[next][current] = 0;

				int nodeNum = DetectCycle(next, currentColor + 1);

				if (-1 == nodeNum)
				{
					color[next] = -1;
				}
				else
				{
					return nodeNum;
				}
			}

		}

		return -1;
	}
	else
	{
		return color[current];
	}
}

void Solve()
{
	cycleFound = -1;

	int paint = 0;

	for (int x = 1; x <= vertex; ++x)
	{
		if (0 == color[x])
		{
			cycleFound = DetectCycle(x, paint + 1);

			if (-1 != cycleFound)
			{
				break;
			}
		}
	}
}

void Display()
{
	if (-1 != cycleFound)
	{
		for (int x = 1; x <= vertex; ++x)
		{
			if (cycleFound <= color[x])
			{
				printf(" %d", x);
			}
		}

		printf("\n");
	}
	else
	{
		printf(" -1\n");
	}
}

int main(int argc, char const *argv[])
{
	freopen("input.txt", "r", stdin);

	int test;
	cin >> test;

	for (int t = 1; t <= test; ++t)
	{
		printf("#%d", t);

		ReadCase();
		Solve();
		Display();
	}

	return 0;
}