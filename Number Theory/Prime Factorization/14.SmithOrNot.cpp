#include <iostream>
#include <vector>
using namespace std;

vector<bool> Sieve(int num)
{
	vector<bool> prime(num+1, true);

	prime[0] = prime[1] = false;

	for(int i=2; i*i <= num; i++)
	{
		if(prime[i] == true)
		{
			for(int j=i*i; j<=num; j = j+i)
			{
				prime[j] = false;
			}
		}
	}

	return prime;
}

vector <int> AllPrimeFactor(int num)
{
	vector <bool> prime = Sieve(num);

	vector <int> primeFactors;

	//int tnum = num;

	for(int i=2; i<=num; i++)
	{
		if(prime[i])
		{
			while(num % i == 0)
			{
				primeFactors.push_back(i);

				num /= i;
			}
		}
	}

	return primeFactors
}

void SmithOrNot(int num)
{
	vector <int> primeFactors = AllPrimeFactor(num);

	int factorSum = 0;

	for(int i=0; i < primeFactors.size(); i++)
	{
		int x = primeFactors[i];

		while(x)
		{
			int digit = x % 10;

			factorSum += digit;

			x = x / 10;
		}
	}


	int digitSum = 0;

	while(num)
	{
		int digit = num % 10;

		digitSum += digit;

		num = num / 10;
	}

	if (digitSum == factorSum)
	{
		cout << "Smith Number" << endl;
	}
	else
	{
		cout << "Not Smith Number" << endl;
	}
}


int main(int argc, char const *argv[])
{
	int num;

	cout << "enter any positive interger" << endl;

	while(cin >> num)
	{
		SmithOrNot(num);

		cout << "enter any positive interger" << endl;
	}

	return 0;
}