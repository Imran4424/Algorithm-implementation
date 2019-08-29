#include <iostream>
#include <vector>
using namespace std;

vector <int> *adjacency;

void AddEdge(int u, int v) // directed graph
{
	adjacency[u].push_back(v);
}

int main(int argc, char const *argv[])
{
	cout << "enter the number of vertex" << endl;

	int vertex;
	cin >> vertex;

	adjacency = new vector <int> [vertex + 1]; // array of vector

	cout << "How many edges?" << endl;
	
	return 0;
}