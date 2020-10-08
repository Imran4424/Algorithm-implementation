#include <stdio.h>
#include <iostream>
using namespace std;


// Max number of states in the matching machine.
// Should be equal to the sum of the length of all keywords.
const int MAXS = 500;

// Maximum number of characters in input alphabet
const int MAXC = 26;

// FAILURE FUNCTION IS IMPLEMENTED USING failure[]
int failure[MAXS];

// GOTO FUNCTION (OR TRIE) IS IMPLEMENTED USING trie[][]
int trie[MAXS][MAXC];
