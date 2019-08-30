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
	adjacency[source].push_back(make_pair(destination, weight));

	adjacency[destination].push_back(make_pair(source, weight));
}

int PrimsMinimumSpanningTree(int startVertex, int totalVertex)
{
	int minimumWeight = 0; // for minimum spanning tree weight

	// declaring priority queue of weighted edges ascending order
	priority_queue < couple, vector <couple>, greater <couple> > weightedList;

	vector <bool> visited(totalVertex + 1, false);

	int visitedCount = totalVertex; // for tracking visited vertex number
				       //  Initializing visitedCount with totalVertex

	visited[startVertex] = true; // marking the startVertex as visited
	visitedCount--;

	for (int k = 0; k < adjacency[startVertex].size(); ++k) // finding startVertex adjacency
	{
		couple helper = adjacency[startVertex][k]; // adjacency pair

		weightedList.push(make_pair(helper.second, helper.first));
	}

	while(!weightedList.empty() && visitedCount) // reducing visitedCount by 1
	{                                             //  visitedCount == 0 means
		                                     //   all vertex have been visited

		couple hand = weightedList.top();
		weightedList.pop();

		if (!visited[hand.second]) // rechecking if there exist any minimum edges 
		{                         //  with visited vertex
		
			minimumWeight = minimumWeight + hand.first;

			cout << hand.first << endl;

			int current = hand.second; // destination vertex from the startVertex

			visited[current] = true;
			visitedCount--;
		
			for (int k = 0; k < adjacency[current].size(); ++k) // now finding the adjacency of current vertex
			{
				couple helper = adjacency[current][k]; // adjacency pair

				if (!visited[helper.first])
				{
					weightedList.push(make_pair(helper.second, helper.first));
				}
			}
		}
	}

	return minimumWeight;
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
	
	int minimumWeight = PrimsMinimumSpanningTree(1, vertex);

	cout << "minimum spanning tree: " << minimumWeight << endl;

	return 0;
}