/*
	This is a recursive solution of catalan number

	this code implements the recursive euqation of catalan number

	Cn+1 = Ci*Cn-i

	adaption will be to Cn

	Cn = <Summation of <0 to n-1>> Ci*Cn-i-1

	https://en.wikipedia.org/wiki/Catalan_number

	this code can conduct 36
*/
#include <iostream>
#include <vector>
using namespace std;

typedef long long int lli; // supports 19 digit

lli Catalan(lli num)
{
	vector <lli> catDp(num+1);

	catDp[0] = catDp[1] = 1;

	for (int i = 2; i <= num; ++i)
	{
		catDp[i] = 0;

		for (int j = 0; j < i; ++j)
		{
			catDp[i] += catDp[j] * catDp[i-j-1];
		}

	}

	return catDp[num];
}

int main(int argc, char const *argv[])
{

	cout << "enter the nth term" << endl;

	lli n;
	cin >> n;

	

	for (lli i = 0; i < n; ++i)
	{

		cout << Catalan(i) << " ";
	}

	cout << endl;
	
	return 0;
}