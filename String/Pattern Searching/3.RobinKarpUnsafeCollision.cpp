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

lli getHash(char text[], lli textSize, lli base, lli modulus) {
	lli hash = 0, power = 1;
	for (int i = textSize - 1; i >= 0; i--) {
		hash = hash + (text[i] * power) % modulus;
		hash = hash % modulus;

		power = (power * base) % modulus;
	}

	return hash;
}

int findMatch(char pattern[]) {
	int mainStringSize = stringLength(mainString);
	int patternSize = stringLength(pattern);

	if (mainStringSize < patternSize) {
		return -1;
	}

	if (0 == mainStringSize || 0 == patternSize) {
		return -1;
	}

	lli base = 347, modulus = 1000000000 + 7;

	// calculate B^patternSize-1
	lli power = 1;
	for (int i = 1; i < patternSize; i++) {
		power = (power * base) % modulus;
	}

	// hash value of pattern
	lli hashPattern = getHash(pattern, patternSize, base, modulus);
	// hash value of mainString
	lli hashMainString = getHash(mainString, mainStringSize, base, modulus);
}

int main(int argc, char const *argv[])
{
	
	return 0;
}