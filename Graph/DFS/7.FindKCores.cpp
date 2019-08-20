#include <iostream>
#include <vector>
using namespace std;

vector <int> *adjacency;

void AddEdge(int u, int v) // unidirected graph
{
	AddEdge[u].push_back(v);

	AddEdge[v].push_back(u);
}

void Eliminating(int current, int cores)
{
	if (adjacency[current].size() >= cores)
	{
		return;
	}

	for (int i = 0; i < adjacency[current].size(); ++i)
	{
		/* code */
	}
}


void FindingKCores(int cores, int startVertex, int totalVertex)
{
	vector <bool> visited(vertex+1, false);

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
			DFS(i, i); // Every vertex is reachable from itself
		}
	}

}


int main(int argc, char const *argv[])
{
	cout << "enter the number of vertex" << endl;

	int vertex;
	cin >> vertex;

	adjacency = new vector <int> [vertex + 1];

	cout << "How many edges" << endl;

	int edges;
	cin >> edges;

	cout << "enter the edges" << endl;

	int u, v;

	for (int i = 0; i < edges; ++i)
	{
		cin >> u >> v;

		AddEdge(u, v);
	}

	cout << "How many cores" << endl;

	int cores;
	cin >> cores;
	
	return 0;
}