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
		if (sumVal > maximum && sumWeight <= maximumAllowedWeight)
		{
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
	int rightWeight = dpWeight[i+1][sumWeight+value[i]];


	/*
		if both node satisfies take the maximum Allowed Weight

		then choose the maximum value
	*/
	if (leftWeight <= maximumAllowedWeight && rightWeight <= maximumAllowedWeight) 
	{
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
		dpVal[i][sumVal] = leftVal;
		dpWeight[i][sumWeight] = leftWeight;
	}
	else if (rightWeight <= maximumAllowedWeight)
	{
		dpVal[i][sumVal] = rightVal;
		dpWeight[i][sumWeight] = rightWeight;
	}
	else
	{
		if (leftWeight < rightWeight)
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

	for (int i = 0; i < size; ++i)
	{
		cin >> value[i] >> weight[i];

		totalValue += value[i];
	}

	cout << "how much weight can carry" << endl;

	cin >> maximumAllowedWeight;



	return 0;
}