#include <iostream>
using namespace std;

bool isPrime(int num)
{
	if(num <= 1)
	{
		return false;
	}

	if (num <= 3)
	{
		return true;
	}

	/*
		all integers can be expressed as (6k + i)
		
		here, i = -1, 0, 1, 2, 3, 4


		checking (6k + i)

		2 divides (6k + 0), (6k + 2), (6k + 4)
		3 divides (6k + 3)
	*/

	if(num % 2 == 0 || num % 3 == 0) 
	{
		return false;
	}

	for(int i = 5; i*i <= num; i = i + 6)
	{
		/*
			checking (6k - 1) and (6k + 1)
		*/

		if(num % i == 0 || num % (i+2) == 0)
		{
			return false;
		}
	}

	return true;
}

int main(int argc, char const *argv[])
{
	cout << " enter any natural number" << endl;

	int num;

	while(cin >> num)
	{
		if(isPrime(num))
		{
			cout << " Prime" << endl << endl;
		}
		else
		{
			cout << " Not Prime" << endl << endl;
		}

		cout << " enter any natural number" << endl;
	}
	
	return 0;
}