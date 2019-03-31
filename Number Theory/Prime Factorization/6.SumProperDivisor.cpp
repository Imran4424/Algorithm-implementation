#include <iostream>
using namespace std;

typedef long long int lli;

lli sumOfAllProperDivisor(lli num)
{
	lli endPoint, sum = 0;

	if(num % 2 == 0)
	{
		endPoint = num / 2;
	}
	else
	{
		endPoint = num / 3;
	}

	for(lli i = 1; i < endPoint; i++)
	{
		if (num % i == 0)
		{
			sum = sum + i;
		}
	}

	return sum;
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