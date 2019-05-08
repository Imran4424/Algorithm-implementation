#include <iostream>
#include <vector>
using namespace std;

vector<int> AllPrimeFactor(int num)
{
	vector <int> primeFactors;

	while(num % 2 == 0)
	{
		primeFactors.push_back(2);

		num /= 2;
	}

	for(int i=3; i*i <= num; i = i+2)
	{
		while(num % i == 0)
		{
			primeFactors.push_back(i);

			num /= i;
		}
	}

	if(num > 2)
	{
		primeFactors.push_back(num);
	}

	return primeFactors;
}


void KthPrimeFactor(int num, int k)
{
	vector <int> primeFactors = AllPrimeFactor(num);

	if(k <= primeFactors.size())
	{
		cout << k << "-th prime factor is: " << primeFactors[k-1] << endl;
	}
	else
	{

		cout << k << "-th prime factor is: " << -1 << endl;
	}
}


int main(int argc, char const *argv[])
{
	int num, k;

	cout << "enter any positive number and k value" << endl;

	while(cin >> num >> k)
	{
		KthPrimeFactor(num, k);

		cout << "enter any positive number and k value" << endl;
	}

	return 0;
}