#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int *parent;

/*
	creating a class for holding the edges

	as

	customized datatype
*/

class EdgeInstance
{
	public: int source, destination, weight;

	public: bool operator <(const EdgeInstance& obj)
	{
		return weight < obj.weight;
	}
};

int MinimumSpanningTree(vector <EdgeInstance> edgeList)
{
	sort(edgeList.begin(), edgeList.end()); // ascending sort
}

int main(int argc, char const *argv[])
{
	cout << "enter the number of vertex" << endl;

	int vertex;
	cin >> vertex;

	parent = new int[vertex + 1];

	vector <EdgeInstance> edgeList;

	cout << "How many edges?" << endl;

	int edges;
	cin >> edges;

	EdgeInstance input;

	cout << "enter edges source, destination and weight" << endl;

	for (int i = 0; i < edges; ++i)
	{
		cin >> input.source >> input.destination >> input.weight;

		edgeList.push_back(input);
	}

	return 0;
}