#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool found = false;
bool secondRoute;

vector <int> solve;

void SubSetSolve(vector <int> input, vector <int> arSet, int index, int sum, int target)
{
	sum = sum + input[index];

	arSet.push_back(input[index]);

	if(sum == target) // base
	{
		found = true;

		solve = arSet;
	}

	while(sum > target)
	{
		sum = sum - arSet[0];

		arSet.erase(arSet.begin());
	}

	if(sum == target) // base
	{
		found = true;

		solve = arSet;
	}

	if(index < input.size()-1)
	{
		SubSetSolve(input, arSet, index+1, sum, target);
	}
	else if(!secondRoute)
	{
		secondRoute = true;

		SubSetSolve(input, arSet, 0, sum, target);		
	}
	
	// return arSet;
}



void SubSetSum(vector<int> input, int target)
{
	sort(input.begin(), input.end());

	int i=0;

	while(input[i] <= target)
	{
		i++;
	}

	input.resize(i);

	vector <int> arSet;


	for(int k=0; k < input.size(); k++)
	{
		secondRoute = false;

		if(found)
		{
			break;
		}
		else
		{
			SubSetSolve(input, arSet, k, 0, target);		
		}

	}


	// return arSet;
}

int main(int argc, char const *argv[])
{
	vector <int> input;

	cout << "eter the size and target" << endl;

	int size, target;
	cin >> size >> target;

	cout << "enter the array" << endl;

	for(int i=0; i< size; ++i)
	{
		int temp;
		cin >> temp;

		input.push_back(temp);
	}

	SubSetSum(input, target);

	if(found)
	{
		for (int i = 0; i < solve.size(); ++i)
		{
			cout << solve[i] << " ";
		}

		cout << endl;
	}
	else
	{
		cout << "Solution doesn't exist" << endl;
	}

	return 0;
}


/*

	Own implemented backtrack algorithm

	first sorted the array

	then delete the elements which is larger than the elements

	then start a recursion with every existing element in search of target

	if the array ends in some cases (think about the case we start the function with last index)
	then retraverse the whole array until it find the subset	

	for example :

	3 34 4 12 5 2

	sorted: 2 3 4 5 12 34

	new array: 2 3 4 5

	now the recusive call will be like for target 9
	
	2
	2+3+4

	3
	3+4
	3+4+5
	4+5

	4
	4+5

	5
	5+2
	5+2+3
	2+3
	2+3+4

*/