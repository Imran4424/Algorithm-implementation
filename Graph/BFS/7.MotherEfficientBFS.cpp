/*
	Mother vertex - In graph mother vertex is that vertex or node, from which we can reach all other
	vertices in the graph

	In a graph there can more than one mother vertex

	In this we will print just one.

	In the case undirected graph all vertices are mother vertices

	But directed graph or undirected disconnected graph we need to find mother vertex.

	In this code, we will consider directed graph.

	......

	this is a efficient approach

	because when in naive approach we need

	totalVertex * one iteration time

	In this approach we will need 

	2 * one iteration time

	1 for finding
	1 for verifying
*/
#include <iostream>
#include <vector>
using namespace std;

vector <int> *adjacency;

void AddEdge(int u, int v) // directed graph
{
	adjacency[u].push_back(v);
}

void BFS(queue <int> &currentNodes, vector <bool> &visited) // this is recursive BFS
{
	
	// Base cases

	if (currentNodes.empty())
	{
		return;
	}

	int current = currentNodes.front();
	currentNodes.pop();	

	// cout << current << " ";

	// looking for adjacency nodes
	for(int k = 0; k < adj[current].size(); k++)
	{
		if (!visited[adj[current][k]])
		{
			currentNodes.push(adj[current][k]);

			visited[adj[current][k]] = true;
		}
	}

	BFS(currentNodes, visited);
}


int SearchMother(int startVertex ,int totalVertex)
{
	vector <bool> visited(totalVertex+1, false);

	int lastFinishedVertex = startVertex;

	/*
		Here, we are doing recursive function call

		at the end 

		all the vertex will visited if there is a mother vertex with one 
		iteration  time

		that saves lot of time
	*/

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
			if (!visited[i])
			{
				queue <in> currentNodes;

				currentNodes.push(i);

				visited[i] = true;

				BFS(currentNodes, visited);

				lastFinishedVertex = i;
			}
		}
	}
	else // this is for start count at 1
	{		
		for (int i = startVertex; i <= totalVertex; ++i)
		{
			if (!visited[i])
			{
				queue <in> currentNodes;

				currentNodes.push(i);

				visited[i] = true;

				BFS(currentNodes, visited);

				lastFinishedVertex = i;
			}
		}
	}

	/*
	   creating a new same size boolean vector array

	   for rechecking that

	   the lastFinishedVertex is mother vertex or not

	   actually in real scenario  we are checking that is there any mother vertex or not for the
	   inputed graph
	*/
	vector <bool> reVisited(totalVertex+1, false);

	// rechecking, this will cost one iteration time
	BFS(lastFinishedVertex, reVisited);

	//verifying

	if (0 == startVertex)
	{
		for (int i = startVertex; i < totalVertex; ++i)
		{
			if (!reVisited[i])
			{
				return -1;
			}
		}
	}
	else
	{		
		for (int i = startVertex; i <= totalVertex; ++i)
		{
			if (!reVisited[i])
			{
				return -1;
			}
		}
	}


	return lastFinishedVertex; // returning the mother vertex
}

int main(int argc, char const *argv[])
{
	cout << "enter the number of vertices" << endl;

	int vertex;
	cin >> vertex;

	adjacency = new vector <int> [vertex+1];  // taking an array of vector

	cout << "how many edges?" << endl;

	int edges;
	cin >> edges;

	int u,v;

	cout << "input the edges" << endl;

	for (int i = 0; i < edges; ++i)
	{
		cin >> u >> v;

		AddEdge(u, v);
	}

	int result = SearchMother(0, vertex);


	if (-1 == result)
	{
		cout << "there is no mother vertex" << endl;
	}
	else
	{
		cout << "Mother vertex is: " << result << endl;
 	}

	return 0;
}