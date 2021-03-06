#include <iostream>
#include <vector>
using namespace std;


vector< vector<int> > SearchingPath(vector< vector<int> > maze, vector< vector <int> > path, int row, int col)
{
	if(row == maze.size()-1 && col == maze[row].size()-1)
	{
		path[row][col] = 1;
		
		return path;
	}

	if(row == maze.size()-1)
	{
		return SearchingPath(maze, path, row, col);
	}

	if (col == maze[row].size()-1)
	{
		return SearchingPath(maze, path, row, col);
	}

	path[row][col] = 1;

	if(maze[row+1][col] == 1)
	{
		return SearchingPath(maze, path, row+1, col);
	}

	if(maze[row][col+1] == 1)
	{
		return SearchingPath(maze, path, row, col+1);
	}

	//return SearchingPath(maze, path, row, col);

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

	path = SearchingPath(maze, path, 0, 0);

	for (int i = 0; i < path.size(); ++i)
	{
		for(int j = 0 ; j < path[i].size(); ++j)
		{
			cout << path[i][j] << " ";
		}

		cout << endl;
	}

	return 0;
}

/*
	not working
*/