#include <iostream>
#include <list>
#include <queue>
using namespace std;

list <int> *adj;


void AddEdge(int u, int v)
{
	adj[u].push_back(v);
}


int main(int argc, char const *argv[])
{
	cout << "How many vertex of the graph" << endl;

	int vertex;
	cin >> vertex;

	adj = new list <int> [vertex];  // taking an array of list (doubly link list)
	
	return 0;
}