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
			if(2 == j) {
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
	for(int i = 0; mainString[i]; i++) {
		if (mainString[i] == pattern[j]) {
			printf("%d - %d ", i, j);
			
			if(2 == j) {
				//printf("%d ", i - j);
				// for clearing
				j = 0;
			} else {
				j++;
			}
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
	int j = 0;
	for(int i = 0; mainString[i]; i++) {
		if (mainString[i] == pattern[j]) {
			if(2 == j) {
				int x, y;
				for (x = i - j, y = 0; replace[y]; x++, y++) {
					mainString[x] = replace[y];
				}
				// for clearing
				j = 0;
			} else {
				j++;
			}
			
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
	freopen("output.txt", "w", stdout);

	char pattern[5];
	char replace[5];

	// scanf("%[^\n]", mainString);
	// getchar();
	// scanf("%[^\n]", pattern);

	scanf("%s", mainString);

	printf("given String - %s\n\n", mainString);

	while(cin >> pattern >> replace) {
		printf("%s %s\n", pattern, replace);
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
	}

	return 0;
}