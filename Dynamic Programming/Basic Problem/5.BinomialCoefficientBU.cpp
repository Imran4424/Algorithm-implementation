/*
	In this code, we will implement binomial coefficient. This also known as combination

	we know combination rule for nCk is

	nCk = n! / (k!*(n-k)!)

	recursive rule of combination is,

	C(n, k) = C(n-1, k-1) + C(n-1, k)
	
	C(n, 0) = C(n, n) = 1
*/

/*
	In this code we will implement Bottom Up approach
*/

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

typedef long long int lli;

const int size = 101;

vector < vector <lli> > dpCombinations(size, vector <lli> (size, -1));


lli BinomialCoefficient(lli number, lli combinations)
{
	for (lli i = 0; i <= number; ++i)
	{
		for (lli j = 0; j <= min(i, combinations); ++j)
		{
			// Base cases

			if (-1 != dpCombinations[i][j]) // checking if calculation already there or not
			{
				continue;
			}


			if (0 == j || i == j)
			{
				dpCombinations[i][j] = 1;

				continue;
			}

			if (1 == j)
			{
				dpCombinations[i][j] = i;
			}

			dpCombinations[i][j] = dpCombinations[i-1][j] + dpCombinations[i-1][j-1];

		}
	}

	return dpCombinations[number][combinations];
}

int main(int argc, char const *argv[])
{
	int test = 20;

	while(test--)
	{
		cout << "enter the n k" << endl;
		
		lli n, k;
		cin >> n >> k;

		cout << "The result of " << n << "C" << k << " is: " << BinomialCoefficient(n, k) << endl;

		cout << endl;
	}
	return 0;
}