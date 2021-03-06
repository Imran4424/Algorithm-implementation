#include <iostream>
using namespace std;

int Politeness(int num)
{
	int politeCount = 1; // 1 for multiplying cause;

	// removing all even prime factor of num

	while(num % 2 == 0)
	{
		num /= 2;
	}

	// now num is an odd number

	for(int i=3; i*i <= num; i++)
	{
		int divCount = 0;

		// if i divides num, then start counting divisors

		while(num % i == 0)
		{
			num /= i;
			divCount++;
		}

		politeCount = (politeCount * divCount) + 1;
	}

	// if num odd prime still remains then count it

	if(num > 2)
	{
		politeCount *= 2;
	}
	

	return politeCount - 1; // subtracting the first one
}



int main(int argc, char const *argv[])
{
	int num;

	cout << "enter any positive integer" << endl;

	while(cin >> num)
	{
		cout << "Politeness of " << num << " is: " << Politeness(num) << endl;
		
		cout << "enter any positive integer" << endl;
	}

	return 0;
}