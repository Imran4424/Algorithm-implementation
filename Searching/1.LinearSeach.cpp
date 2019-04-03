#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
using namespace std;

int LinearSearch(vector<int> ar, int target)
{
	for (int i = 0; i < ar.size(); ++i)
	{
		if (target == ar[i])
		{
			return i+1;
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

	for (int i = 0; i < numbers.size(); ++i)
	{
		int temp = rand() % 100;

		temp = (temp + i - 50);

		if (temp < 0)
		{
			temp = -temp;
		}

		numbers[i] = temp;
	}

	cout << "enter your target" << endl;

	int target;
	cin >> target;

	int position = LinearSearch(numbers, target);

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