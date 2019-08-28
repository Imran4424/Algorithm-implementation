int dpVal[101][10001];
int dpWeight[101][10001];

void Init()
{
	
}/*
	0-1 knapsack problem is a dynamic programming problem
*/

#include <iostream>
using namespace std;

int maxWeight, size, maximumAllowed = 0;
int *weight, *value, *bits;

int totalValue; // almost all cases value is greater than weight

int dpVal[101][10001];
int dpWeight[101][10001];

void Init()
{
	for (int i = 0; i <= size; ++i)
	{
		for (int i = 0; i <=  totalValue; ++i)
		{
			dpVal[i][j] = -1;
			dpWeight[i][j] = -1;
		}
	}
}


int Binary(int i, sumVal, sumWeight)
{
	if (dpVal[i][sumVal] >= 0 && dpVal[i][sumVal] >= 0)
	{
		return;
	}

	if (i == size)
	{
		return 
	}

	bits[i] = 0;
	Binary(i+1, sumVal, sumWeight);

	bits[i] = 1;
	Binary(i+1, sumVal+value[i], sumWeight+weight[i]);
}

int main(int argc, char const *argv[])
{
	totalValue = 0;

	cout << "how many objects" << endl;

	cin >> size;

	weight = new int[size+1];
	value = new int[size+1];
	bits = new int[size+1];

	for (int i = 0; i < size; ++i)
	{
		cin >> value[i] >> weight[i];

		totalValue += value[i];
	}

	cout << "how much weight can carry" << endl;

	cin >> maxWeight;



	return 0;
}