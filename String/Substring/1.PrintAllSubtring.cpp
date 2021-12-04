#include <iostream>
using namespace std;

void printSubstrings(string str) {
	// first loop for starting index
	for (int i = 0; i < str.size(); i++) {
		string subStr;
		// second loop is for generating substring
		for (int j = i; j < str.size(); j++) {
			subStr += str[j];
			// got all substring here
			cout << subStr << endl;
		}
	}
}


int main(int argc, char const *argv[])
{
	string str = "imran";
	printSubstrings(str);

	return 0;
}

/*
	This is a program for printing all substring for a string using two nested loop


	Time Complexity - O(N^2)
	Space Complexity - O(1)
*/