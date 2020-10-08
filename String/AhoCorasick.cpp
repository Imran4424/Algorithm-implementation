
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


int main(int argc, char const *argv[])
{
	
	return 0;
}