#include <iostream>
#include <vector>
using namespace std;

vector <int> prime;

const int limit = 10001;

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


	for (int i = 2; i <= num; ++i)
	{
		if (mark[i])
		{
			prime.push_back(i);
		}
	}
}

int main(int argc, char const *argv[])
{
	

	return 0;
}