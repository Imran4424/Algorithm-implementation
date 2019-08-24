#include <iostream>
#include <cmath>
using namespace std;

typedef long long int lli;

void GetNthUgly(lli n)
{
	lli ugly[n];
	lli i2 = 0, i3 = 0, i5 = 0;

	lli nexMultipleOf2 = 2;
	lli nexMultipleOf3 = 3;
	lli nexMultipleOf5 = 5;
}

int main(int argc, char const *argv[])
{
	cout << "enter the nth term" << endl;

	lli n;
	cin >> n;

	GetNthUgly(n);

	return 0;
}