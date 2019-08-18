/*
	Mother vertex - In graph mother vertex is that vertex or node, from which we can reach all other
	vertices in the graph

	In a graph there can more than one mother vertex

	In this we will print just one.

	In the case undirected graph all vertices are mother vertices

	But directed graph or undirected disconnected graph we need to find mother vertex.

	In this code, we will consider directed graph.

*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector <int> motherVertex;

vector <int> *adjacency;

int count;

void AddEdge(int u, int v) // directed graph
{
	adjacency[u].push_back(v);
}

void BFS(int startVertex, int totalVertex)
{
	vector <bool> visited(totalVertex+1, false);

	count = 0;

	queue <int> currentNode;

	currentNode.push_back(startVertex);
	visited[startVertex] = true;
	count++;

	while(!currentNode.empty())
	{
		int current = currentNode.front();
		currentNode.pop();

		for (int k = 0; k < adjacency[current].size(); ++k)
		{
			if (!visited[adjacency[current][k]])
			{
				currentNode.push_back(adjacency[current][k]);
			}
		}

	}


}

int main(int argc, char const *argv[])
{
	cout << "enter the number of vertices" << endl;

	int vertex;
	cin >> vertex;

	adjacency = new vector <int> [vertex+1];

	cout << "how many edges?" << endl;

	int edges;
	cin >> edges;

	int u,v;

	for (int i = 0; i < edges; ++i)
	{
		cin >> u >> v;

		AddEdge(u, v);
	}

	return 0;
}