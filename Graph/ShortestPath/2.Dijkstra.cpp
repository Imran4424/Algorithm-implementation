#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node
{
	int vertex;
	int cost;

	Node(int vertex, int cost) {
		this -> vertex = vertex;
		this -> cost = cost;
	}

	// operator overloading for max heap
	bool operator< (const Node& p) const {
		return cost < p.cost;
	}

	// operator overloading for min heap
	bool operator> (const Node& p) const {
		return cost > p.cost;
	} 
};

vector<Node> *adjacency;

vector <int> distanceFromSource;

void AddEdge(int source, int destination, int weight)
{
	adjacency[source].push_back(Node(destination, weight));

	adjacency[destination].push_back(Node(source, weight));
}


void Dijkstra(int startVertex, int totalVertex)
{
	distanceFromSource.resize(totalVertex + 1, INT_MAX);

	priority_queue<Node, vector <Node>, greater <Node> > weightedList;

	weightedList.push(Node(startVertex, 0));
	distanceFromSource[startVertex] = 0;

	while(!weightedList.empty()) {
		Node currentNode = weightedList.top();
		weightedList.pop();

		int curVertex = currentNode.vertex;
		int cost = currentNode.cost;

		for (int i = 0; i < adjacency[curVertex].size(); ++i) {
			int neighbour = adjacency[curVertex][i].vertex;
			int neighbourDistance = adjacency[curVertex][i].cost;

			// cout << "before path relaxation" << endl;
			// cout << distanceFromSource[curVertex] << " " << neighbourDistance << " " << distanceFromSource[neighbour] << endl;

			// path relaxation
			if (distanceFromSource[curVertex] + neighbourDistance < distanceFromSource[neighbour]) {
				distanceFromSource[neighbour] = distanceFromSource[curVertex] + neighbourDistance;
				weightedList.push(Node(neighbour, distanceFromSource[neighbour]));
			}
		}

	}
}

int main(int argc, char const *argv[])
{
	cout << "enter the number of vertex" << endl;

	int vertex;
	cin >> vertex;

	adjacency = new vector <Node> [vertex + 1];

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


	int startVertex;
	cout << "please enter the start vertex: ";
	cin >> startVertex;

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