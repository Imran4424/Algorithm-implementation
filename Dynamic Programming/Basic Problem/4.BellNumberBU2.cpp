/*
	Bell Number is a number that determines how many partitions we can do in a set

	In this code, we will implement bell triangle to find bell number series

	https://en.wikipedia.org/wiki/Bell_number
*/ 

/*
	in this code, we are doing bottom up approach

	can correctly calculated upto 27

	more efficient
*/

#include <iostream>
#include <vector>
using namespace std;

typedef unsigned long long int ulli;

vector< vector <ulli> > belTriangle(101, vector <ulli> (101, -1));

ulli BellNumber(ulli number)
{

	belTriangle[0][0] = 1;

	for (ulli i = 1; i <= number; ++i)
	{
		if (belTriangle[i][0] != -1)
		{
			continue;
		}

		// filling for j = 0 means by copying from previous row's last element
		belTriangle[i][0] = belTriangle[i-1][i-1]; // both are i-1 one because every row same number of 
		                                            //  column the row number

		for(ulli j=1; j<=i; j++)
		{
			belTriangle[i][j] = belTriangle[i][j-1] + belTriangle[i-1][j-1];
		}
	}

	return belTriangle[number][0];
}

int main(int argc, char const *argv[])
{
	cout << "enter the nth term" << endl;

	ulli n;
	cin >> n;

	

	for (ulli i = 0; i < n; ++i)
	{

		cout << BellNumber(i) << " ";
	}

	cout << endl;

	return 0;
}