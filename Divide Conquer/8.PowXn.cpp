#include <iostream>
using namespace std;

typedef long long int lli;

lli Power(lli x, lli y)
{
	if (y == 0)
	{
		return 1;
	}
	else if (y % 2 == 0)
	{
		return Power(x, y/2) * Power(x, y/2);
	}
	else
	{
		return x * Power(x, y/2) * Power(x, y/2);
	}

}

int main(int argc, char const *argv[])
{


	int base, pow;



	return 0;
}