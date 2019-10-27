#include <iostream>
#include <stdio.h>
using namespace std;

const int vSize = 101;

int path[vSize][vSize];

int vertex, edges;

void Init()
{
	for (int i = 0; i <= vertex; ++i)
	{
		for (int j = 0; j <= edges; ++j)
		{
			path[i][j] = 0;
		}
	}
}

void ReadCase()
{
	cin >> vertex >> edges;

	int x, y;

	while(edges--)
	{
		cin >> x >> y;

		// Undirected
		path[x][y] = 1;
		path[y][x] = 1;
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