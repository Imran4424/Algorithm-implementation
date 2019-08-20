#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> *adjacency;

void AddEdge(int u, int v) // unidirected graph
{
	adjacency[u].push_back(v);

	adjacency[v].push_back(u);
}

void Eliminating(int current, int cores)
{
	if (adjacency[current].size() >= cores)
	{
		return;
	}

	while(adjacency[current].size())
	{
		int target = adjacency[current].front();

		adjacency[current].erase(adjacency[current].begin()); // making directed from undirected

		// completely removing the link
		adjacency[target].erase(remove(adjacency[target].begin(), adjacency[target].end(), current), adjacency[target].end());
	}
}


void FindingKCores(int cores, int startVertex, int totalVertex)
{
	// vector <bool> visited(vertex+1, false);

	/*
		this if condition is here because,

		some people start the vertex count at 0
		and
		some people start the vertex count at 1
	*/

	int count = 3; // 3 for rechecking purposes

	while(count--)
	{
		if (0 == startVertex) // this is for start count at 0
		{
			for (int i = startVertex; i < totalVertex; ++i)
			{
				Eliminating(i, cores); // Every vertex is reachable from itself
			}
		}
		else // this is for start count at 1
		{		
			for (int i = startVertex; i <= totalVertex; ++i)
			{
				Eliminating(i, cores); // Every vertex is reachable from itself
			}
		}
		
	}

	if (0 == startVertex) // this is for start count at 0
	{
		for (int i = startVertex; i < totalVertex; ++i)
		{
			for (int j = 0; j < adjacency[i].size(); ++j)
			{
				if (j == 0)
				{
					cout << i << " -> " ;
				}

				cout << adjacency[i][j] << " ";
			}

			cout << endl;
		}
	}
	else // this is for start count at 1
	{		
		
		for (int i = startVertex; i <= totalVertex; ++i)
		{
			for (int j = 0; j < adjacency[i].size(); ++j)
			{
				if (j == 0)
				{
					cout << i << " -> " ;
				}

				cout << adjacency[i][j] << " ";
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

	FindingKCores(cores, 0, vertex);
	
	return 0;
}