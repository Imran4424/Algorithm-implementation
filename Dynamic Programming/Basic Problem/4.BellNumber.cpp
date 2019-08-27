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

