/*
	In this code, we will implement permutation coefficient. This also known as permutation

	we know permutation rule for nPk is

	nPk = n! / (n-k)!

	recursive rule of permutaion is,

	P(n, k) = P(n-1, k) + k* P(n-1, k-1)

	P(n, 0) = 1
	P(n, 1) = n
	P(n, n) = n!
*/

/*
	In this code we will implement a old school method recursive
*/

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

typedef long long int lli;


lli PermutationCoefficient(lli number, lli combinations)
{
	if (/* condition */)
	{
		/* code */
	}
}

int main(int argc, char const *argv[])
{
	int test = 20;

	while(test--)
	{
		cout << "enter the n k" << endl;
		
		lli n, k;
		cin >> n >> k;

		cout << "The result of " << n << "C" << k << " is: " << PermutationCoefficient(n, k) << endl;

		cout << endl;
	}
	return 0;
}