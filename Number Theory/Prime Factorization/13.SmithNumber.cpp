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

	
}

int main(int argc, char const *argv[])
{
	
	return 0;
}