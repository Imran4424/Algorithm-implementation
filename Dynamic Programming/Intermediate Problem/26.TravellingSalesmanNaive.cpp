#include <iostream>
#include <utility>
#include <vector>
using namespace std;

typedef pair <int, int> couple;

vector <couple> *adjacency;

int minimunDistance;

void AddEdge(int source, int destination, int weight)
{
	adjacency[source].push_back(make_pair(destination, weight));
	adjacency[destination].push_back(make_pair(source, weight));
}

void DFS(int current, totalVertex, vector <bool> visited, int vertexCount, int pathCost)
{
	if (vertexCount == totalVertex)
	{
		
	}

	visited[current] = true;
	vertexCount++;

	for (int k = 0; k < adjacency[current].size(); ++k)
	{
		if (!visited[adjacency[current][k].first])
		{
			DFS(adjacency[current][k].first, visited, vertexCount, pathCost + adjacency[current][k].second);
		}
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