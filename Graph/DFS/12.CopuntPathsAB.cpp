#include <iostream>
#include <vector>
using namespace std;

vector <int> *adjacency;

void AddEdge(int u, int v)
{
	adjacency[u].push_back(v);
}

int main(int argc, char const *argv[])
{
	
	return 0;
}