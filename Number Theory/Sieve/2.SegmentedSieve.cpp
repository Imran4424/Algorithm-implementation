#include <iostream>
#include <cmath>
#include <vector>
#include <cstring>
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

}

void SegmentedSieve(int num)
{
	/*
		making the limit as sqrt of num
	*/

	int limit = floor(sqrt(num)) + 1;

	vector <int> prime;

	/*
		passing the first segment
	*/

	SieveOfEratosthenes(limit, prime);


	/*
		preparing the next segments
	*/

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


		/*
			using the prime list from sieve of eratothens function

			marking the numbers which is divisible by this primes 
		*/

		for (int i = 0; i < prime.size() ; ++i)
		{
			/*
				first finding the minimum number which is multiple of prime
				in [low...high] range

				for example if low is 27 and prime[i] = 2
				then we will start with 28
			*/

			int lowLimit = (low / prime[i]) * prime[i];

			if (lowLimit < low)
			{
				lowLimit = lowLimit + prime[i];
			}


			for (int j = lowLimit; j <= high; j = j + prime[i])
			{
				mark[j - low] = false;
			}
		}


		for (int i = low; i <= high; ++i)
		{
			if (mark[i - low])
			{
				cout << i << " ";
			}
		}

		/*
			preparing the next segments
		*/

		low = low + limit;
		high = high +limit;
	}


	cout << endl << endl;
}


int main(int argc, char const *argv[])
{
	cout << " enter any natural number" << endl;

	lli num;

	while(cin >> num)
	{
		cout << "The prime numbers that is less than or equal to " << num << " are" << endl;

		SegmentedSieve(num);

		cout << " enter any natural number" << endl;
	}

	return 0;
}