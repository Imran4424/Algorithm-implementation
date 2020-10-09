
#include <stdio.h>
#include <iostream>
using namespace std;

struct node
{
	bool endMark;
	node* next[26];
	node() {
		endMark = false;
		for (int i = 0; i < 26; i++) {
			next[i] = NULL;
		}
	}
};

node* root = new node();

void insert(char word[]) {
	node* travel = root;

	for(int i = 0; word[i]; i++) {
		int id = word[i] - 'a';

		if (travel -> next[id] == NULL) {
			travel -> next[id] = new node();
		}

		travel = travel -> next[id];
	}

	travel -> endMark = true;
}


int main(int argc, char const *argv[])
{
	
	return 0;
}