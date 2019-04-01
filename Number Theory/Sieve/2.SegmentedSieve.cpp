#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

typedef long long int lli;

void SieveOfEratosthenes(lli limit, vector <int> &prime)
{
	bool mark[limit + 1];

	/*
		memset sample syntax:

		memset(arr_name, value, sizeof(arr_name));
	*/

	memset(mark, true, sizeof(mark));

	mark[0] = mark[1] = false;

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


	for (int i = 2; i <= limit; ++i)
	{
		if (mark[i])
		{
			prime.push_back(i);

			cout << i << " ";
		}
	}

	cout << endl << endl;
}

void SegmentedSieve(int num)
{
	int limit = floor(sqrt(num)) + 1;

	vector <int> prime;

	SieveOfEratosthenes(limit, prime);


	int low = limit;
	int high = limit * 2;

	while(low < num)
	{
		if(high > num)
		{
			high = num;
		}


		bool mark[limit + 1];

		memset(mark, true, sizeof(mark));

		for (int i = 0; i < prime.size() ; ++i)
		{
			int lowLimit = (low / prime[i]) * prime[i];

			if (lowLimit < low)
			{
				lowLimit = lowLimit + prime[i];
			}


			for (int j = lowLimit; j < high; j = j + prime[i])
			{
				mark[j - low] = false;
			}
		}

		
		
	}
}


int main(int argc, char const *argv[])
{
	
	return 0;
}