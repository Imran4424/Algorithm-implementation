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
	this find parent function is with path relaxation

	this is very much time efficient
*/

int FindParent(int vertex) // this is a recursive function to find vertex parent
{
	if (parent[vertex] == vertex)
	{
		return vertex;
	}

	return parent[vertex] = FindParent(parent[vertex]);
}

/*
	this function union two vertex if their parent aren't same

	if their parent is same then Union skips

	so that

	graph doesn't contain a graph
*/

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

	cout << "enter the pairs" << endl;

	int u, v;

	for (int i = 0; i < pairs; ++i)
	{
		cin >> u >> v;

		Union(u, v);
	}

	cout << "Minimum edge needed: " << countMinimum << endl;

	return 0;
}