#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector <int> *adjacency;

void AddEdge(int u, int v) // undirected graph
{
	AddEdge[u].push_back(v);

	AddEdge[v].push_back(u);
}

int BFS(int startVertex, int totalVertex, int level)
{
	vector <bool> visited(vertex + 1, false);

	vector <int> level(vertex + 1, 0);

	queue <int> currentNodes;
	currentNodes.push(startVertex);

	visited[startVertex] = true;
	level[startVertex] = 0;
}

int main(int argc, char const *argv[])
{
	cout << "enter the number of vertex" << endl;

	int vertex;
	cin >> vertex;
	
	adjacency = new vector <int> [vertex + 1];

	cout << "how many edges?" << endl;

	int edges;
	cin >> edges;

	cout << "enter the edges" << endl;
	int u, v;

	for (int i = 0; i < edges; ++i)
	{
		cin >> u >> v;

		AddEdge(u, v);
	}

	cout << "enter the level" << endl;

	int level;
	cin >> level;

	BFS(0, vertex, level);

	return 0;
}