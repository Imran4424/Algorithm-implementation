/*
	Problem Description :- Pair Sum Problem

	There is an array of integer values, find the pairs which sum will be equal to 
	a given K.

	Explanation:

	let assume, arr = [2, 1, 8, 6, -2, 5, 3, 0] and target K is 8

	so pairs will be  [2, 6], [8, 0], [5, 3]

	We will use hashing for this

	best case time complexity O(N)
	average case time complexity O(N)
	worst case time complexity O(N)

*/
#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;


// in this approach
// we don't get repeation of pairs like - {2, 6} and {6, 2} even if there are sigle 6 and single 2
// we don't get wrong pair like - {4, 4} even if there is only one 4 present in the array
vector< pair<int, int> > pairSum(vector<int> arr, int targetSum) {
	unordered_set<int> hashSet;
	vector< pair<int, int> > pairArr;

	for (int i = 0; i < arr.size(); i++) {
		int remain = targetSum - arr[i];
		if (hashSet.count(remain)) {
			pairArr.push_back({remain, arr[i]});
		}

		hashSet.insert(arr[i]);
	}

	return pairArr;
}

int main(int argc, char const *argv[])
{
	vector <int> arr{2, 1, 3, 0, 5, 6, -2, 4, 10};

	vector< pair<int, int> > returnedPair = pairSum(arr, 8);

	for (int i = 0; i < returnedPair.size(); i++) {
		cout << returnedPair[i].first << " " << returnedPair[i].second << endl;
	}

	return 0;
}