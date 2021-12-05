#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace ::std;

unordered_map<string, vector<string> > subList; 

void generateAllSubString(string name) {
	for (int i = 0; name[i]; i++) {
		string subStr;
		for (int j = i; name[j]; j++) {
			subStr += name[j];

			subList[subStr].push_back(name);
		}
	}
}

// find all string that include the given substring
void finAllString(string subStr) {
	for(auto name: subList[subStr]) {
		cout << name << endl;
	}
}

int main(int argc, char const *argv[])
{
	generateAllSubString("imran");
	generateAllSubString("shoudha");


	finAllString("i");
	finAllString("a");

	return 0;
}