#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

unordered_map<string, int> subTopValue;
unordered_map<string, int> restaurantScore;

void generateAllSubString(string name) {
	for (int i = 0; name[i]; i++) {
		string subStr;
		for (int j = i; name[j]; j++) {
			subStr += name[j];

		}
	}
}

void addRestaurant(string name) {

}

void addValue(string name, int value) {

}

int getValue(string str) {

}

int main(int argc, char const *argv[])
{
	
	return 0;
}

/*
	In this code,
	We will calculate subString top value during addValue
*/