#include <iostream>
#include <string>
#include <vector>
using namespace std;

void allPossibleSubSequence(string word, string subStr) {
	if (word.empty()) {
		cout << subStr << endl;
		return;
	}

	// substring is passed without adding first character of word
	allPossibleSubSequence(word.substr(1), subStr);

	
	// substring is passed with adding first character of word
	allPossibleSubSequence(word.substr(1), subStr + word[0]);
}

int main(int argc, char const *argv[])
{
	string str = "abc";
	allPossibleSubSequence(str, "");

	return 0;
}

/*
	This is a all possible subsequence geration algorithm

	Time complexity - (2^n)
	where, n is the length of string

*/