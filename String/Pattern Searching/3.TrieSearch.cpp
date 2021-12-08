#include <iostream>
#include <string>
using namespace std;

class Trie
{
	struct node
	{
		node *next[26];

		node() {
			for (int i = 0; i < 26; i++) {
				next[i] = NULL;
			}
		}	
	};

	node *root;

public:
	Trie() {
		root = new node();
	}

	void insert(string name) {
		node* travel = root;

		for(int i = 0; name[i]; i++) {
			int letter = name[i] - 'a';

			if (NULL == travel->next[letter]) {
				travel->next[letter] = new node();
			}

			travel = travel->next[letter];
		}
	}

	bool search(string name) {
		node* travel = root;

		for (int i = 0; name[i]; i++) {
			int letter = name[i] - 'a';

			if (NULL == travel->next[letter]) {
				return false;
			}

			travel = travel->next[letter];
		}

		return true;
	}

	void reset() {
		root = new node();
	}
};

int main(int argc, char const *argv[])
{
	string mainString = "ababaaabaaaaabacdeasdfabasfewaaifxsadadsad";
	string pattern = "aba";
	string replace = "xyz";

	Trie trie;
	trie.reset();

	for (int i = 0; mainString[i]; i++) {
		trie.insert(mainString.substr(i));
	}

	if (trie.search(pattern)) {
		cout << "pattern found" << endl;
	} else {
		cout << "pattern not found" << endl;
	}

	return 0;
}