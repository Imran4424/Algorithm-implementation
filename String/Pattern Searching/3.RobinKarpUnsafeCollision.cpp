/*
	This robin karp code adapted from shafayet vai
*/

#include <stdio.h>
#include <iostream>
using namespace std;

typedef long long int lli;

char mainString[50005];

int stringLength(char text[]) {
	int len = 0;
	for (int i = 0; text[i]; i++) {
		len++;
	}

	return len;
}

lli getHash()

int findMatch(char pattern[]) {
	int mainStringSize = stringLength(mainString);
	int patternSize = stringLength(pattern);

	if (mainStringSize < patternSize) {
		return -1;
	}

	if (0 == mainStringSize || 0 == patternSize) {
		return -1;
	}
}

int main(int argc, char const *argv[])
{
	
	return 0;
}