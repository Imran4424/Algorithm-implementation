#include <iostream>
#include <cmath>
using namespace std;

void printAllPrimeFactors(int num)
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
		cout << num ;
	}

	cout << endl << endl;
}

int main(int argc, char const *argv[])
{
	cout << "enter any  number" << endl;

	int num;
	
	while(cin >> num)
	{
		printAllPrimeFactors(num);
		
		cout << "enter any  number" << endl;
	}


	return 0;
}