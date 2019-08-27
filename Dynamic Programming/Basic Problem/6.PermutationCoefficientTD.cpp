/*
	In this code, we will implement permutation coefficient. This also known as permutation

	we know permutation rule for nPk is

	nPk = n! / (n-k)!

	recursive rule of permutaion is,

	P(n, k) = P(n-1, k) + k* P(n-1, k-1)

	P(n, 0) = 1
	P(n, 1) = n
*/

/*
	In this code we will implement Top Down approach
*/

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

typedef long long int lli;

const int size = 101;

vector < vector <lli> > dpPermutations(size, vector <lli> (size, -1));

lli PermutationCoefficient(lli number, lli combinations)
{
	if (-1 != dpPermutations[number][combinations])
	{
		return dpPermutations[number][combinations];
	}

	if (0 == combinations)
	{
		return dpPermutations[number][combinations] = 1;
	}

	if (1 == number)
	{
		return dpPermutations[number][combinations] = number;
	}

	return dpPermutations[number][combinations] = PermutationCoefficient(number-1, combinations) + (combinations *PermutationCoefficient(number-1, combinations-1));
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