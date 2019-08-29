#include <iostream>
#include <vector>
using namespace std;

int *parent, countMinimum;

/*
	Initializing the disjoint set

	making everyone their parent himself
*/

void MakeSet(int p) 
{
	parent[p] = p;
}

void InitDisjoint(int vertex)
{
	for (int i = 1; i <= vertex; ++i)
	{
		MakeSet(i);
	}
}

/*
	end of the initialization
*/

/*
	this find parent function is without path relaxation

	this can cost much time if the graph depth is long
*/

int FindParent(int vertex) 
{
	if (parent[vertex] == vertex)
	{
		return vertex;
	}

	return FindParent(parent[vertex]);
}

void Union(int xVertex, int yVertex)
{
	if (FindParent(xVertex) != FindParent(yVertex))
	{
		parent[yVertex] = xVertex;

		countMinimum++;
	}
}

int main(int argc, char const *argv[])
{
	countMinimum =0; // edge countMinimum

	cout << "enter the number of vertex" << endl;

	int vertex;
	cin >> vertex;

	parent = new int[vertex + 1];

	InitDisjoint(vertex);

	cout << "How many pairs want to join?" << endl;

	int pairs;
	cin >> pairs;

	cout << "enter the pairs"

	int u, v;

	for (int i = 0; i < pairs; ++i)
	{
		cin >> u >> v;

		Union(u, v);
	}

	cout << "Minimum edge needed: " << countMinimum << endl;

	return 0;
}