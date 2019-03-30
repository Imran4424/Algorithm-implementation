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
}

int main(int argc, char const *argv[])
{
	
	return 0;
}