/*
	In this code, we will implement binomial coefficient. This also known as combination

	we know combination rule for nCk is

	nCk = n! / (k!*(n-k)!)
*/

/*
	In this code we will implement Bottom Up approach
*/

#include <iostream>
#include <vector>
using namespace std;

typedef long long int lli;

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