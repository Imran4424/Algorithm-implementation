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

void DFS(int current, vector <int> &visited)
{
	// marking the current node as visited
	visited[current] = true;


	// looking at the adjacency 
	for (int k = 0; k < adjacency[current].size(); ++k)
	{
		if (!visited[adjacency[current][k]])
		{
			DFS(adjacency[current][k], visited);
		}	
	}

}

int SearchMother(int startVertex ,int totalVertex)
{
	vector <bool> visited(totalVertex+1, false);

	int lastFinishedVertex = startVertex;

	if (0 == startVertex)
	{
		for (int i = startVertex; i < totalVertex; ++i)
		{
			if (!visited[i])
			{
				DFS(i, visited);

				lastFinishedVertex = i;
			}
		}
	}
	else
	{
		
	}


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