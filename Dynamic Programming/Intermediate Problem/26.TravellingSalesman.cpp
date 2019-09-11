#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair <int, int> couple;

vector <couple> *adjacency;

int minimunDistance, startVertex, totalVertex;

bool SortBySecond(const couple &a, const couple &b)
{
	return a.second < b.second;
}

void AddEdge(int source, int destination, int weight)
{
	adjacency[source].push_back(make_pair(destination, weight));
	adjacency[destination].push_back(make_pair(source, weight));
}

void DFS(int current, vector <bool> visited, int vertexCount, int pathCost)
{
	if(pathCost > minimunDistance)
	{
		return;
	}

	if (vertexCount == totalVertex)
	{

		for (int k = 0; k < adjacency[current].size(); ++k)
		{
			couple finalHelper = adjacency[current][k];

			if (finalHelper.first == startVertex)
			{
				if (pathCost + finalHelper.second < minimunDistance)
				{
					//cout << current << " " << finalHelper.second << endl;

					minimunDistance = pathCost + finalHelper.second;
				}

				k = adjacency[current].size();
			}
		}

		return;
	}


	for (int k = 0; k < adjacency[current].size(); ++k)
	{
		couple helper = adjacency[current][k];

		if (!visited[helper.first])
		{
			// cout << "inside non visited" << endl;

			visited[helper.first] = true;

			DFS(helper.first, visited, vertexCount+1, pathCost + helper.second);

		}

		// this backtrack is not needed in this sorted optimal solution
		// visited[helper.first] = false; // backtrack
	}
}


void Solve()
{
	for (int i = 0; i <= totalVertex; ++i)
	{
		sort(adjacency[i].begin(), adjacency[i].end(), SortBySecond);
	}


	minimunDistance = 32000;

	vector <bool> visited(totalVertex + 1, false);

	visited[startVertex] = true;
	DFS(startVertex, visited, 1, 0); // remember vertexcount starts from 1
                                        //  cause start vertex is also countable  
	cout << minimunDistance << endl;
}


int main(int argc, char const *argv[])
{
	cout << "enter the vertex number" << endl;

	int vertex;
	cin >> vertex;

	adjacency = new vector <couple> [vertex + 1];

	cout << "how many edges ?" <<endl;
	int edges;
	cin >> edges;

	int source, destination, weight;

	cout << "enter the edges " << endl;

	for (int i = 0; i < edges; ++i)
	{
		cin >> source >> destination >> weight;

		AddEdge(source, destination, weight);
	}

	startVertex = 1; // this one depend upon the vertex counting

	totalVertex = vertex;

	Solve();

	return 0;
}