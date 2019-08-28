#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector <int> *adj;


void AddEdge(int u, int v)
{
	adj[u].push_back(v);
}

void BFS(int startVertex, vector <bool> &visited)
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


	vector <bool> visited(totalVertex+1, false);

	int startVertex = 2;

	queue <int> currentNodes;

	currentNodes.push(startVertex);

	BFS(); 
	
	return 0;
}