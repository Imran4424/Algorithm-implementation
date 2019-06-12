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
		/* co
	}
}