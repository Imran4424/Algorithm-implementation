#include <iostream>
#include <vector>
using namespace std;

/*
	A utility function to add edge for directed graph
*/
void AddEdge(vector <int> adjacency,int u, int v)
{
	adjacency[u].push_back(v);
}

void Display(vector<int> adjacency)
{
	for (int i = 0; i < adjacency.size(); ++i)
	{
		for (int j = 0; j < adjacency[i].size(); ++j)
		{
			cout << adjacency[i][j] << " ";
		}

		cout << endl;
	}


}


int main(int argc, char const *argv[])
{
	cout << "enter the vetex number" << endl;
	int vetex;
	cin >> vetex;

	vector <int> adjacency[vetex + 1]; // cause array strats count from zero

	AddEdge(adjacency, 1, 2); 
	AddEdge(adjacency, 1, 5); 
	AddEdge(adjacency, 2, 3); 
	AddEdge(adjacency, 2, 4); 
	AddEdge(adjacency, 2, 5); 
	AddEdge(adjacency, 3, 4); 
	AddEdge(adjacency, 4, 5); 

	printGraph(adjacency, V); 

	return 0;
}