#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector <int> *adjacency;

void AddEdge(int u, int v) // undirected graph
{
	adjacency[u].push_back(v);

	adjacency[v].push_back(u);
}

void TestDisplay(int startVertex, int totalVertex, vector <int> level)
{
	if (0 == startVertex) // this is for start count at 0
	{

		for (int i = startVertex; i < totalVertex; ++i)
		{
			cout << level[i] << " ";
		}

		cout << endl;
	}
	else // this is for start count at 1
	{		
		for (int i = startVertex; i <= totalVertex; ++i)
		{
			cout << level[i] << " ";
		}

		cout << endl;
	}
}

int BFS(int startVertex, int totalVertex, int searchLevel)
{
	vector <bool> visited(totalVertex + 1, false);

	vector <int> level(totalVertex + 1, 0);

	TestDisplay(startVertex, totalVertex, level);

	queue <int> currentNodes;
	currentNodes.push(startVertex);

	visited[startVertex] = true;
	level[startVertex] = 0;

	while(!currentNodes.empty())
	{
		int current = currentNodes.front();
		currentNodes.pop();

		for (int k = 0; k < adjacency[current].size(); ++k)
		{
			if (!visited[adjacency[current][k]])
			{
				level[adjacency[current][k]] = level[current] + 1;

				visited[adjacency[current][k]] = true;
			}
		}
	}

	TestDisplay(startVertex, totalVertex, level);
	
	int count = 0;

	/*
		this if condition is here because,

		some people start the vertex count at 0
		and
		some people start the vertex count at 1
	*/

	if (0 == startVertex) // this is for start count at 0
	{

		for (int i = startVertex; i < totalVertex; ++i)
		{
			if (searchLevel == level[i])
			{
				count++;
			}
		}
	}
	else // this is for start count at 1
	{		
		for (int i = startVertex; i <= totalVertex; ++i)
		{
			if (searchLevel == level[i])
			{
				count++;
			}
		}
	}

	return count;
}

int main(int argc, char const *argv[])
{
	cout << "enter the number of vertex" << endl;

	int vertex;
	cin >> vertex;
	
	adjacency = new vector <int> [vertex + 1];

	cout << "how many edges?" << endl;

	int edges;
	cin >> edges;

	cout << "enter the edges" << endl;
	int u, v;

	for (int i = 0; i < edges; ++i)
	{
		cin >> u >> v;

		AddEdge(u, v);
	}

	cout << "enter the level" << endl;

	int searchLevel;
	cin >> searchLevel;

	int levelVertex = BFS(0, vertex, searchLevel);

	cout << "total vertex in inputed level is: " << levelVertex << endl;

	return 0;
}