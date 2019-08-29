#include <iostream>
#include <vector>
using namespace std;

int *parent;

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

int FindParent(int vertex)
{
	if (parent[vertex] == vertex)
	{
		return vertex;
	}

	return FindParent(parent[vertex]);
}

int main(int argc, char const *argv[])
{
	cout << "enter the number of vertex" << endl;

	int vertex;
	cin >> vertex;

	parent = new int[vertex + 1];

	InitDisjoint(vertex);



	return 0;
}