#include <iostream>
#include <vector>
using namespace std;



int main(int argc, char const *argv[])
{
	cout << "enter the number of vertices and edges" << endl;

	int vertices, edges;

	cin >> vertices >> edges;

	cout << "enter the adjacency node" << endl;

	vector <int> list[vertices];


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