/*
	https://www.geeksforgeeks.org/greedy-algorithm-egyptian-fraction/

	Every positive fraction can be represented as sum of unique unit fractions. 
	A fraction is unit fraction if numerator is 1 and denominator is a positive 
	integer, for example 1/3 is a unit fraction. Such a representation is called 
	Egyptian Fraction as it was used by ancient Egyptians.

	Following are few examples:

	Egyptian Fraction Representation of 2/3 is 1/2 + 1/6
	Egyptian Fraction Representation of 6/14 is 1/3 + 1/11 + 1/231
	Egyptian Fraction Representation of 12/13 is 1/2 + 1/3 + 1/12 + 1/156

*/

#include <iostream>
using namespace std;

void PrintEgyptian(int numerator, int denominator)
{
	// base cases
	if (0 == numerator || 0 == denominator)
	{
		return;		
	}
}

int main(int argc, char const *argv[])
{
	cout << "enter numerator and denominator" << endl;

	int numerator, denominator;
	cin >> numerator >> denominator;



	return 0;
}