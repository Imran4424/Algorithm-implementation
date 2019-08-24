/*
	Top Down approach is also called Memorization
*/

#include <iostream>
using namespace std;

int Fibonacci(int n)
{
	if (n <= 1)
	{
		return n;
	}
}

int main(int argc, char const *argv[])
{
	cout << "enter the nth number" << endl;

	int n;
	cin >> n;

	int result = Fibonacci(n);

	cout << "The nth Fibonacci number is: " << result << endl;

	return 0;
}