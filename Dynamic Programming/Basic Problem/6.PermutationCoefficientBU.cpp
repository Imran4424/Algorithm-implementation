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
	for (lli i = 0; i <= number; ++i)
	{
		for (lli j = 0; j < min(i, combinations); ++j)
		{
			// if (-1 != dpPermutations[i][j])
			// {
			// 	continue;
			// }

			if (0 == j)
			{
				dpPermutations[i][j] = 1;

				continue;
			}

			if (1 == j)
			{
				dpPermutations[i][j] = i;

				continue;
			}

			dpPermutations[i][j] = dpPermutations[i-1][j] + (j * dpPermutations[i-1][j-1]);


			dpPermutations[i][j+1] = 0;
		}
	}

	return dpPermutations[number][combinations];
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