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

	

	

	return politeCount;
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