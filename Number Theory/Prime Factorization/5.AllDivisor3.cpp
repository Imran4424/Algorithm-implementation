#include <iostream>
#include <cmath>
#include <vector>
using namespace std;


void printAllDivisor(int num)
{
	vector <int> list;

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
				cout << i << " ";

				list.push_back(num / i);
			}
		}
	}

	for (int i = list.size() - 1; i >= 0; --i)
	{
		cout << list[i] << " ";
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