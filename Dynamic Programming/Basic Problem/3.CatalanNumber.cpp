/*
	Catalan number

	Formula, nth term = (2n)! / (n+1)! n!
*/

#include <iostream>
#include <vector>
using namespace std;

typedef unsigned long long int ulli;

vector <int> fact(100, -1);

ulli Factorial(ulli num) // dynamic recursive factorial 
{
	if (fact[num] >= 0)
	{
		return fact[num];
	}

	if (num == 1)
	{
		return fact[1] = 1;
	}

	return fact[num] = num * Factorial(num - 1);
}

void Catalan(ulli n)
{

	int result = Factorial(2 * n) / (Factorial(n + 1) * Factorial(n));

	cout << result << " ";
}

int main(int argc, char const *argv[])
{
	fact[0] = 1;

	cout << "enter the nth term" << endl;

	ulli n;
	cin >> n;

	for (int i = 1; i <= n; ++i)
	{
		Catalan(i);
	}

	cout << endl;
	
	return 0;
}