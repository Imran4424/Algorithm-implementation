#include <iostream>
using namespace std;

typedef long long int lli;

bool isPrime(lli num, llli k = 25)
{
	if(num <= 1 || num == 4)
	{
		return false;
	}

	if (k <= 3)
	{
		return true;
	}

	// test k times


}

int main(int argc, char const *argv[])
{
	cout << " enter any natural number" << endl;

	lli num;

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