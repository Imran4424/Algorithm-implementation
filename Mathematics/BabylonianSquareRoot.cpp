#include <iostream>
using namespace std;

double BabylonianRoot(double num)
{
	double x = num;
	double y = 1;

	double e = 0.000001; /* e decides the accuracy level */

	while(x - y > e)
	{
		x = (x + y)/2;
		y = num / x;
	}

	return x;
}


int main(int argc, char const *argv[])
{
	
	return 0;
}