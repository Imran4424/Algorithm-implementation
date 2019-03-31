#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int num)
{
	if(n <= 1)
	{
		return false;
	}

	for(int i=2; i <= sqrt(num); ++i)
	{
		if(num % i == 0)
		{
			return false;
		}
	}

	return true;
}

int main(int argc, char const *argv[])
{
	
	return 0;
}