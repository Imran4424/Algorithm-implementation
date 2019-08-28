#include <iostream>
#include <list>
#include <queue>
using namespace std;

list <int> *adj;


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

	list <int> ::iterator itr;

	while(!currentNodes.empty())
	{
		int current = currentNodes.front();
		cout << current << " ";

		currentNodes.pop();

		for( itr = adj[current].begin(); itr != adj[current].end(); itr++)
		{
			if (!visited[*itr])
			{
				visited[*itr] = true;
				currentNodes.push(*itr);
			}
		}
	}
}


int main(int argc, char const *argv[])
{
	cout << "How many vertex of the graph" << endl;

	int vertex;
	cin >> vertex;

	adj = new list <int> [vertex];  // taking an array of list (doubly link list)

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