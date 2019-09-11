#include <iostream>
#include <utility>
#include <vector>
using namespace std;

typedef pair <int, int> couple;

vector <couple> *adjacency;

void AddEdge(int source, int destination, int weight)
{
	adjacency[source].push_back(make_pair(destination, weight));
	adjacency[destination].push_back(make_pair(source, weight));
}

void DFS(int current, vector <bool> visited, int vertexCount)
{

	vertexCount++;

	for (int k = 0; k < adjacency[current].size(); ++k)
	{
		/* code */
	}
}


void Solve(int startVertex, int totalVertex)
{
	vector <bool> visited(totalVertex + 1, false);
}


int main(int argc, char const *argv[])
{
	cout << "enter the vertex number" << endl;

	int vertex;
	cin >> vertex;

	adjacency = new vector <couple> [vertex + 1];

	cout << "how many edges ?" <<endl;
	int edges;
	cin >> edges;

	int source, destination, weight;

	cout << "enter the edges " << endl;

	for (int i = 0; i < edges; ++i)
	{
		cin >> source >> destination >> weight;

		AddEdge(source, destination, weight);
	}

	Solve(1, vertex);

	return 0;
}