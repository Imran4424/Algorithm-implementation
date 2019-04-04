#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <time.h>
using namespace std;

bool isSorted = false;

int BinarySearch(vector<int> ar, int target, int start, int stop)
{
	if (!isSorted)
	{
		sort(ar.begin(), ar.end());

		isSorted = true;
	}

	// if (start == stop && ar[start] != target)
	// {
	// 	return -1;
	// }


	if(start <= stop)
	{
		int mid = (start + stop - 1) / 2;

		if (ar[mid] == target)
		{
			return mid + 1;
		}
		else if (ar[mid] > target)
		{
			return BinarySearch(ar, target, start, mid-1);
		}
		else if (ar[mid] < target)
		{
			return BinarySearch(ar, target, mid+1, stop);
		}
		
	}

	return -1;

}


int main(int argc, char const *argv[])
{
	cout << "enter the size of the array" << endl;

	int n;
	cin >> n;

	vector <int> numbers(n);

	srand(time(0)); // for managing session

	for (int i = 0; i < numbers.size(); ++i)
	{
		int temp = rand() % 100;

		

		numbers[i] = temp + 1;

		cout << numbers[i] << " ";
	}

	cout << endl << endl;

	cout << "enter your target" << endl;

	int target;

	while(cin >> target)
	{
		int position = BinarySearch(numbers, target, 0, numbers.size()-1);

		if (position == -1)
		{
			cout << "target does not exist in the array" << endl << endl;
		}
		else
		{
			cout << "found in position: " << position << endl << endl	;
		}
		
		cout << "enter your target" << endl;
	}


	return 0;
}