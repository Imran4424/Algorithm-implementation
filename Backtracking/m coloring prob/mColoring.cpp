#include <iostream>
#include <vector>
#include <queue>
using namespace std;


int mColoring(vector<int> list[], vector<int> currentColor, int startNode) // multiple 1d vectors passing "list"
{
	int maxColorcount = 0;

	queue <int> currentList;

	currentColor[startNode] = 1;

	currentList.push(startNode);

	while(!currentList.empty())
	{
		int hand = currentList.front();
		currentList.pop();

		if (currentColor[hand] == -1)
		{
			map <int, int> adj;

			for (int i = 0; i < list[hand].size(); ++i)
			{
				if (currentColor[list[hand][i]] != -1)
				{
					adj[currentColor[list[hand][i]]] = 1;
				}
				else
				{
					currentList.push(list[hand][i]);
				}
			}
			
			int x = 1;

			while(adj.count(x) != 0)
			{
				x++;
			}

			if (x > maxColorcount)
			{
				maxColorcount = x;
			}

			currentColor[hand] = x;			
		}
		else
		{
			for (int i = 0; i < list[hand].size(); ++i)
			{
				if(currentColor[list[hand][i]] == -1)
				{
					currentList.push(list[hand][i]);
				}
			}
		}
	}

	return maxColorcount;
}


int main(int argc, char const *argv[])
{
	cout << "enter the number of vertices and edges" << endl;

	int vertices, edges;

	cin >> vertices >> edges;

	cout << "enter the adjacency node" << endl;


	vector <int> list[vertices+1]; // for starting the count from 1

	for (int i = 0; i < edges; ++i)
	{
		int a, b;

		cin >> a >> b;

		list[a].push_back(b);
		list[b].push_back(a);
	}

	vector <int> currentColor(vertices+1, -1);

	int maxColorcount =  mColoring(list, currentColor, 1);

	cout << "Total " << maxColorcount << "colors need to color the graph" << endl;

	return 0;
}


/*
	https://www.geeksforgeeks.org/m-coloring-problem-backtracking-5/

	geeksforgeeks problem

	Input

	10 15 - vetices and edges

	1 2
	1 3
	1 4
	2 5
	2 9
	3 6
	3 10
	4 7
	4 8
	5 6
	5 8
	6 7
	7 9
	8 10
	9 10
*/