#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void findSubString(string mainString, string pattern) {
	int n = size();
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

int main(int argc, char const *argv[])
{
	string mainString = "ababaaabaaaaabacdeasdfabasfewaaifxsadadsad";
	string pattern = "ada";
	string replace = "xyz";

	return 0;
}