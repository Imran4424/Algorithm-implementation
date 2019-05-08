#include <iostream>
#include <vector>
using namespace std;

typedef long long int lli;

vector<bool> Sieve(int num)
{
	vector<bool> prime(num+1, true);

	prime[0] = prime[1] = false;

	for(int i=2; i*i <= num; i++)
	{
		if(prime[i] == true)
		{
			for(int j=i*i; j<=num; j = j+i)
			{
				prime[j] = false;
			}
		}
	}

	return prime;
}

void PrintPrime(int start, int stop)
{
	vector <bool> prime = Sieve(stop);

	for(int i=start; i<=stop; i++)
	{
		if(prime[i])
		{
			cout << prime[i] << " ";
		}
	}

	cout << endl;
}

int main(int argc, char const *argv[])
{
	
	return 0;
}