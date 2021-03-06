/*
	In this code, we will implement binomial coefficient. This also known as combination

	we know combination rule for nCk is

	nCk = n! / (k!*(n-k)!)

	recursive rule of combination is,

	C(n, k) = C(n-1, k-1) + C(n-1, k)
	
	C(n, 0) = C(n, n) = 1
*/

/*
	In this code we will implement Top Down approach
*/

#include <iostream>
#include <vector>
using namespace std;

typedef long long int lli; // supports 19 digit

const int size = 101;

vector < vector <lli> > dpCombinations(size, vector <lli> (size, -1));

lli BinomialCoefficient(lli number, lli combinations)
{
	if (combinations > number)
	{
		return -1;
	}

	if (-1 != dpCombinations[number][combinations])
	{
		return dpCombinations[number][combinations];
	}

	if (0 == combinations || number == combinations)
	{
		return dpCombinations[number][combinations] = 1;
	}

	if (1 == combinations)
	{
		return dpCombinations[number][combinations] = number;
	}

	return dpCombinations[number][combinations] = BinomialCoefficient(number-1, combinations) + BinomialCoefficient(number-1, combinations-1);
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