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
	
	return 0;
}