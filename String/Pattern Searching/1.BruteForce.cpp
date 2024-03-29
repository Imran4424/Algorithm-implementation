#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void findSubString(string mainString, string pattern) {
	int n = mainString.size();
	int m = pattern.size();
	int foundPos = -1;

	for (int i = 0; i + m <= n; i++) {
		if (mainString.substr(i, m) == pattern) {
			foundPos = i;
			break;
		}
	}

	if (-1 == foundPos) {
		cout << "Sub String not found" << endl;
	} else {
		cout << "found substring at position " << foundPos << endl;
	}
}

void findAllSubStringPositions(string mainString, string pattern) {
	int n = mainString.size();
	int m = pattern.size();

	for (int i = 0; i + m <= n; i++) {
		if (mainString.substr(i, m) == pattern) {
			cout << i << endl;
		}
	}
}

string replaceAllSubString(string mainString, string pattern, string replace) {
	int n = mainString.size();
	int m = pattern.size();

	for (int i = 0; i + m <= n; i++) {
		if (mainString.substr(i, m) == pattern) {
			for (int k = 0; replace[k]; k++) {
				mainString[i + k] = replace[k];
			}
		}
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