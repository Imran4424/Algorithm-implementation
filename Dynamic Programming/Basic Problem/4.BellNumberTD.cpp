/*
	Bell Number is a number that determines how many partitions we can do in a set

	In this code, we will implement bell triangle to find bell number series

	https://en.wikipedia.org/wiki/Bell_number
*/ 

/*
	in this code, we are doing bottom up approach

	can correctly calculated upto 26
*/
#include <iostream>
#include <vector>
using namespace std;

typedef long long int lli; // covers 19 digit

vector< vector <lli> > belTriangle(101, vector <lli> (101, -1));

lli BellNumber(lli number, lli col)
{
	if (-1 != belTriangle[number][col])
	{
		return belTriangle[number][col];
	}

	if (0 == number && 0 == col)
	{
		return belTriangle[number][col] = 1;
	}

	if (0 == col)
	{
		return belTriangle[number][col] = BellNumber(number-1, number-1);
	}

	return belTriangle[number][col] = BellNumber(number, col-1) + BellNumber(number-1, col-1);
}


int main(int argc, char const *argv[])
{
	cout << "enter the nth term" << endl;

	lli n;
	cin >> n;

	

	for (lli i = 0; i < n; ++i)
	{

		cout << BellNumber(i, 0) << " ";
	}

	cout << endl;

	return 0;
}
