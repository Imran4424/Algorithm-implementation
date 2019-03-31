#include <iostream>
#include <cmath>
using namespace std;


void printAllDivisor(int num)
{
	for (int i = 1; i <= sqrt(num); ++i)
	{
		if (num % i == 0)
		{
			if( num / i == i)
			{
				cout << i << " ";
			}
			else
			{
				cout << i << " " << num / i << " ";
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	
	return 0;
}