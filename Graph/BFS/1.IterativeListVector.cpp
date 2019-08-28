#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector <int> *adj;


void AddEdge(int u, int v)
{
	adj[u].push_back(v);
}

void BFS(int startVertex, int totalVertex)
{
	bool visited[totalVertex];

	for(int i = 0; i < totalVertex; i++)
	{
		visited[i] = false;
	}


	queue <int> currentNodes;

	visited[startVertex] = true;
	currentNodes.push(startVertex);

	while(!currentNodes.empty())
	{
		int current = currentNodes.front();
		cout << current << " ";

		currentNodes.pop();

		for(int k = 0; k < adj[current].size(); k++)
		{
			if (!visited[adj[current][k]])
			{
				visited[adj[current][k]] = true;
				currentNodes.push(adj[current][k]);
			}
		}
	}
}


int main(int argc, char const *argv[])
{
	cout << "How many vertex of the graph" << endl;

	int vertex;
	cin >> vertex;

	adj = new vector <int> [vertex+1];  // taking an array of vector

	AddEdge(1, 2); 
	AddEdge(2, 3); 
	AddEdge(0, 2); 
	AddEdge(2, 0); 
	AddEdge(3, 3); 
	AddEdge(0, 1); 

	cout << "Following is Breadth First Traversal "
		<< "(starting from vertex 2) \n"; 
	BFS(2, vertex); 
	
	return 0;
}