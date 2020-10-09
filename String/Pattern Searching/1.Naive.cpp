
#include <stdint.h>
#include <iostream>
using namespace std;

char mainString[50005];

bool findSubString(char pattern[]) {

}

void findSubStringAllPositions(char pattern[]) {

}

void replaceAllSubString(char pattern[], char replace[]) {
	
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