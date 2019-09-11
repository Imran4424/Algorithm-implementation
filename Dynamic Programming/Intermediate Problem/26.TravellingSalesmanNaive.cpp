#include <iostream>
#include <utility>
using namespace std;

typedef pair <int, int> couple;

vector <couple> *adjacency;

int main(int argc, char const *argv[])
{
	int vertex;
	cin >> vertex;

	adjacency = new vector <couple> [vertex + 1];

	return 0;
}