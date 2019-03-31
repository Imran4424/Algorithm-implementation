#include <iostream>
using namespace std;

typedef long long int lli;

lli MyPow(lli base, lli expo, lli mod)
{
	lli result = 1;

	for(lli i = 1; i <= expo; i++)
	{
		result = (result * base) % mod;
	}

	return result;
}

bool isPrime(lli num, lli k = 25)
{
	if(num <= 1 || num == 4)
	{
		return false;
	}

	if (num <= 3)
	{
		return true;
	}

	// test k times
	while(k > 0)
	{
		// pick a random number between 2 and num-2

		int base = 2 + rand() % (num - 4);

		if (MyPow(base, num - 1, num) != 1)
		{
			return false;
		}

		k--;
	}

	return true;

}

int main(int argc, char const *argv[])
{
	cout << " enter any natural number" << endl;

	lli num;

	while(cin >> num)
	{
		if(isPrime(num))
		{
			cout << " Prime" << endl << endl;
		}
		else
		{
			cout << " Not Prime" << endl << endl;
		}

		cout << " enter any natural number" << endl;
	}

	
	return 0;
}