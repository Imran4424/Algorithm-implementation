#include <iostream>
#include <vector>
using namespace std;

int AllPrimeFactor(int num)
{
	int factorSum = 0;

	vector <int> primeFactors;

	while(num % 2 == 0)
	{
		primeFactors.push_back(2);

		factorSum += 2;

		num /= 2;
	}

	for(int i=3; i*i <= num; i = i + 2)
	{
		while(num % i == 0)
		{
			primeFactors.push_back(i);

			factorSum += i;

			num = num / i;
		}
	}

	if(num > 2)
	{
		primeFactors.push_back(num);

		factorSum += num;
	}

	return factorSum;
}

void SmithOrNot(int num)
{
	int factorSum = AllPrimeFactor(num);


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
	
	return 0;
}