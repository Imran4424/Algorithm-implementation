/*
	This is  an iterative approach of DFS graph traversal

	here we used vector as adjacencyacency list
*/
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

list <int> *adjacency;


void AddEdge(int u, int v)
{
	adjacency[u].push_back(v);
}

void BFS(int startVertex, int totalVertex)
{
	bool visited[totalVertex + 1];

	for(int i = 0; i <= totalVertex; i++)
	{
		visited[i] = false;
	}


	stack <int> currentNodes;

	currentNodes.push(startVertex);


	while(!currentNodes.empty())
	{
		int current = currentNodes.top();
		currentNodes.pop();

		if (!visited[current])
		{
			cout << current << " ";

			visited[current] = true;
		}

		for(int k = 0 ; k < adjacency[current].size(); k++)
		{
			if (!visited[adjacency[current][k]])
			{
				currentNodes.push(adjacency[current][k]);
			}
		}
	}
}


int main(int argc, char const *argv[])
{
	cout << "How many vertex of the graph" << endl;

	int vertex;
	cin >> vertex;

	adjacencyacency = new vector <int> [vertex + 1];  // taking a array of vector

	AddEdge(2, 3); 
	AddEdge(3, 4); 
	AddEdge(1, 3); 
	AddEdge(3, 1); 
	AddEdge(4, 4); 
	AddEdge(1, 2); 

	cout << "Following is Breadth First Traversal "
		<< "(starting from vertex 2) \n"; 
	BFS(3, vertex); 
	
	return 0;
}