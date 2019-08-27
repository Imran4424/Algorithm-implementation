/*
	Catalan number

	Formula, nth term = (2n)! / (n+1)! n!

			  = (1/(n+1)) * 2n C n

			  = (2n*(2n-1)*(2n-2)*...*(2n-n+2)) / (n)!

	https://en.wikipedia.org/wiki/Catalan_number

	this code can calculate upto 15
*/

#include <iostream>
#include <vector>
using namespace std;

typedef unsigned long long int lli;

vector <lli> fact(100, -1);

lli CatalanHelper(lli num, lli endPoint)
{
	if (num == endPoint)
	{
		return num;
	}

	return num * CatalanHelper(num-1, endPoint);
}

lli Factorial(lli num) // dynamic recursive factorial 
{
	if (num == 1)
	{
		return fact[1] = 1;
	}

	if (fact[num] != -1)
	{
		return fact[num];
	}

	return fact[num] = num * Factorial(num - 1);
}

void Catalan(lli n)
{
	if (n == 0 || n == 1) // base case
	{
		cout << 1 << " ";

		return;
	}


	lli result = CatalanHelper(2 * n, n+2) / (Factorial(n));

	cout << result << " ";
}

int main(int argc, char const *argv[])
{
	fact[0] = 1;

	cout << "enter the nth term" << endl;

	lli n;
	cin >> n;

	for (lli i = 0; i < n; ++i)
	{
		Catalan(i);
	}

	cout << endl;
	
	return 0;
}