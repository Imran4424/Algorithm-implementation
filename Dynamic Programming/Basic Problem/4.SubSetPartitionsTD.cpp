/*
	Input: n = 3, k = 2
	Output: 3
	Explanation: Let the set be {1, 2, 3}, we can partition
	             it into 2 subsets in following ways
	             {{1,2}, {3}},  {{1}, {2,3}},  {{1,3}, {2}}  

	Input: n = 3, k = 1
	Output: 1
	Explanation: There is only one way {{1, 2, 3}}

	recursive rule: S(n, k) = k*S(n-1, k) + S(n-1, k-1) 

	https://www.geeksforgeeks.org/count-number-of-ways-to-partition-a-set-into-k-subsets/
*/

#include <iostream>
#include <vector>
using namespace std;

typedef long long int lli; // supports 19 digit

vector< vector<lli> > dpCount(101, vector <lli> (101, -1) );

lli CountPartitions(lli memNum, lli subsetNum)
{
	// Base cases
	if (dpCount[memNum][subsetNum] != -1)
	{
		return dpCount[memNum][subsetNum];
	}

	if (0 == memNum || 0 == subsetNum || memNum < subsetNum)
	{
		return dpCount[memNum][subsetNum] = 0;
	}

	if (1 == subsetNum || memNum == subsetNum)
	{
		return dpCount[memNum][subsetNum] = 1;
	}

	return dpCount[memNum][subsetNum] = subsetNum * CountPartitions(memNum-1, subsetNum) + CountPartitions(memNum-1, subsetNum-1);
}

int main(int argc, char const *argv[])
{
	while(1)
	{
		cout << "enter the member number subset number" << endl;

		lli memNum, subsetNum;
		cin >> memNum >> subsetNum;
		
		cout << "number of partition: " << CountPartitions(memNum, subsetNum) << endl << endl;
	}

	return 0;
}