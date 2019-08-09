#include <iostream>
#include <vector>
using namespace std;

void AddEdge(vector <int> adjacency,int u, int v)
{
	adjacency[u].push_back(v);
}

int main(int argc, char const *argv[])
{
	cout << "enter the vetex number" << endl;
	int vetex;
	cin >> vetex;

	vector <int> adjacency[vetex];

	AddEdge(adjacency, 0, 1); 
	AddEdge(adjacency, 0, 4); 
	AddEdge(adjacency, 1, 2); 
	AddEdge(adjacency, 1, 3); 
	AddEdge(adjacency, 1, 4); 
	AddEdge(adjacency, 2, 3); 
	AddEdge(adjacency, 3, 4); 

	printGraph(adjacency, V); 

	return 0;
}