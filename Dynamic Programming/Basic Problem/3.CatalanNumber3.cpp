/*
	This is a recursive solution of catalan number

	this code implements the recursive euqation of catalan number

	Cn+1 = Ci*Cn-i

	adaption will be to Cn

	Cn = <Summation of <0 to n-1>> Ci*Cn-i-1

	https://en.wikipedia.org/wiki/Catalan_number
*/
#include <iostream>
using namespace std;

typedef unsigned long long int ulli

ulli Catalan(ulli num)
{
	if (1 >= num)
	{
		return 1;
	}

	ulli sum = 0;

	for (int i = 0; i < num; ++i)
	{
		sum = sum + Catalan(i) + Catalan(num - i - 1);
	}

	return sum;
}

int main(int argc, char const *argv[])
{

	cout << "enter the nth term" << endl;

	ulli n;
	cin >> n;

	for (ulli i = 0; i < n; ++i)
	{
		cout << Catalan(i) << " ";
	}

	cout << endl;
	
	return 0;
}