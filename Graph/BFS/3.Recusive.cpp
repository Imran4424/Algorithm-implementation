#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector <int> *adj;


void AddEdge(int u, int v)
{
	adj[u].push_back(v);
}

void BFS(queue <int> &currentNodes, vector <bool> &visited)
{
	
	// Base cases

	if (currentNodes.empty())
	{
		return;
	}

	int current = currentNodes.front();
	currentNodes.pop();	

	cout << current << " ";

	visited[current] = true;

	for(int k = 0; k < adj[current].size(); k++)
	{
		if (!visited[adj[current][k]])
		{
			currentNodes.push(adj[current][k]);
		}
	}

	BFS(currentNodes, visited);
}


int main(int argc, char const *argv[])
{
	cout << "How many vertex of the graph" << endl;

	int vertex;
	// cin >> vertex;

	vertex = 4;

	adj = new vector <int> [vertex+1];  // taking an array of vector

	AddEdge(1, 2); 
	AddEdge(2, 3); 
	AddEdge(0, 2); 
	AddEdge(2, 0); 
	AddEdge(3, 3); 
	AddEdge(0, 1); 

	cout << "Following is Breadth First Traversal "
		<< "(starting from vertex 2) \n";


	vector <bool> visited(vertex+1, false);

	int startVertex = 2;

	queue <int> currentNodes;

	currentNodes.push(startVertex);

	BFS(currentNodes, visited); 
	
	return 0;
}