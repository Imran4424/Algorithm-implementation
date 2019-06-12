#include <iostream>
using namespace std;

typedef long long int lli;

lli Power(lli base, lli pow)
{
	if (0 == pow)
	{
		return 1;
	}

	lli hold = Power(base, pow/2);

	if (pow % 2 == 0)
	{
		return hold * hold;
	}
	else
	{
		return base * hold * hold;
	}
}

int main(int argc, char const *argv[])
{
	cout << "enter the base and pow" << endl;

	lli base, pow;
	cin >> base >> pow;

	cout << "Result is: " << Power(base, pow) << endl;

	return 0;
}