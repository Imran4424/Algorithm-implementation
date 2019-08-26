/*
	Catalan number

	Formula, nth term = (2n)! / (n+1)! n!

			  = (1/(n+1)) * 2n C n

			  = (2n*(2n-1)*(2n-2)*...*(2n-n+2)) / (n)!

	https://en.wikipedia.org/wiki/Catalan_number
*/

#include <iostream>
#include <vector>
using namespace std;

typedef unsigned long long int ulli;

vector <ulli> fact(100, -1);

ulli ComibinationalHelper(ulli num, ulli endPoint)
{
	ulli result = endPoint;

	while(endPoint <= num)
	{
		cout << result << endl;

		result = result * endPoint;

		cout << result << endl;
		
		endPoint++;
	}

	return result;
}

ulli Factorial(ulli num) // dynamic recursive factorial 
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

void Catalan(ulli n)
{
	if (n == 0 || n == 1) // base case
	{
		cout << 1 << " ";

		return;
	}


	ulli result = ComibinationalHelper(2 * n, n+2) / (Factorial(n));

	cout << result << " ";
}

int main(int argc, char const *argv[])
{
	fact[0] = 1;

	cout << "enter the nth term" << endl;

	ulli n;
	cin >> n;

	for (ulli i = 0; i <= n; ++i)
	{
		Catalan(i);
	}

	cout << endl;
	
	return 0;
}