#include <iostream>
#include <list>
using namespace std;

/*
	A utility function to add edge for directed graph
*/
void AddEdge(list <int> adjacency[],int u, int v) // remember this is a list array
{
	adjacency[u].push_back(v);
	adjacency[v].push_back(u);
}

void Display(list <int> adjacency[], int vetex) // remember this is a list array
{
	for (int i = 1; i <= vetex; ++i)
	{
		cout << i << ": ";

		list <int> :: iterator it;

		for (it = adjacency[i].begin(); it != adjacency[i].end(); ++it) 
		{
			cout << *it << " ";
		}

		cout << endl;
	}


}


int main(int argc, char const *argv[])
{
	// cout << "enter the vetex number" << endl;
	int vetex = 5;
	// cin >> vetex;

	// remember this is a vector array
	list <int> adjacency[vetex + 1]; // cause array strats count from zero
	// list <int> *adjacency; // cause array strats count from zero

	AddEdge(adjacency, 1, 2); 
	AddEdge(adjacency, 1, 5); 
	AddEdge(adjacency, 2, 3); 
	AddEdge(adjacency, 2, 4); 
	AddEdge(adjacency, 2, 5); 
	AddEdge(adjacency, 3, 4); 
	AddEdge(adjacency, 4, 5); 

	Display(adjacency, vetex);

	return 0;
}

/*
	This code demontrate adjacency list for undirected graph
*/