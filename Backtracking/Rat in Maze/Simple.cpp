#include <iostream>
#include <vector>
using namespace std;


void SearchingPath(vector< vector<int> > maze, vector< vector <int> > path, int row, int col)
{
	if(row == maze.size() && col == maze[row].size())
	{
		return;
	}

	path[row][col] = 1;

	if(maze[row+1][col] == 1)
	{
		SearchingPath(maze, path, row+1, col);
	}

	if(maze[row][col+1])
	{
		SearchingPath(maze, path, row, col+1);
	}

}


int main(int argc, char const *argv[])
{
	cout << "enter the maze size in row and column" << endl;

	int row, col;
	cin >> row >> col;

	vector< vector <int> > maze(row, vector <int> (col));

	vector< vector <int> > path(row, vector <int> (col, 0)); //initializing path matrix with zero

	for (int i = 0; i < maze.size(); ++i)
	{
		for(int j = 0 ; j < maze[i].size(); ++j)
		{
			cin >> maze[i][j];
		}
	}



	return 0;
}

