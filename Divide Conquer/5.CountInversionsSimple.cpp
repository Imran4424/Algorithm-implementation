#include <iostream>
#include <vector>
#include <time.h>
using namespace std;

int CountInversions(vector <int> arr)
{
	int inversionCount = 0;

	for (int i = 0; i < arr.size() - 1; ++i)
	{
		for (int j = i+1; j < arr.size(); ++j)
		{
			if (arr[i] > arr[j])
			{
				inversionCount++;
			}
		}
	}

	return inversionCount;
}

int main(int argc, char const *argv[])
{
	cout << "enter the array size" << endl;

	int n;
	cin >> n;

	vector <int> arr(n);

	srand(time(0)); // for managing session

	for (int i = 0; i < n; ++i)
	{
		arr[i] = rand() % 20 + 1;

		cin >> arr[i];

		cout << arr[i] << " ";
	}

	cout << endl;

	int result = CountInversions(arr);

	cout << "Number of inversions are: " << result << endl;

	return 0;
}