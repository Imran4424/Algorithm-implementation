#include <iostream>
using namespace std;

int Fibonacci(int n)
{
	if(n <= 1)
	{
		return n;
	}

	return Fibonacci(n - 1) + Fibonacci(n - 2);
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