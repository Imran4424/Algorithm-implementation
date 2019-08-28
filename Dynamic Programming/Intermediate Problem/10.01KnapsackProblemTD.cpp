/*
	0-1 knapsack problem is a dynamic programming problem
*/

#include <iostream>
using namespace std;

int maximumAllowedWeight, size, maximum;
int *weight, *value, *bits;

int totalValue; // almost all cases value is greater than weight

int dpVal[101][10001];
int dpWeight[101][10001];

void Init()
{
	for (int i = 0; i <= size; ++i)
	{
		for (int j = 0; j <=  totalValue; ++j)
		{
			dpVal[i][j] = -1;
			dpWeight[i][j] = -1;
		}
	}
}


void Binary(int i, int sumVal, int sumWeight)
{
	if (dpVal[i][sumVal] >= 0 && dpVal[i][sumVal] >= 0)
	{
		return;
	}

	if (i == size)
	{
		if (sumVal > maximum && sumWeight <= maximumAllowedWeight)
		{
			cout << "Hi max" << endl;

			maximum = sumVal;
		}

		dpVal[i][sumVal] = sumVal;

		dpVal[i][sumWeight] = sumWeight;

		return;
	}

	bits[i] = 0;
	Binary(i+1, sumVal, sumWeight);

	int leftVal = dpVal[i+1][sumVal];
	int leftWeight = dpWeight[i+1][sumWeight];

	bits[i] = 1;
	Binary(i+1, sumVal+value[i], sumWeight+weight[i]);

	int rightVal = dpVal[i+1][sumVal+ value[i]];
	int rightWeight = dpWeight[i+1][sumWeight+weight[i]];


	/*
		if both node satisfies take the maximum Allowed Weight

		then choose the maximum value
	*/
	if (leftWeight <= maximumAllowedWeight && rightWeight <= maximumAllowedWeight) 
	{
		cout << "Hi max all" << endl;

		if (leftVal > rightVal)
		{
			dpVal[i][sumVal] = leftVal;
			dpWeight[i][sumWeight] = leftWeight;
		}
		else
		{
			dpVal[i][sumVal] = rightVal;
			dpWeight[i][sumWeight] = rightWeight;
		}
	}
	else if(leftWeight <= maximumAllowedWeight)
	{
		cout << "Hi left" << endl;
		dpVal[i][sumVal] = leftVal;
		dpWeight[i][sumWeight] = leftWeight;
	}
	else if (rightWeight <= maximumAllowedWeight)
	{
		cout << "Hi right" << endl;

		dpVal[i][sumVal] = rightVal;
		dpWeight[i][sumWeight] = rightWeight;
	}
	else
	{
		cout << "Hi none" << endl;

		if (leftVal > rightVal)
		{
			dpVal[i][sumVal] = leftVal;
			dpWeight[i][sumWeight] = leftWeight;
		}
		else
		{
			dpVal[i][sumVal] = rightVal;
			dpWeight[i][sumWeight] = rightWeight;
		}
	}

}

int main(int argc, char const *argv[])
{
	totalValue = 0;
	maximum = 0;

	cout << "how many objects" << endl;

	cin >> size;

	weight = new int[size+1];
	value = new int[size+1];
	bits = new int[size+1];

	cout << "enter the value and weight" << endl;

	for (int i = 0; i < size; ++i)
	{
		cin >> value[i] >> weight[i];

		totalValue += value[i];
	}

	cout << "how much weight can carry" << endl;

	cin >> maximumAllowedWeight;

	Binary(0, 0, 0);

	cout << "So maximum weight can you carry: " << maximum << endl;

	return 0;
}