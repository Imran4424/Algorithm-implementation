#include <iostream>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

typedef pair <int, int> couple;

vector <couple> *adjacency;

vector <int> distance;

void AddEdge(int source, int destination, int weight)
{
	adjacency[source].push_back(make_pair(destination, weight));

	adjacency[destination].push_back(make_pair(source, weight));
}

void Dijkstra()
{
	
}

int main(int argc, char const *argv[])
{
	cout << "enter the number of vertex" << endl;

	int vertex;
	cin >> vertex;

	adjacency = new vector <couple> [vertex + 1];

	cout << "How many edges ?" << endl;

	int edges;
	cin >> edges;

	cout << "enter the source, destination and weight" << endl;

	int source, destination, weight

	for (int i = 0; i < edges; ++i)
	{
		cin >> source >> destination >> weight;

		AddEdge(source, destination, weight);
	}


	
	return 0;
}