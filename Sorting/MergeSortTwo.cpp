#include <iostream>
#include <vector>
using namespace std;


vector <int> Merge(vector <int> left, vector <int> right)
{
	vector <int> sorted;

	int i = 0, j = 0;

	while(i < left.size() && j < right.size())
	{
		if (left[i] <= right)
		{
			sorted.push_back(left[i]);

			i++;
		}
		else
		{
			sorted.push_back(right[i]);

			j++;
		}
	}

	while(i < left.size())
	{
		sorted.push_back(left[i]);
		i++;
	}

	while(j < right.size())
	{
		sorted.push_back(right[j]);

		j++;
	}

	return sorted;
}

vector <int> MergeSort(vector <int> ar)
{
	if(ar.size() < 2)
	{
		return ar;
	}

	int mid = ar.size() / 2;

	vector <int> left, right;

	for (int i = 0; i < mid; ++i)
	{
		left.push_back(ar[i]);
	}

	for (int i = mid; i < ar.size(); ++i)
	{
		right.push_back(ar[i]);
	}

	left  = MergeSort(left);

	right = MergeSort(right);

	return Merge(left, right);
}


int main(int argc, char const *argv[])
{
	
	return 0;
}