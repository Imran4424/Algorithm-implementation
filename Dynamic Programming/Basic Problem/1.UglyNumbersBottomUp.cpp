#include <iostream>
#include <cmath>
using namespace std;

typedef long long int lli;

void GetNthUgly(lli n)
{
	lli ugly[n];
	lli i2 = 0, i3 = 0, i5 = 0;

	lli nextMultipleOf2 = 2;
	lli nextMultipleOf3 = 3;
	lli nextMultipleOf5 = 5;

	lli  nextUglyNo = 1;

	ugly[0] = 1;

	cout << ugly[0] << " ";

	for (int i = 0; i < n; ++i)
	{
		nextUglyNo = min(nextMultipleOf2, min(nextMultipleOf3, nextMultipleOf5));

		ugly[i] = nextUglyNo;

		cout << nextUglyNo << " ";

		if (nextUglyNo == nextMultipleOf2)
		{
			i2 = i2 + 1;

			nextMultipleOf2 = ugly[i2] * 2;
		}
		else if(nextUglyNo == nextMultipleOf3)
		{
			i3 = i3 + 1;

			nextMultipleOf3 = ugly[i3] * 3;
		}
		else if (nextUglyNo == nextMultipleOf5)
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