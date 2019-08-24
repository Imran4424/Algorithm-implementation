/*
	This approach is also called tabulation

	because this appraoch is like creating table from 0 index
*/

#include <iostream>
using namespace std;

int Fibonacci(int n)
{
	int fib[n+1];

	fib[0] = 0;
	fib[1] = 1;

	for (int i = 2; i <= n; ++i)
	{
		fib[i] = fib[i - 1] + fib[i - 2];
	}

	return fib[n];
}

int main(int argc, char const *argv[])
{
	cout << "enter the nth number" << endl;

	int n;
	cin >> n;

	cout << "The nth Fibonacci number is: " << Fibonacci(n) << endl;

	return 0;
}

