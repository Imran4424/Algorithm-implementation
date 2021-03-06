/*
	0-1 knapsack problem is a dynamic programming problem

	this code implement top down approach

	Runtime: 0.110s
*/

#include <bits/stdc++.h> 
using namespace std; 


int maximumAllowedWeight, size;
int *weight, *value;

int totalValue; // almost all cases value is greater than weight

int dpVal[101][10001];

// A utility function that returns maximum of two integers 

int Max(int a, int b)
{
	if (a > b)
	{
		return a;
	}

	return b;
}

void Init()
{
	for(int m = 0; m <= size; m++)
	{
		for(int n = 0; n <= totalValue; n++)
		{
			dpVal[m][n] = -1;
		}
	}
}

// Returns the maximum value that 
// can be put in a KnapSack of capacity maximumAllowedWeight

int KnapSack(int currentObject, int currentWeight) 
{ 
	// Base cases

	if(currentObject >= size)
	{
		return 0;
	}

	// if solution exists then return the solution

	if (-1 != dpVal[currentObject][currentWeight])
	{
		return dpVal[currentObject][currentWeight];
	}

	int withProfit, withoutProfit;

	
	// here we are considering current object weight

	if (currentWeight + weight[currentObject] <= maximumAllowedWeight)
	{
		withProfit = value[currentObject] + KnapSack(currentObject + 1, currentWeight + weight[currentObject]);
	}
	else
	{
		withProfit = 0;
	}

	// here we are not considering current object weight

	withoutProfit = KnapSack(currentObject + 1, currentWeight);

	// now comparing and returning the max value among them

	return dpVal[currentObject][currentWeight] = Max(withProfit, withoutProfit);
} 


int main(int argc, char const *argv[])
{
	totalValue = 0;

	cout << "how many objects" << endl;

	cin >> size;

	weight = new int[size+1];
	value = new int[size+1];
	

	cout << "enter the value and weight" << endl;

	for (int i = 0; i < size; ++i)
	{
		cin >> value[i] >> weight[i];

		totalValue += value[i];
	}

	cout << "how much weight can carry" << endl;

	cin >> maximumAllowedWeight;

	Init(); // this is the right place to call init

	int maximum = KnapSack(0, 0);

	cout << "So maximum weight can you carry: " << maximum << endl;

	return 0;
}