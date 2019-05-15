#include <iostream>
#include <vector>
using namespace std;


vector <int> Merge(vector <int> left, vector <int> right, vector <int> ar)
{
	ar.clear();

	int i = 0, j = 0;
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

	return Merge(left, right, ar);
}


int main(int argc, char const *argv[])
{
	
	return 0;
}