#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void findSubString(string mainString, string pattern) {
	int n = mainString.size();
	int m = pattern.size();
	
	auto foundPos = mainString.find(pattern);

	if (string::npos != foundPos) {
		cout << "Sub String not found" << endl;
	} else {
		cout << "found substring at position " << foundPos << endl;
	}
}

void findAllSubStringPositions(string mainString, string pattern) {
	int n = mainString.size();
	int m = pattern.size();

	auto foundPos = mainString.find(pattern);

	while(foundPos != string::npos) {
		cout << foundPos << endl;

		foundPos = mainString.find(pattern, foundPos + 1);
	}
}

string replaceAllSubString(string mainString, string pattern, string replace) {
	int n = mainString.size();
	int m = pattern.size();

	auto foundPos = mainString.find(pattern);

	while(foundPos != string::npos) {
		for (int k = 0; replace[k]; k++) {
			mainString[foundPos + k] = replace[k];
		}

		foundPos = mainString.find(pattern, foundPos + 1);
	}

	return mainString;
}

int main(int argc, char const *argv[])
{
	string mainString = "ababaaabaaaaabacdeasdfabasfewaaifxsadadsad";
	string pattern = "aba";
	string replace = "xyz";

	findSubString(mainString, pattern);

	findAllSubStringPositions(mainString, pattern);

	cout << replaceAllSubString(mainString, pattern, replace) << endl;

	return 0;
}


/*
	Time complexity: O(mn) - in average case
			 O(n^2) - in worst case

*/