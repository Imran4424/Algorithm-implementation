#include <iostream>
using namespace std;

double BabylonianRoot(double num)
{

	/* I Initialize */

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
	int num;
	cin >> num;


	cout << "Square root of " << num << " is: " << BabylonianRoot(num) << endl;
	
	return 0;
}