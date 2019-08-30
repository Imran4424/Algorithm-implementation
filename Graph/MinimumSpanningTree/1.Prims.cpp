#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>
using namespace std;

typedef pair <int, int> couple;
typedef pair <int, pair <int, int> > nestedCouple;

vector <couple> *adjacency;

void AddEdge(int source, int destination, int weight) // undirected weighted graph
{
	adjacency[source].push_back(make_set(destination, weight));

	adjacency[destination].push_back(make_set(source, weight));
}



int main(int argc, char const *argv[])
{
	cout << "enter the number of vertex" << endl;

	int vertex;
	cin >> vertex;

	adjacency = new vector <couple> [vertex + 1];

	cout << "How many edges?" << endl;

	int edges;
	cin >> edges;

	cout << "enter edges source, destination and weight" << endl;

	int source, destination, weight;

	for (int i = 0; i < edges; ++i)
	{
		cin >> source >> destination >> weight;

		AddEdge(source, destination, weight);
	}
	


	return 0;
}