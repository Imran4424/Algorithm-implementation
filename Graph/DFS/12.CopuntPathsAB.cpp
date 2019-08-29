#include <iostream>
#include <vector>
using namespace std;

vector <int> *adjacency;

int count;

void AddEdge(int u, int v) // directed graph
{
	adjacency[u].push_back(v);
}

void RecursiveDFS(int current, int destination, vector <bool> visited) // here visited array will be different
{
	if (current == destination)                                   //  for every iteration in reaction
	{
		count++;

		return;
	}

	for (int k = 0; k < adjacency[current].size(); ++k)
	{
		if (!visited[adjacency[current][k]])
		{
			visited[adjacency[current][k]] = true;

			RecursiveDFS(adjacency[current][k], destination, visited);
		}

	}
}

int main(int argc, char const *argv[])
{
	count = 0; // clearing for every test cases

	cout << "enter the number of vertex" << endl;

	int vertex;
	cin >> vertex;

	adjacency = new vector <int> [vertex + 1]; // array of vector

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

	cout << "enter the entry and destination vertex" << endl;

	int entry, destination;
	cin >> entry >> destination;

	vector <bool> visited(vertex + 1, false);

	visited[entry] = true;

	RecursiveDFS(entry, destination, visited);

	cout << "number of paths are: " << count << endl;
	
	return 0;
}