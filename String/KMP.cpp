#include <iostream>
#include <stdio.h>
using namespace std;


char mainString[50005];
int piArray[5];

void kmpPreProcess(char pattern[]) {
	piArray[0] = 0;
	int j = 0;

	for (int i = 1; pattern[i]; i++) {
		if (pattern[i] == pattern[j]) {
			piArray[i] = ++j;
		} else {
			// initiating
			piArray[i] = 0;

			while (j > 0){
				j = piArray[j - 1];
				if (pattern[i] == pattern[j]) {
					// changed if found prefix match
					piArray[i] = ++j;
					break;
				}
			}
		}
	}
}

bool kmp(char pattern[]) {
	int j = 0;
	for(int i = 0; mainString[i]; i++) {
		if (mainString[i] == pattern[j]) {
			if(!pattern[j + 1]) {
				return true;
			}
			j++;
		} else {
			while(j > 0) {
				j = piArray[j - 1];
				if (mainString[i] == pattern[j]) {
					j++;
					break;
				}
			}
		}
	}

	return false;	
}

void kmpAllPositions(char pattern[]) {
	int j = 0;
	int beginIndex;
	for(int i = 0; mainString[i]; i++) {
		if (mainString[i] == pattern[j]) {
			if (0 == j) {
				beginIndex = i;
			} else if(!pattern[j + 1]) {
				printf("%d ", beginIndex);
				// for clearing
				j = 0;
			}
			j++;
		} else {
			while(j > 0) {
				j = piArray[j - 1];
				if (mainString[i] == pattern[j]) {
					j++;
					break;
				}
			}
		}
	}
}

void kmpReplaceSubstring(char pattern[], char replace[]) {
	int beginIndex;
	int j = 0;
	for(int i = 0; mainString[i]; i++) {
		if (mainString[i] == pattern[j]) {
			if (0 == j) {
				beginIndex = i;
			} else if(!pattern[j + 1]) {
				int x, y;
				for (x = beginIndex, y = 0; replace[y]; x++, y++) {
					mainString[x] = replace[y];
				}
				// for clearing
				j = 0;
			}
			j++;
		} else {
			while(j > 0) {
				j = piArray[j - 1];
				if (mainString[i] == pattern[j]) {
					j++;
					break;
				}
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	freopen("input.txt", "r", stdin);

	char pattern[5];
	char replace[5];

	// scanf("%[^\n]", mainString);
	// getchar();
	// scanf("%[^\n]", pattern);

	scanf("%s %s %s", mainString, pattern, replace);

	printf("%s\n", mainString);
	printf("%s\n", pattern);

	kmpPreProcess(pattern);

	if(kmp(pattern)) {
		printf("subString found\n");
	} else {
		printf("subString not found\n");
	}

	printf("subString positions: ");
	kmpAllPositions(pattern);
	printf("\n\n");

	kmpReplaceSubstring(pattern, replace);
	printf("%s\n", mainString);

	return 0;
}