#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool found = false;
bool secondRoute;

vector<int> SubSetSolve(vector <int> input, vector <int> arSet, int index, int sum, int target)
{
	sum = sum + input[index];

	arSet.push_back(input[index]);

	if(sum == target)
	{
		found = true;

		return arSet;
	}

	while(sum > target)
	{
		sum = sum - arSet[0];

		arSet.erase(arSet.begin());
	}

	if(index < input.size()-1)
	{
		return SubSetSolve(input, arSet, index+1, sum, target);
	}
	else if(!secondRoute)
	{
		secondRoute = true;

		return SubSetSolve(input, arSet, 0, sum, target);		
	}

	return arSet;
}



vector<int> SubSetSum(vector<int> input, int target)
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
			arSet = SubSetSolve(input, arSet, k, 0, target);		
		}

	}


	return arSet;
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

	vector<int> arSet = SubSetSum(input, target);

	if(found)
	{
		for (int i = 0; i < arSet.size(); ++i)
		{
			cout << arSet[i] << " ";
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
*/