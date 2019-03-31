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

	/*

		now the number is a odd number
		so starting from 3 and incrementing by 2 to check

		odd non-prime numbers will never encounter if that worries you

		cause

		9 will divide by 3
		15 will divide by 3, 5
		21 will divide by 3, 7
		25 will divide by 5
		and so on

		and they also divide the multiplies on non prime numbers

	*/


	for(int i = 3; i <= sqrt(num); i = i + 2)
	{
		while(num % i == 0)
		{
			cout << i << " ";

			num = num / i;
		}
	}

	/*
		This condition is for factorization of prime numbers
	*/

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