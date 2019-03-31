#include <iostream>
#include <cmath>
using namespace std;

typedef long long int lli;

lli sumOfAllProperDivisor(lli num)
{
	lli sum = 0;


	for(lli i = 2; i <= sqrt(num); i++)
	{
		if (num % i == 0)
		{
			if(num / i == i)
			{
				sum = sum + i;
			}
			else
			{
				sum = sum + i + (num / i);
			}
		}
	}


	// cause 1 is also a proper divisor
	return sum + 1;
}

int main(int argc, char const *argv[])
{
	cout << " enter any natural number " << endl;

	int num;

	while(cin >> num)
	{
		int result = sumOfAllProperDivisor(num);

		cout << "The sum is: " << result << endl << endl;

		cout << " enter any natural number " << endl;
	}
	
	return 0;
}