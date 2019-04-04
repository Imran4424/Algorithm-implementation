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
		int position = LinearSearch(numbers, target);

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