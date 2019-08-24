#include <iostream>
#include <cmath>
using namespace std;

typedef unsigned long long int lli;

void GetNthUgly(lli n)
{
	lli ugly[n];
	lli i2 = 0, i3 = 0, i5 = 0;

	lli nextMultipleOf2 = 2;
	lli nextMultipleOf3 = 3;
	lli nextMultipleOf5 = 5;

	lli  nextUglyNo = 1;

	ugly[0] = 1;

	cout << nextUglyNo << " ";

	for (int i = 1; i < n; ++i)
	{
		nextUglyNo = min(nextMultipleOf2, min(nextMultipleOf3, nextMultipleOf5)); // a trick to use binary input functions

		ugly[i] = nextUglyNo;

		cout << nextUglyNo << " ";


		// here don't use if elseif else block
		// that will cause repetations
		if (nextUglyNo == nextMultipleOf2)
		{
			i2 = i2 + 1;

			nextMultipleOf2 = ugly[i2] * 2;
		}

		if(nextUglyNo == nextMultipleOf3)
		{
			i3 = i3 + 1;

			nextMultipleOf3 = ugly[i3] * 3;
		}
		if (nextUglyNo == nextMultipleOf5)
		{
			i5 = i5 + 1;

			nextMultipleOf5 = ugly[i5] * 5;
		}

	}
}

int main(int argc, char const *argv[])
{
	cout << "enter the nth term" << endl;

	lli n;
	cin >> n;

	GetNthUgly(n);

	return 0;
}