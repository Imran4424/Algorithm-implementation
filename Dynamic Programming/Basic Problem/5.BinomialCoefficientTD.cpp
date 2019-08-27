/*
	In this code, we will implement binomial coefficient. This also known as combination

	we know combination rule for nCk is

	nCk = n! / (k!*(n-k)!)
*/

#include <iostream>
#include <vector>
using namespace std;

typedef long long int lli;

const int size = 101;

vector < vetor <lli> > dpCombinations(size, vector <int> (size, -1));

lli BinomialCoefficient(lli number, lli combinations)
{
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

	
}

int main(int argc, char const *argv[])
{
	while(1)
	{
		cout << "enter the n k" << endl;
		
		lli n, k;
		cin >> n >> k;

		cout << "The result of " << n << "C" << k << " is: " << 
	}
	return 0;
}