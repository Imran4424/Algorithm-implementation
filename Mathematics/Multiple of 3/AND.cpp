#include <iostream>
using namespace std;

int IsMultipleOfThree(int n)
{
	int oddCount = 0;
	int evenCount = 0;

	/*
		checking the number is negative is negative or not

		if it is negative then making it positive
	*/

	if(n < 0)
	{
		n = -n;
	}

	if(n == 0)
	{
		return 1;
	}

	if(n == 1)
	{
		return 0;
	}

	while(n)
	{
		/*
			if the odd bit is set then increment odd counter
		*/

		if (n & 1)
		{
			oddCount++;
		}

		n = n >> 1;

		/*
			if the even bit is set then increment odd counter
		*/

		if(n & 1)
		{
			evenCount++;
		}

		n = n >> 1;
	}
}


int main(int argc, char const *argv[])
{
	

	return 0;
}