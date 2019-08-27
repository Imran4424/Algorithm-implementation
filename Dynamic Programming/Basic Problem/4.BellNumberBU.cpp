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

typedef long long int lli;

// vector< vector <lli> > belTriangle(101, vector <lli> (101, -1));

lli BellNumber(lli number)
{
	lli belTriangle[number+1][number+1];

	belTriangle[0][0] = 1;

	for (lli i = 1; i <= number; ++i)
	{
		// filling for j = 0 means by copying from previous row's last element
		belTriangle[i][0] = belTriangle[i-1][i-1]; // both are i-1 one because every row same number of 
		                                            //  column the row number

		for(lli j=1; j<=i; j++)
		{
			belTriangle[i][j] = belTriangle[i][j-1] + belTriangle[i-1][j-1];
		}
	}

	return belTriangle[number][0];
}

int main(int argc, char const *argv[])
{
	cout << "enter the nth term" << endl;

	lli n;
	cin >> n;

	

	for (lli i = 0; i < n; ++i)
	{

		cout << BellNumber(i) << " ";
	}

	cout << endl;

	return 0;
}