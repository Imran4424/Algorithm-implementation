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


int main(int argc, char const *argv[])
{
	
	return 0;
}