#include <iostream>
#include <vector>
using namespace std;

vector <int> *adjacency;

void AddEdge(int u, int v) // for directed graph
{
	adjacency[u].push_back(v);
}

void BFS(int current, vector <bool> &visited)
{
	// mark the current as visited
	visited[current] = true;

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
	vector <bool> visited(totalVertex+1, false);
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