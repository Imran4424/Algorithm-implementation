#include <iostream>
using namespace std;

bool isPrime(int num)
{
	if(num <= 1)
	{
		return false;
	}

	for(int i=2; i*i <= num; ++i)
	{
		if(num % i == 0)
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
			cout << "Prime" << endl << endl;
		}
		else
		{
			cout << "Not Prime" << endl << endl;
		}

		cout << " enter any natural number" << endl;
	}
	
	return 0;
}