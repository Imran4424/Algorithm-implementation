#include <iostream>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

typedef pair <int, int> couple;

vector <int> *adjacency;

void AddEdge(int source, int destination, int weight)
{
	adjacency[source].push_back(make_pair(destination, weight));

	adjacency[destination].push_back(make_pair(source, weight));
}


int main(int argc, char const *argv[])
{
	cout << "enter the number of vertex" << endl;

	int vertex;
	cin >> vertex;

	adjacency = new vector <int> [vertex + 1];

	cout << "How many edges ?" << endl;

	int edges;
	cin >> edges;

	
	
	return 0;
}