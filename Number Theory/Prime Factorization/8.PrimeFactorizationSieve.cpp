#include <iostream>
#include <vector>
using namespace std;

typedef long long int lli;

vector <lli> prime;

const lli limit = 10001;

void Sieve()
{
	bool mark[limit + 1];

	memset(mark, true, sizeof(mark));

	mark[0] = mark [1] = false;

	for(lli p = 2; p*p <= limit; p++)
	{
		if (mark[p] == true)
		{
			for(lli i = p*p; i <= limit; i = i+p)
			{
				mark[i] = false;
			}
		}
	}


	for (lli i = 2; i <= limit; ++i)
	{
		if (mark[i])
		{
			prime.push_back(i);
		}
	}
}

void primeFactorization(lli num)
{
	for(lli i=0; i < prime.size(); i++)
	{
		if (num % i == 0)
		{
			cout << i << " ";
		}
	}

	cout << endl << endl;
}

int main(int argc, char const *argv[])
{
	cout << "enter any natural number" << endl;

	lli num;
	
	while(cin >> num)
	{
		primeFactorization(num);
		
		cout << "enter any  number" << endl;
	}

	return 0;
}