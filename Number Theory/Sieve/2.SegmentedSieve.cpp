#include <iostream>
using namespace std;

typedef long long int lli;

void SieveOfEratosthenes(lli limit, vector <int> &prime)
{
	bool mark[num + 1];

	/*
		memset sample syntax:

		memset(arr_name, value, sizeof(arr_name));
	*/

	memset(mark, true, sizeof(mark));

	mark[0] = mark[1] = false;

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
	
	return 0;
}