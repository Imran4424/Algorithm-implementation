#include <iostream>
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

void SegmentedSieve()


int main(int argc, char const *argv[])
{
	
	return 0;
}