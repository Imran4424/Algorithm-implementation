#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int *parent; // parent array to hold the parents

/*
	creating a class for holding the edges

	as

	customized datatype
*/

struct EdgeInstance
{
	int source, destination, weight;

	bool operator <(const EdgeInstance& obj)
	{
		return weight < obj.weight;
	}
};

/*
	Initializing the disjoint set

	making everyone their parent himself
*/

void Makeset(int p)
{
	parent[p] = p;
}

/*
	Initializing the disjoint of the graph
*/

void InitDisjoint(int vertex)
{
	for (int i = 1; i <= vertex; ++i)
	{
		Makeset(i);
	}
}

int SearchParent(int vertex) // recursive function to search parent of a vertex
{
	if (vertex == parent[vertex])
	{
		return vertex;
	}

	return parent[vertex] = SearchParent(parent[vertex]);
}

/*
	checking 

	adding the edge will create a cycle in the graph or not
*/

bool Union(int xVertex, int yVertex)
{
	int xParent = SearchParent(xVertex);
	int yParent = SearchParent(yVertex);

	if (xParent != yParent)
	{
		parent[yParent] = xParent;

		return true;
	}

	return false;
}

int MinimumSpanningTree(int vertex, vector <EdgeInstance> edgeList)
{

	InitDisjoint(vertex);

	// cout << "Hey" << endl;

	sort(edgeList.begin(), edgeList.end()); // ascending sort

	int currentWeight = 0;

	for (int i = 0; i < edgeList.size(); ++i)
	{
		if (Union(edgeList[i].source, edgeList[i].destination))
		{
			currentWeight = currentWeight + edgeList[i].weight;
		}
	}

	return currentWeight;
}

int main(int argc, char const *argv[])
{
	cout << "enter the number of vertex" << endl;

	int vertex;
	cin >> vertex;

	parent = new int[vertex + 1]; // cause counting starts with 1 mostly in MST

	vector <EdgeInstance> edgeList; // declaring user defined vector

	cout << "How many edges?" << endl;

	int edges;
	cin >> edges;

	EdgeInstance input;

	cout << "enter edges source, destination and weight" << endl;

	for (int i = 0; i < edges; ++i)
	{
		cin >> input.source >> input.destination >> input.weight;

		edgeList.push_back(input);
	}

	cout << "Minimum Spanning Tree: " << MinimumSpanningTree(vertex, edgeList) << endl;

	return 0;
}