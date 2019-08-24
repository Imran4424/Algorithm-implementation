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

	
}

int main(int argc, char const *argv[])
{
	cout << "enter the nth number" << endl;

	int n;
	cin >> n;

	cout << "The nth Fibonacci number is: " << Fibonacci(n) << endl;

	return 0;
}

