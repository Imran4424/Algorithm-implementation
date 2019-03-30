#include <iostream>
#include <cmath>
using namespace std;

void primeFactors(int num)
{
	// print the number of 2's if it divide num

	while(num % 2 == 0)
	{
		cout << 2 << " ";

		num = num / 2 ;
	}

	for(int i = 3; i <= sqrt(num); i = i + 2)
	{
		while(num % i == 0)
		{
			cout << i << " ";

			num = num / i;
		}
	}

	if (num > 2)
	{
		cout << num << endl;
	}
}

int main(int argc, char const *argv[])
{
	
	return 0;
}