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
using namespace std;

int main(int argc, char const *argv[])
{
	
	return 0;
}