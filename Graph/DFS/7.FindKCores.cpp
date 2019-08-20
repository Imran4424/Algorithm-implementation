#include <iostream>
#include <vector>
using namespace std;

vector <int> *adjacency;

void AddEdge(int u, int v) // unidirected graph
{
	AddEdge[u].push_back(v);

	AddEdge[v].push_back(u);
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
	
	return 0;
}