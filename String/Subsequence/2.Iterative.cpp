#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <cmath>
using namespace std;

// function to print all possible non empty subsequences
void allPossibleSubSequence(string str) {
	// set will store all substring lexicographically 
	// map will store all substring by length
	map<int, set<string> > sortedSubSequence;

	// if string length is n
	// total number of subsequence is 2^n - 1
	int totalSubsequence = pow(2, str.size());

	for (int i = 1; i < totalSubsequence; i++) {
		string subsequence;

		for (int j = 0; str[j]; j++) {
			// check if jth bit in binary is 1 or not
			if (i & (1 << j)) {
				subsequence += str[j];
			}
		}

		sortedSubSequence[subsequence.size()].insert(subsequence);
	}

	for (auto mapIt : sortedSubSequence) {
		cout << "subsequence of length " << mapIt.first << " are:" << endl;

		for (string sub : mapIt.second) {
			cout << sub << endl;
		} 

		cout << endl;
	}
}

int main(int argc, char const *argv[])
{
	string str = "abc";
	allPossibleSubSequence(str);
	return 0;
}

/*
	This is a all possible subsequence geration algorithm

	Time complexity - (2^n * l)
	where, n is the length of string
	       l is length of binary string

*/