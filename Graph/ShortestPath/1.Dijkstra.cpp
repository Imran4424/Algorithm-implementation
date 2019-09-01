#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <limits.h>
using namespace std;

typedef pair <int, int> couple;

vector <couple> *adjacency;

vector <int> distanceFromSource;

void AddEdge(int source, int destination, int weight)
{
	adjacency[source].push_back(make_pair(destination, weight));

	adjacency[destination].push_back(make_pair(source, weight));
}

void Dijkstra(int startVertex, int totalVertex)
{

	distanceFromSource.resize(totalVertex + 1, INT_MAX);

	priority_queue<couple, vector <couple>, greater <couple> > weightedList;

	int iteration = (totalVertex / 2);

	while(iteration--)
	{

		vector <bool> visited(totalVertex + 1, false);

		weightedList.push(make_pair(0, startVertex));

		// following two statements won't create any problem for next iteration
		distanceFromSource[startVertex] = 0;
		visited[startVertex] = true;


		while(!weightedList.empty())
		{
			// cout << "Hi" << endl;

			couple hand = weightedList.top();
			weightedList.pop();

			int current = hand.second;

			for (int k = 0; k < adjacency[current].size(); ++k)
			{
				int neighbour = adjacency[current][k].first;
				int neighbourDistance = adjacency[current][k].second;

				if(distanceFromSource[current] + neighbourDistance < distanceFromSource[neighbour])
				{
					distanceFromSource[neighbour] = distanceFromSource[current] + neighbourDistance;
				}

				if (!visited[neighbour])
				{
					weightedList.push(make_pair(neighbourDistance, neighbour));

					visited[neighbour] = true;
				}
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

	int source, destination, weight;

	for (int i = 0; i < edges; ++i)
	{
		cin >> source >> destination >> weight;

		AddEdge(source, destination, weight);
	}

	int startVertex = 0;

	Dijkstra(startVertex, vertex);

	cout << "Distance from source is" << endl;

	if (0 == startVertex)
	{
		for (int i = startVertex; i < vertex; ++i)
		{
			cout << i << " " << distanceFromSource[i] << endl;
		}
	}
	else
	{
		for (int i = startVertex; i <= vertex; ++i)
		{
			cout << i << " " << distanceFromSource[i] << endl;
		}
	}
	
	return 0;
}