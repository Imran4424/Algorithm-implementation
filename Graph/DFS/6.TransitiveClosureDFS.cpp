#include <iostream>
#include <vector>
using namespace std;

vector <int> *adjacency;

vector <bool> *transitiveMatrix;

void AddEdge(int u, int v) // for directed graph
{
	adjacency[u].push_back(v);
}

void BFS(int one, int another)
{
	// mark from one to another as true 
	visited[one][another] = true;

	// looking at the adjacency nodes of current
	for (int k = 0; k < adjacency[current].size(); ++k)
	{
		if (!visited[adjacency[current][k]])
		{
			BFS(adjacency[current][k], visited);
		}
	}
}

void TransitiveClosure(int startVertex, int totalVertex)
{
	transitiveMatrix = new vector <bool> (totalVertex+1, vector <int> (totalVertex+1, false));

	/*
		this if condition is here because,

		some people start the vertex count at 0
		and
		some people start the vertex count at 1
	*/

	if (0 == startVertex) // this is for start count at 0
	{
		for (int i = startVertex; i < totalVertex; ++i)
		{
			DFS(i, i); // Every vertex is reachable from itself
		}
	}
	else // this is for start count at 1
	{		
		for (int i = startVertex; i <= totalVertex; ++i)
		{
			DFS(i, i);
		}
	}

}

int main(int argc, char const *argv[])
{
	cout << "enter the number of vertex" << endl;

	int vertex;
	cin >> vertex;

	adjacency = new vector <int> (vertex + 1);

	cout << "How many edges?" << endl;

	int edges;
	cin >> edges;

	cout << "enter the edges" << endl;

	int u, v;

	for (int i = 0; i < edges; ++i)
	{
		cin >> u >> v;

		AddEdge(u, v);
	}

	return 0;
}