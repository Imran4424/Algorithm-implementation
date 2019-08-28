/*
	0-1 knapsack problem is a dynamic programming problem
*/

#include <iostream>
using namespace std;

int maximumAllowedWeight, size, maximum = 0;
int *weight, *value, *bits;


void Binary(int i, int sumVal, int sumWeight)
{
	if (i == size)
	{
		if (sumVal > maximum && sumWeight <= maximumAllowedWeight)
		{
			maximum = sumVal;
		}

		return;
	}

	bits[i] = 0;
	Binary(i+1, sumVal, sumWeight);

	bits[i] = 1;
	Binary(i+1, sumVal+value[i], sumWeight+weight[i]);
}

int main(int argc, char const *argv[])
{
	cout << "how many objects" << endl;

	cin >> size;

	weight = new int[size+1];
	value = new int[size+1];
	bits = new int[size+1];

	cout << "enter the value and weight" << endl;

	for (int i = 0; i < size; ++i)
	{
		cin >> value[i] >> weight[i];
	}

	cout << "how much weight can carry" << endl;

	cin >> maximumAllowedWeight;

	Binary(0, 0, 0);

	cout << "So maximum weight can you carry: " << maximum << endl;

	return 0;
}