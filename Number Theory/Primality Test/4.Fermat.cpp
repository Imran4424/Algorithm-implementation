#include <iostream>
using namespace std;

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