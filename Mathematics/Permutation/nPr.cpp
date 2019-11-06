#include <iostream>
using namespace std;

const int size = 4;

int visited[10];
int digit[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

// int targetArr[4] = {0, 0, 0, 0};

void InitVisited()
{
	for (int i = 0; i < 10; ++i)
	{
		visited[i] = 0;
	}
}

void Display(int permuArr[])
{
	for (int i = 0; i < 4; ++i)
	{
		cout << permuArr[i] << " ";
	}

	cout << endl;
}

void Permutation(int permuArr[], int index)
{
	if(4 == index)
	{
		Display(permuArr);

		return;
	}

	for (int i = 0; i < 10; ++i)
	{
		if (!visited[i])
		{
			visited[i] = 1;

			permuArr[index] = i;

			Permutation(permuArr, index + 1);

			visited[i] = 0; // backtracking
		}
	}
}


int main(int argc, char const *argv[])
{

	InitVisited();

	int permuArr[4];

	Permutation(permuArr, 0);

	return 0;
}