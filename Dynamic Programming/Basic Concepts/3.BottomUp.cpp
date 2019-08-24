/*
	This approach is also called tabulation

	because this appraoch is like creating table from 0 index
*/

#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	cout << "enter the nth number" << endl;

	int n;
	cin >> n;

	cout << "The nth Fibonacci number is: " << Fibonacci(n) << endl;
	
	return 0;
}

