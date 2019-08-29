#include <iostream>
#include <vector>
using namespace std;

vector <int> *adjacency;

int count;

void AddEdge(int u, int v) // directed graph
{
	adjacency[u].push_back(v);
}

void RecursiveDFS(int current, int destination)
{
	if (current == destination)
	{
		count++;

		return;
	}

	for (int k = 0; i < adjacency[current].size(); ++k)
	{
		RecursiveDFS(adjacency[current][k], destination);
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

	in edges;
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