#include <iostream>
using namespace std;

typedef long long int lli;

void SieveOfEratosthenes(lli num)
{
	bool prime[num + 1];

	/*
		memset sample syntax:

		memset(arr_name, value, sizeof(arr_name));
	*/

	memset(prime, true, sizeof(prime));

	prime[0] = prime[1] = false;

	for(lli p = 2; p*p <= num; p++)
	{
		if (prime[p] == true)
		{
			for(lli i = p*p; i <= num; i = i+p)
			{
				prime[i] = false;
			}
		}
	}


	for (int i = 2; i <= num; ++i)
	{
		if (prime[i])
		{
			cout << i << " ";
		}
	}

	cout << endl << endl;
}

int main(int argc, char const *argv[])
{
	cout << " enter any natural number" << endl;

	lli num;

	while(cin >> num)
	{
		cout << "The prime numbers that smaller than " << num << " are" << endl;

		SieveOfEratosthenes(num);

		cout << " enter any natural number" << endl;
	}
	
	return 0;
}