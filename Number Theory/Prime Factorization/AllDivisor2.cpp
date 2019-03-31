#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
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
				list.push_back(i);
			}
			else // otherwise print both
			{
				list.push_back(i);
				list.push_back(num / i);
			}
		}
	}

	sort(list.begin(), list.end());

	for(int i = 0; i < list.size(); ++i)
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