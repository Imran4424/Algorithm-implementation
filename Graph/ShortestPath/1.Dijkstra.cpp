#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <limits.h>
using namespace std;

typedef pair <int, int> couple;

vector <couple> *adjacency;

vector <int> distance;

void AddEdge(int source, int destination, int weight)
{
	adjacency[source].push_back(make_pair(destination, weight));

	adjacency[destination].push_back(make_pair(source, weight));
}

void Dijkstra(int startVertex, int totalVertex)
{
	distance.resize(totalVertex + 1, INT_MAX);

	priority_queue<couple, vector <couple>, greater <couple> > weightedList;


	weightedList.push(make_pair(0, startVertex))

	distance[startVertex] = 0;

	while(!weightedList.empty())
	{
		couple hand = weightedList.top();
		weightedList.pop();

		int current = hand.second;

		for (int k = 0; k < adjacency[current].size; ++k)
		{
			int neighbour = adjacency[current][k].second;
			int neighbourDistance = adjacency[current][k].first;

			if(distance[current] + neighbourDistance < distance[neighbour])
			{
				distance[neighbour] = distance[current] + neighbourDistance;
			}
		}
	}

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