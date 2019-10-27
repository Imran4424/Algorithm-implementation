/*
	https://www.geeksforgeeks.org/detect-cycle-in-a-graph/
*/

#include <iostream>
#include <stdio.h>
using namespace std;

const int vSize = 50;

int path[vSize][vSize];

bool visited[vSize];

int vertex;

bool isCycleAvailabe;

bool DetectCycle(int current)
{
	if(visited[current])
	{
		return true;
	}

	visited[current] = true;

	for (int next = 0; next < vertex; ++next)
	{
		if (path[current][next])
		{
			return DetectCycle(next);
		}
	}

	return false;
}


void Solve()
{
	isCycleAvailabe = false;

	for (int x = 0; x < vertex; ++x)
	{
		if (!visited[x])
		{
			if(DetectCycle(x))
			{
				isCycleAvailabe = true;

				break;
			}
		}
	}
}

void Init()
{
	for (int i = 0; i <= vertex; ++i)
	{
		visited[i] = false;

		for (int j = 0; j < vertex; ++j)
		{
			path[i][j] = 0;
		}
	}
}

void ReadCase()
{
	cin >> vertex;

	Init();

	int edges, source, destination;

	cin >> edges;

	while(edges--)
	{
		cin >> source >> destination;

		path[source][destination] = 1;
	}

}

void Display()
{
	if (isCycleAvailabe)
	{
		cout << "Cycle Found" << endl;
	}
	else
	{
		cout << "Cycle not Found" << endl;
	}
}

int main(int argc, char const *argv[])
{
	freopen("input.txt", "r", stdin);

	while(cin >> vertex)
	{
		if (!vertex)
		{
			break;
		}

		ReadCase();
		Solve();
		Display();
	}


	return 0;
}