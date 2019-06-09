#include <iostream>
#include <vector>
using namespace std;


vector <int> Merge(vector <int> left, vector <int> right)
{
	vector <int> sorted;

	int i = 0, j = 0;

	while(i < left.size() && j < right.size())
	{
		if (left[i] <= right[j])
		{
			sorted.push_back(left[i]);

			i++;
		}
		else
		{
			sorted.push_back(right[j]);

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
	cout << "enter the array size" << endl;

	int size;
	cin >> size;

	vector <int> ar;

	cout << "enter the array you want to be sorted" << endl;

	int input;

	for(int i=0; i < size; i++)
	{
		cin >> input;

		ar.push_back(input);
	}

	ar = MergeSort(ar);

	for (int i = 0; i < ar.size(); ++i)
	{
		cout << ar[i] << " ";
	}

	cout << endl;

	return 0;
}