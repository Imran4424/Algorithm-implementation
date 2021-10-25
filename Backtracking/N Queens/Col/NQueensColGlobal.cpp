#include <iostream>
using namespace std;

int board[32][32];

bool IsSafe(int num, int row, int col)
{
	int i,j;

	// checking the row

	for(j=0; j<col; j++)
	{
		if(board[row][j])
		{
			return false;
		}
	}

	// checking upper left diagonal

	for(i = row-1, j = col-1; i>=0 && j>=0; i--, j--)
	{
		if (board[i][j])
		{
			return false;
		}
	}

	// checking the lower left diagonal

	for(i = row+1, j=col-1; i < num && j >= 0; i++, j--)
	{
		if(board[i][j])
		{
			return false;
		}
	}

	return true;
}


bool Solve(int num, int col)
{
	if (col == num)
	{
		return true;
	}

	for(int i=0; i<num; i++)
	{
		if (IsSafe(num, i, col))
		{
			board[i][col] = 1;

			if (Solve(num, col+1))
			{
				return true;
			}

			board[i][col] = 0; // backtracking
		}
	}


	//If the queen cannot be placed in any row in this colum col 
	return false;
}


int main(int argc, char const *argv[])
{
	cout << "How many queens you want to place" << endl;

	int num;
	cin >> num;

	

	for(int i = 0; i<num; i++)
	{
		for(int j=0; j<num; j++)
		{
			board[i][j] = 0;
		}
	}

	if (Solve(num, 0) == 0)
	{
		cout << "Solution doesn't exist" << endl;
	}
	else
	{
		
		for(int i = 0; i<num; i++)
		{
			for(int j=0; j<num; j++)
			{
				cout << board[i][j] << " ";
			}

			cout << endl;
		}
	}
	

	return 0;
}