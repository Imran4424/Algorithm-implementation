/*
	Transitive Closure

	Means

	Finding out paths from each vertex to all other vertex

	Transitive Matrix shows if there path from each vertex to all other vertex or not
*/
#include <iostream>
#include <vector>
using namespace std;

vector <int> *adjacency; // global vector array

vector < vector <bool> > transitiveMatrix; // global 2d vector

void AddEdge(int u, int v) // for directed graph
{
	adjacency[u].push_back(v);
}

void DFS(int one, int another) // recursive dfs
{
	// mark from one to another as true 
	transitiveMatrix[one][another] = true;

	// looking at the adjacency nodes of another
	for (int k = 0; k < adjacency[another].size(); ++k)
	{
		if (!transitiveMatrix[one][adjacency[another][k]])
		{
			DFS(one, adjacency[another][k]);
		}
	}
}

void TransitiveClosure(int startVertex, int totalVertex)
{
	// resizing 2d vector in one line

	transitiveMatrix.resize(totalVertex+1, vector <bool> (totalVertex+1, false));

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

	cout << "transitive closure Matrix is " << endl;

	if (0 == startVertex)
	{
		for (int i = startVertex; i < totalVertex; ++i)
		{
			for (int j = startVertex; j < totalVertex; ++j)
			{
				cout << transitiveMatrix[i][j] << " ";
			}

			cout << endl;
		}
	}
	else
	{		
		for (int i = startVertex; i <= totalVertex; ++i)
		{
			for (int j = startVertex; j <= totalVertex; ++j)
			{
				cout << transitiveMatrix[i][j] << " ";
			}

			cout << endl;
		}
	}

}

int main(int argc, char const *argv[])
{
	cout << "enter the number of vertex" << endl;

	int vertex;
	cin >> vertex;

	adjacency = new vector <int> [vertex + 1];

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

	TransitiveClosure(0, vertex);

	return 0;
}