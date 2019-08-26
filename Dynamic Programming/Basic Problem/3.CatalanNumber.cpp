/*
	Catalan number

	Formula, nth term = (2n)! / (n+1)! n!

			  = (1/(n+1)) * 2n C n

			  = (2n*(2n-1)*(2n-2)*...*(2n-n+1)) / (n+1)!

	https://en.wikipedia.org/wiki/Catalan_number
*/

#include <iostream>
#include <vector>
using namespace std;

typedef unsigned long long int ulli;

vector <int> fact(100, -1);
vector <int> combination(100, -1);

ulli ComibinationalHelper(ulli num, ulli endPoint)
{
	// if (-1 != combination[num])
	// {
	// 	return combination[num];
	// }

	if (endPoint == num)
	{
		return num;
	}

	return num * ComibinationalHelper(num - 1, endPoint);
}

ulli Factorial(ulli num) // dynamic recursive factorial 
{
	if (fact[num] >= 1)
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
	if (n == 0) // base case
	{
		cout << 1 << " ";
	}


	int result = ComibinationalHelper(2 * n, n+1) / (Factorial(n + 1));

	cout << result << " ";
}

int main(int argc, char const *argv[])
{
	fact[0] = 1;

	cout << "enter the nth term" << endl;

	ulli n;
	cin >> n;

	for (int i = 0; i <= n; ++i)
	{
		Catalan(i);
	}

	cout << endl;
	
	return 0;
}