#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

unordered_map<string, int> subTopValue;

void generateAllSubString(string name) {
	for (int i = 0; name[i]; i++) {
		string subStr;
		for (int j = i; name[j]; j++) {
			subStr += name[j];

		}
	}
}

int main(int argc, char const *argv[])
{
	
	return 0;
}