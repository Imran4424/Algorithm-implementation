#include <iostream>
using namespace ::std;

int topFive[5];
int topThree[3];

void displayTopFive() {
	for (int i = 0; i < 5; i++) {
		cout << topFive[i] << " ";
	}
	cout << endl;
}

void displayTopThree() {
	for (int i = 0; i < 3; i++) {
		cout << topThree[i] << " ";
	}
	cout << endl;
}

void insertionSortTopFive(int currentValue) {
	int index = 4;
	int findPos = -1;

	while(index >= 0 && currentValue > topFive[index]) {
		findPos = index;
		index--;
	}

	if(-1 != findPos) {
		for (int i = 4; i > findPos; i--) {
			topFive[i] = topFive[i - 1];
		}

		topFive[findPos] = currentValue;
	}
}

void insertionSortTopThree(int currentValue) {
	int index = 2;
	int findPos = -1;

	while(index >= 0 && currentValue > topThree[index]) {
		findPos = index;
		index--;
	}

	if (-1 != findPos) {
		for (int i = 2; i > findPos; i--) {
			topThree[i] = topThree[i - 1];
		}

		topThree[findPos] = currentValue;
	}
}

void init() {
	for (int i = 0 ; i < 3; i++) {
		topThree[i] = topFive[i] = 0;
	}

	topFive[3] = topFive[4] = 0;
}

int main(int argc, char const *argv[])
{
	init();

	cout << "enter your array size" << endl;
	int size;
	cin >> size;

	int currentValue;
	while(size--) {
		cin >> currentValue;
		insertionSortTopFive(currentValue);
		insertionSortTopThree(currentValue);
	}


	displayTopThree();
	displayTopFive();
	
	return 0;
}