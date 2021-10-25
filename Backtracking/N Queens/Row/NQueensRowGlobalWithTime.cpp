#include <iostream>
#include <ctime>
using namespace std;


int board[1002][1002];
const int boardSize = 1002;


bool IsSafe(int num, int row, int col)
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

        for(i = row, j = col; i >= 0 && j >= 0; i--, j--)
        {
                if (board[i][j])
                {
                        return false;
                }
        }

        // check upper diagonal on the right side

        for(i = row,j = col; i >= 0 && j < num; i--, j++)
        {
                if (board[i][j])
                {
                        return false;
                }
        }

        return true;
}


bool Solve(int num, int row)
{
        if(row == num) // base condition
        {
                return true;
        }

        for(int j = 0; j < num; j++)
        {
                if (IsSafe(num, row, j))
                {
                        board[row][j] = 1;

                        if (Solve(num, row + 1))
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
        // for tracking of the time spent in computing
        clock_t startTime, endTime;
        // strat time tracking
        startTime = clock();


        cout << "How many queens you want to place" << endl;
        int num;
        cin >> num;

        for(int i = 0; i < boardSize; i++)
        {
                for(int j = 0; j < boardSize; j++)
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
                int position = 0;

                for(int i = 0; i < num; i++)
                {
                        for(int j = 0; j < num; j++)
                        {
                                position++;

                                if (board[i][j]) {
                                        cout << position << " ";
                                }
                        }
                }

                cout << endl;
        }
        
        // end time tracking
        endTime = clock();

        cout << "\nTotal Execution Time: \t"  << 1000*((double)(endTime-startTime)/CLOCKS_PER_SEC) << " milliseconds." << "\n\n";

        return 0;
}
