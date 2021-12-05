#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

struct TrieNode
{
	vector <string> list;
	TrieNode *next[26];
};

TrieNode* trieRoot;

TrieNode* getNode() {
	TrieNode* temp = new TrieNode();
	
	for (int i = 0; i < 26; i++) {
		temp->next[i] = NULL;
	}

	return temp;
}

void trieInsert(string subStr, string name) {
	TrieNode* travel = trieRoot;

	for (int i = 0; subStr[i]; i++) {
		int letter = subStr[i] - 'a';

		if(NULL == travel->next[letter]) {
			travel->next[letter] = getNode();
		}

		travel = travel->next[letter];
	}

	travel->list.push_back(name);
}

vector<string> trieSearch(string subStr) {
	TrieNode* travel = trieRoot;

	for (int i = 0; subStr[i]; i++) {
		int letter = subStr[i] - 'a';

		if (NULL == travel->next[letter]) {
			return vector<string>();
		}

		travel = travel->next[letter];
	}

	return travel->list;
}

void generateAllSubString(string name) {
	for (int i = 0; name[i]; i++) {
		string subStr;

		for (int j = i; name[j]; j++) {
			subStr += name[j];

			trieInsert(subStr, name);
		}
	}
}

// find all string that include the given substring
void finAllString(string subStr) {
	vector<string> nameList = trieSearch(subStr);

	for(auto name: nameList) {
		cout << name << endl;
	}
}

int main(int argc, char const *argv[])
{
	trieRoot = new TrieNode();

	generateAllSubString("imran");
	generateAllSubString("shoudha");


	finAllString("i");
	finAllString("a");

	return 0;
}