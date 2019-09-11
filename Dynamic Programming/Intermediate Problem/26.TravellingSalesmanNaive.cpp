#include <iostream>
#include <utility>
using namespace std;

typedef pair <int, int> couple;

vector <couple> *adjacency;

void AddEdge(int source, int destination, int weight)
{
	adjacency[source].push_back(make_pair(destination, weight));
	adjacency[destination].push_back(make_pair(source, weight));
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
		cin >> source >> destination >> edges;

		AddEdge(source, destination, edges);
	}

	return 0;
}