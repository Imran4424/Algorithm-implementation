#include <iostream>
using namespace std;


typedef long long int lli;


lli Multipication(lli x, lli y)
{
	/* Base Condition */

	if(y == 0)
	{
		return 0;
	}

	/* Adding x one by one until y is 0 */

	if(y > 0)
	{
		return (x + Multipication(x, y - 1));
	}

	/*  */

	if (y < 0)
	{
		return - (Multipication(x, -y));
	}
}