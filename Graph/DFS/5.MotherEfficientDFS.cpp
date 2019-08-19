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
#include <stack>
using namespace std;

vector <int> motherVertex;

vector <int> *adjacency;

int count;

void AddEdge(int u, int v) // directed graph
{
	adjacency[u].push_back(v);
}

void DFS(int startVertex, int totalVertex)
{
	vector <bool> visited(totalVertex+1, false);

	count = 0;

	stack <int> currentNode;

	currentNode.push(startVertex);
	visited[startVertex] = true;
	count++;

	while(!currentNode.empty())
	{
		int current = currentNode.top();
		currentNode.pop();

		for (int k = 0; k < adjacency[current].size(); ++k)
		{
			if (!visited[adjacency[current][k]])
			{
				currentNode.push(adjacency[current][k]);

				visited[adjacency[current][k]] = true;

				count++;
			}	
		}

	}

	if (count == totalVertex)
	{
		motherVertex.push_back(startVertex);
	}
}

int SearchMother(int startVertex ,int totalVertex)
{
	vector <bool> visited(totalVertex+1, false);

	int lastFinishedVertex = 0;


}

int main(int argc, char const *argv[])
{
	cout << "enter the number of vertices" << endl;

	int vertex;
	cin >> vertex;

	adjacency = new vector <int> [vertex+1];  // taking an array of vector

	cout << "how many edges?" << endl;

	int edges;
	cin >> edges;

	int u,v;

	cout << "input the edges" << endl;

	for (int i = 0; i < edges; ++i)
	{
		cin >> u >> v;

		AddEdge(u, v);
	}

	

	if (motherVertex.size())
	{
		cout << "Mother vertex: " << motherVertex[0] << endl;
	}

	return 0;
}