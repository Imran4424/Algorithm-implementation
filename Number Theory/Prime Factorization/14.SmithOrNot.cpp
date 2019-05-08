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

void SmithOrNot(int num)
{
	vector <bool> prime = Sieve(num);

	int factorSum = 0;

	for(int i=2; i <= num; i++)
	{
		while(num % i == 0)
		{
			if(prime[i])
			{
				int pfNum = i;

				while(pfNum)
				{
					int digit = pfNum % 10;

					factorSum += digit;

					pfNum = pfNum / 10;
				}
			}
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