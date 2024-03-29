#include <iostream>
using namespace std;


bool IsSafe(int num, int row, int col, int board[num][num])
{
	int i,j;

	// checking the column

	for(i = 0; i < row; i++)
	{
		if (board[i][col])
		{
			return false;
		}
	}

	// check upper diagonal on the left side

	for(i = row-1,j = col-1; i>=0 && j>=0; i--, j--)
	{
		if (board[i][j])
		{
			return false;
		}
	}

	// check upper diagonal on the right side

	for(i = row-1,j = col+1; i >= 0 && j < num; i--, j++)
	{
		if (board[i][j])
		{
			return false;
		}
	}


	return true;
}


bool Solve(int num, int row, int board[num][num])
{
	if(row == num) // base condition
	{
		return true;
	}

	for(int j = 0; j < num; j++)
	{
		if (IsSafe(num, row, j, board))
		{
			board[row][j] = 1;

			if (Solve(num, row+1, board))
			{
				return true;
			}

			
			board[row][j] = 0; // backtracking
		}
	}


	return false; // when queen can't be placed in this row
}


int main(int argc, char const *argv[])
{
	cout << "How many queens you want to place" << endl;

	int num;
	cin >> num;

	int board[num][num];

	for(int i = 0; i<num; i++)
	{
		for(int j=0; j<num; j++)
		{
			board[i][j] = 0;
		}
	}

	if (Solve(num, 0, board) == 0)
	{
		cout << "Solution doesn't exist" << endl;
	}
	else
	{
		
		for(int i = 0; i<num; i++)
		{
			for(int j=0; j<num; j++)
			{
				cout << board[i][j] << " " ;
			}

			cout << endl;
		}
	}
	

	return 0;
}