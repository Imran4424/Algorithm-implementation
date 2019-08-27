/*
	Bell Number is a number that determines how many partitions we can do in a set

	In this code, we will implement bell triangle to find bell number series

	https://en.wikipedia.org/wiki/Bell_number
*/ 


#include <iostream>
#include <vector>
using namespace std;

typedef unsigned long long int ulli;

vector< vector <ulli> > belTriangle(101, vector <ulli> (101, -1));

ulli BellNumber(ulli number, ulli col)
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

	ulli n;
	cin >> n;

	

	for (ulli i = 0; i < n; ++i)
	{

		cout << BellNumber(i, 0) << " ";
	}

	cout << endl;

	return 0;
}
