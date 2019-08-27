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
using namespace std;

typedef long long int lli;

lli endPoint;
bool status;


lli PermutationCoefficient(lli number, lli combinations)
{
	if (status)
	{
		endPoint = number - combinations + 1;

		status = false;
	}

	if (endPoint == number)
	{
		return number;
	}

	return number * PermutationCoefficient(number-1, combinations);
}

int main(int argc, char const *argv[])
{
	int test = 20;

	while(test--)
	{
		status = true; // for each test case

		cout << "enter the n k" << endl;
		
		lli n, k;
		cin >> n >> k;

		cout << "The result of " << n << "C" << k << " is: " << PermutationCoefficient(n, k) << endl;

		cout << endl;
	}
	return 0;
}