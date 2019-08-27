/*
	In this code, we will implement binomial coefficient. This also known as combination

	we know combination rule for nCk is

	nCk = n! / (k!*(n-k)!)
*/

/*
	In this code we will implement Top Down approach
*/

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

typedef long long int lli;

const int size = 101;

vector < vector <lli> > dpCombinations(size, vector <lli> (size, -1));