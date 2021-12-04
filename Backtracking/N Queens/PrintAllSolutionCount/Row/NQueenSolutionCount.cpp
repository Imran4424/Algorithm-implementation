#include <iostream>
using namespace std;

int **board;
int totalSolutions;

bool isSafe(int num, int row, int col) {
	int i , j;

	// checking the column
	for (int i = 0; i < row; i++) {
		if(board[i][col]) {
			return false;
		}
	}

	// check upper diagonal on the left side
	for (i = row, j = col; i >=0 && j >= 0; i--, j--) {
		if(board[i][j]) {
			return false;
		}
	}

	// check upper diagonal on the right side
	for (i = row, j = col; i >= 0 && j < num; i--, j++) {
		if(board[i][j]) {
			return false;
		}
	}

	return true;
}

bool solve(int num, int row) {
	if (num == row) {
		totalSolutions++;
		return true;
	}

	bool status = false;

	for (int j = 0; j < num; j++) {
		if(isSafe(num, row, j)) {
			board[row][j] = 1;

			if(solve(num, row + 1)) {
				status = true;
			}

			board[row][j] = 0;
		}
	}

	return status;
}

int main(int argc, char const *argv[])
{
	
	cout << "How many queens you want to place" << endl;

	int num;
	cin >> num;

	board = new int*[num];

	for (int i = 0; i < num; i++) {
		board[i] = new int[num];
	}

	
	for (int k = 1; k <= num; k++) {
		// clearing
		totalSolutions = 0;

		for(int i = 0; i < k; i++)
		{
			for(int j = 0; j < k; j++)
			{
				board[i][j] = 0;
			}
		}


		solve(k, 0);

		cout << k << ". There are " << totalSolutions << " solutions to the " << k << " queens problem" << endl;
	}

	
	return 0;
}