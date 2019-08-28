/* A Naive recursive implementation of 0-1 Knapsack problem */
#include <bits/stdc++.h> 
using namespace std; 

// A utility function that returns maximum of two integers 

int max(int a, int b)
{
	if (a > b)
	{
		return a;
	}

	return b;
}

// Returns the maximum value that 
// can be put in a knapsack of capacity W 
int knapSack(int W, int wt[], int val[], int n) 
{ 
	
// Base Case 
if (n == 0 || W == 0) 
	return 0; 

// If weight of the nth item is more 
// than Knapsack capacity W, then 
// this item cannot be included 
// in the optimal solution 
if (wt[n-1] > W) 
	return knapSack(W, wt, val, n-1); 

// Return the maximum of two cases: 
// (1) nth item included 
// (2) not included 
else return max( val[n-1] + knapSack(W-wt[n-1], wt, val, n-1), 
					knapSack(W, wt, val, n-1) ); 
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

	Init(); // this is the right place to call init

	Binary(0, 0, 0);

	cout << "So maximum weight can you carry: " << maximum << endl;

	return 0;
}