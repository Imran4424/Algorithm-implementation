#include <iostream>
#include <cmath>
using namespace std;


void printAllDivisor(int num)
{
	for (int i = 1; i <= sqrt(num); ++i)
	{
		if (num % i == 0)
		{

			// if the divisors are equal print one

			if( num / i == i)
			{
				cout << i << " ";
			}
			else // otherwise print both
			{
				cout << i << " " << num / i << " ";
			}
		}
	}

	cout << endl << endl;
}

int main(int argc, char const *argv[])
{
	cout << "enter any natural number" << endl;

	int num;

	while ( cin >> num)
	{
		printAllDivisor(num);

		cout << "enter any natural number" << endl;
	}
	
	return 0;
}