/*
	https://www.geeksforgeeks.org/detect-cycle-in-a-graph/
*/

#include <iostream>
#include <stdio.h>
using namespace std;

const int vSize = 50;

int path[vSize][vSize];

int vertex;

void ReadCase()
{
	cin >> vertex;

	int edges, source, destination;

	cin >> edges;

	while(edges--)
	{
		cin >> source >> destination;
	}

}

int main(int argc, char const *argv[])
{
	ReadCase();


	return 0;
}