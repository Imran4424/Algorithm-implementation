/*
	This is a recursive solution of catalan number

	this code implements the recursive euqation of catalan number

	Cn+1 = Ci*Cn-i

	adaption will be to Cn

	Cn = <Summation of <0 to n-1>> Ci*Cn-i-1

	https://en.wikipedia.org/wiki/Catalan_number

	this code can conduct 37
*/
#include <iostream>
#include <vector>
using namespace std;

typedef unsigned long long int ulli; // supports 20 digit

ulli Catalan(ulli num)
{
	
}

int main(int argc, char const *argv[])
{

	cout << "enter the nth term" << endl;

	ulli n;
	cin >> n;

	catDp.resize(n+1, -1);

	for (ulli i = 0; i < n; ++i)
	{

		cout << Catalan(i) << " ";
	}

	cout << endl;
	
	return 0;
}