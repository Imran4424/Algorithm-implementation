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

	// returns the index of the match
	if (hashMainString = hashPattern) {
		return 0;
		//We should've checked the substrings character by character here as hash collision might happen
	}

	for (int i = patternSize; i < mainStringSize; i++) {
		// updating rolling hash
		hashMainString = (hashMainString - (power * mainString[i - patternSize]) % modulus) % modulus;
		hashMainString = (hashMainString + modulus) % modulus; // take care of patternSize of negative value
		hashMainString = (hashMainString * base) % modulus;
		hashMainString = (hashMainString + mainString[i]) % modulus;
	}
}

int main(int argc, char const *argv[])
{
	
	return 0;
}