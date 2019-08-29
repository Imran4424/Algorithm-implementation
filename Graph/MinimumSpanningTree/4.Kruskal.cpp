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

class Edges
{
	public: int source, destination, weight;

	public: bool operator <(const Edges& obj)
	{
		return weight < obj.weight;
	}
};

int main(int argc, char const *argv[])
{
	cout << "enter the number of vertex" << endl;

	int vertex;
	cin >> vertex;

	parent = new int[vertex + 1];

	return 0;
}