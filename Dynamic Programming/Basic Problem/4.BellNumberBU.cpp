/*
	Bell Number is a number that determines how many partitions we can do in a set

	In this code, we will implement bell triangle to find bell number series

	https://en.wikipedia.org/wiki/Bell_number
*/ 

#include <iostream>
using namespace std;

typedef long long int lli;

vector< vector <lli> > belltriangle(101, vector <lli> (101, -1));

lli BellNumber(lli number)
{

}

int main(int argc, char const *argv[])
{
	cout << "enter the nth term" << endl;

	ulli n;
	cin >> n;

	

	for (ulli i = 0; i < n; ++i)
	{

		cout << Catalan(i) << " ";
	}

	cout << endl;

	return 0;
}