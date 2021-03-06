/*
	Top Down approach is also called Memorization
*/

#include <iostream>
using namespace std;

int *lookup;

void InitDp(int n)
{
	for (int i = 0; i <= n; ++i)
	{
		lookup[i] = -1;
	}
}

int Fibonacci(int n)
{
	if (-1 == lookup[n])
	{
		if (n <= 1)
		{
			lookup[n] = n; // this statement is for less than 2 values 
		}
		else
		{
			lookup[n] = Fibonacci(n-1) + Fibonacci(n-2); // this statement is for greater than or equal to 2 values
		}
		
	}

	return lookup[n];
}

int main(int argc, char const *argv[])
{
	cout << "enter the nth number" << endl;

	int n;
	cin >> n;

	lookup = new int[n+1];

	InitDp(n);

	cout << "The nth Fibonacci number is: " << Fibonacci(n) << endl;

	return 0;
}