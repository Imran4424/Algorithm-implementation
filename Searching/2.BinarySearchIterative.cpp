#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <time.h>
using namespace std;

int BinarySearch(vector<int> ar, int target, int start, int stop)
{
	if (start <= stop)
	{
		int mid = (start + stop) / 2;
	}
	
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
	}

	cout << "enter your target" << endl;

	int target;
	cin >> target;

	int position = LinearSearch(numbers, target, 0, numbers.size()-1);

	if (position == -1)
	{
		cout << "target does not exist in the array" << endl;
	}
	else
	{
		cout << "found in position: " << position << endl;
	}

	return 0;
}